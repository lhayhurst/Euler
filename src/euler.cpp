#include <UnitTest++.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
   The sum of these multiples is 23.

   Find the sum of all the multiples of 3 or 5 below 1000.
*/
TEST(ProblemOne)
  {

    auto sum = 0;
    for( auto i = 0; i < 999; i++ ) {
        if ( i % 3 == 0 || i % 5 == 0 ) {
            sum += i;
        }
    }
    CHECK_EQUAL( 232169, sum );

  }

/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms.
By starting with 1 and 2, the first 10 terms will be:

    1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million,
find the sum of the even-valued terms.
*/

void fibonacci( long int max, function<void(long int&)> action ) {
    long int f1 = 1;
    long int f2 = 2;
    while ( f2 <= max ) {
       action( f2 );
       int tmp = f2;
       f2 = f1 + tmp;
       f1 = tmp;
    }
}

TEST(ProblemTwo)
{
    long int sum = 0;

    auto accumulator = [&sum](long int elem) {
        if ( elem % 2 == 0) {
            sum += elem;
        }
    };
    fibonacci( 4000000, accumulator );
    CHECK_EQUAL( 4613732, sum );
    //std::cout << sum << std::endl;
}



vector<unsigned long> prime_factors( unsigned long N ) {
    unsigned long d = 2;
    vector<unsigned long> ret(0);
    while ( N > 1  ) {
        while ( N % d == 0 ) {
            ret.push_back( d );
            N /= d;
        }
        d++;
    }
    return ret;

}
/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

TEST(ProblemThree)
{
    unsigned long N = 600851475143;
    vector<unsigned long> factors = prime_factors( N );
    sort( factors.begin(), factors.end() );
    CHECK_EQUAL( 6857, factors.back() );
}

int main()
  {
    return UnitTest::RunAllTests();
  }
