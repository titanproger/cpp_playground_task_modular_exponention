
#include <iostream>

#include "PowerSimple.hpp"

using namespace std;
 
static_assert( PowerSimple(0L, 1, 0) == 0);
static_assert( PowerSimple(0L, 1, 1000) == 0);
static_assert( PowerSimple(1L, 1, 1) == 0);
static_assert( PowerSimple(1L, 1, 2) == 1);

static_assert( PowerSimple(123L, 1, 1000) == 123);
static_assert( PowerSimple(1000L, 1, 1000) == 0);


static_assert( PowerSimple(-1L, 1, 1000) == 999);
static_assert( PowerSimple(-1001L, 1, 1000) == 999);

static_assert( PowerSimple(131999920L, 234979, 991540365) == 682771105);
static_assert( PowerSimple(991540365L*2, 234979, 991540365) == 0);

static_assert( PowerSimple(8888L, 0, 1000) == 1);

// Driver code
int main()
{                           
    int64_t x;
    while(cin >> x)
    {
        int64_t y;
        int64_t mod;    
        cin >> y;
        cin >> mod;
        cout << PowerSimple(x, y, mod) << '\n';
    }
        
    return 0;
}
