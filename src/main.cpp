#include <iostream>
#include "math.h"

#include "FFT.hpp"

double F(double X) {
    return cos(3 * X) + sin(2 * X);
}

int main() {

    COSI::FFT<8> a;

    auto d = COSI::get_sample<8, F>();

    for(std::size_t i = 0; i < 8; ++i) {
        std::cout << d.second[i] << ", " << d.first[i] << '\n';
    }


    COSI::complex_vector c(8);

    for(std::size_t i = 0; i < 8; ++i) {
        c[i] = d.first[i];
    }

    auto result = a(c);

    std::cout << "\n\n\n\n\n";
    for(std::size_t i = 0; i < 8; ++i) {
        std::cout << d.second[i] << ", " << std::arg(result[i]) << "\n";
    }

    auto test = result;

    a.restore(test);

    std::cout << "\n\n\n\n\n";
    for(std::size_t i = 0; i < 8; ++i) {
        test[i] /= 8;
        std::cout << d.second[i] << ", " << test[i].real() << "\n";
    }
    return 0;
}