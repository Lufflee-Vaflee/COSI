#include <iostream>
#include "math.h"
#include <fstream>
#include <filesystem>

#include "FFT.hpp"

double F(double X) {
    return cos(3 * X) + sin(2 * X);
}

int main(int argc, char* argv[]) {
    COSI::FFT<128> a;

    std::string path;

    if(argc == 2) {
        path = argv[1];
    } else {
        path = "../draw/";
    }

    std::ofstream origin(path + "origin.csv", std::fstream::trunc);
    std::ofstream imag(path + "imag.csv", std::fstream::trunc);
    std::ofstream real(path + "real.csv", std::fstream::trunc);
    std::ofstream ABS(path + "ABS.csv", std::fstream::trunc);
    std::ofstream restore(path + "restore.csv", std::fstream::trunc);

    auto d = COSI::get_sample<128, F>();

    for(std::size_t i = 0; i < 128; ++i) {
        origin << d.second[i] << ", " <<  d.first[i] << '\n';
    }

    COSI::complex_vector c(128);

    for(std::size_t i = 0; i < 128; ++i) {
        c[i] = std::complex<double>(d.first[i], d.second[i]);
    }

    a(c);  //perform FFT

    for(std::size_t i = 0; i < 128; ++i) {
        imag << d.second[i] << ", " << c[i].imag() << "\n";
    }

    for(std::size_t i = 0; i < 128; ++i) {
        real << d.second[i] << ", " << c[i].real() << "\n";
    }

    for(std::size_t i = 0; i < 128; ++i) {
        ABS << d.second[i] << ", " << std::abs(c[i]) << "\n";
    }

    a.restore(c);

    for(std::size_t i = 0; i < 128; ++i) {
        c[i] /= 128;
        restore << d.second[i] << ", " << c[i].real() << "\n";
    }

    return 0;
}