#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}

// int main() {
//     Fixed a(3);
//     Fixed b(0);
//     Fixed c(1);
//     std::cout << "a= " << a << std::endl;
//     std::cout << "c= " << c << std::endl;
//     std::cout << "a + c= " << a + c << std::endl;
//     std::cout << "a - c= " << a - c << std::endl;
//     std::cout << "a * c= " << a * c << std::endl;
//     std::cout << "a * c= " << a * c << std::endl;
//     std::cout << "a / c= " << a / c << std::endl;

//     assert(a > b);
//     assert(b < c);
//     assert(a != b);
//     assert(c >= b);
//     assert(b <= a);
//     assert(c == 1);
//     return (0);
// }

// int main( void ) {
    // float c1 = 2.10f;
    // float e1 = 2.05f;
    // Fixed a;
    // Fixed c(c1);
    // Fixed e(e1);
    // const Fixed c(c1);
    // const Fixed e(e1);
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << "" << (c1 > e1) << std::endl;
    // std::cout << "" << (c > e) << std::endl;
    // std::cout << "" << (c1 < e1) << std::endl;
    // std::cout << "" << (c < e) << std::endl;
    // std::cout << "" << (c1 >= e1) << std::endl;
    // std::cout << "" << (c >= e) << std::endl;
    // std::cout << "" << (c1 <= e1) << std::endl;
    // std::cout << "" << (c <= e) << std::endl;
    // std::cout << "" << (c1 == e1) << std::endl;
    // std::cout << "" << (c == e) << std::endl;
    // std::cout << "" << (c1 + e1) << std::endl;
    // std::cout << "" << (c + e) << std::endl;
    // std::cout << "" << (c1 - e1) << std::endl;
    // std::cout << "" << (c - e) << std::endl;
    // std::cout << "" << (c1 * e1) << std::endl;
    // std::cout << "" << (c * e) << std::endl;
    // std::cout << "" << (c1 / e1) << std::endl;
    // std::cout << "" << (c / e) << std::endl;
    // std::cout << "min" << c.min(c, e) << std::endl;
    // std::cout << "max" << c.max(c, e) << std::endl;
    // return 0;
// }