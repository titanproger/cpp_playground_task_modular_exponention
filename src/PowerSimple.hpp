
const int TYPE_OPERAND_MAX_DIGITS = 9;

template <typename TOperand, typename TExponent, typename TModulus>
constexpr int PowerSimple(TOperand x, TExponent exponent, TModulus modulus)
{             
    static_assert(std::numeric_limits<TOperand>::digits10 >= TYPE_OPERAND_MAX_DIGITS*2 ); // we need double bitspace to make x*x operation

    if(modulus <= 0) // it nonsense
        return 0;
       
    TOperand result = 1;
    x = x % modulus;       
    if (x == 0) 
        return 0;

    if(x < 0) 
        x+=modulus;     
    
    while (exponent > 0) {        
        const bool is_last_bit_set =  exponent & 1;        
        if (is_last_bit_set)
            result = (result*x) % modulus;         
        exponent = exponent >> 1;
        x = (x*x) % modulus;
    }
    return result;
}
 
