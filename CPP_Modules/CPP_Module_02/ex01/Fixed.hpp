#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int m_fp_value;
        static const int m_num_of_bits = 8;
    public:
        Fixed();
        Fixed(const int& integer);
        Fixed(const float& float_num);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);
#endif