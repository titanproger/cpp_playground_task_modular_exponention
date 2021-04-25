#include "catch.hpp"

#include "PowerSimple.hpp"
#include <algorithm> 
#include <gmpxx.h>

TEST_CASE("Test module 0")
{
    static_assert( PowerSimple(0L, 1, 0) == 0);
    static_assert( PowerSimple(0L, 1, 1000) == 0);
    static_assert( PowerSimple(1L, 1, 1) == 0);
    static_assert( PowerSimple(1L, 1, 2) == 1);

    REQUIRE(PowerSimple(0L, 1, 0)  == 0);
    REQUIRE(PowerSimple(0L, 1, 1000)  == 0);
    REQUIRE(PowerSimple(0L, 1, 1)  == 0);
    REQUIRE(PowerSimple(0L, 1, 2)  == 0);    
}

struct TTestRecord {
    uint64_t  base;
    uint64_t  exponent;
    uint64_t  module;    

    TTestRecord(uint64_t _base, uint64_t _exp, uint64_t _module ) : base(_base), exponent(_exp), module(_module) {        
    }
};
#include <iostream>
TEST_CASE("Test with GMP")
{
    auto TEST_DATA = {
        TTestRecord(0,1,2),
        TTestRecord(2,3,4),        
        TTestRecord(3,0,10),        
        TTestRecord(3,1,10),        
        TTestRecord(923452234,234445,3456),        
        TTestRecord(923452234,234445,344563434),        
        TTestRecord(131999920L,234979,991540365),                
    };

    std::for_each( TEST_DATA.begin(), TEST_DATA.end(), [](const TTestRecord &record){         
        mpz_class result;
        mpz_class base = record.base;
        mpz_class exp = record.exponent;
        mpz_class mod = record.module;


        
        mpz_powm(result.get_mpz_t(), base.get_mpz_t(), exp.get_mpz_t(), mod.get_mpz_t());
        REQUIRE(result == PowerSimple(record.base, record.exponent,record.module) );
        std::cout << result;
    });
    
    
    
    //mpz_class a, b, c;

    //a = 1234;
    //b = "-5678";
    ///c = a+b;
    //mpz_powm(mpz_t rop, const mpz_t base, const mpz_t exp, const mpz_t mod)

}
