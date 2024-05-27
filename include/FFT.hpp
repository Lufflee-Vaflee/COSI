#pragma once

#include <vector>
#include <array>
#include "math.h"
#include <complex>
#include <tuple>

namespace COSI {

using Fx_signature = double (*)(double X);


using sample = std::pair<std::vector<double>, std::vector<double>>;

template<std::size_t N, Fx_signature F>
sample get_sample() {
    std::vector<double> y(N);
    std::vector<double> x(N);

    for(std::size_t i = 0; i < N; ++i) {
        double X = i * 2 * M_PI / N;
        x[i] = X;
        y[i] = F(X);
    }

    return {y, x};
}


using complex_vector = std::vector<std::complex<double>>;

template<std::size_t N>
class FFT {
public:

std::size_t get_transform_index(std::size_t index) {  // i stole this -_-
    long long int power = log2(N);

    long long int k = 1;
    std::size_t A = index;
    std::size_t result = 0;
    std::size_t s = 0;
    std::size_t A_right = A;
    std::size_t A_left = A;
    while (power - k >= 0)
    {
        A_right = (A >> (power - k)) & (std::size_t)(std::pow(2, power) - 1) & (std::size_t)std::pow(2, s);
        A_left  = (A << (power - k)) & (std::size_t)(std::pow(2, power) - 1) & (std::size_t)std::pow(2, power - 1 - s);
        result = result | A_left | A_right;
        s++;
        k += 2;
    }

    return result;
}


complex_vector transform(complex_vector const& origin) {
    complex_vector result(origin.size());

    std::complex<double> a;

    for(std::size_t i = 0; i < result.size(); ++i) {
        result[i] = origin[get_transform_index(i)];
    }

    return result;
}



void operator()(complex_vector& signal) {
    //complex_vector data = transform(signal);


    impl(signal);
}

void impl(complex_vector& data) {
    if(data.size() == 1) {
        return;
    }

    complex_vector even = complex_vector(data.size() / 2);
    complex_vector odd = complex_vector(data.size() / 2);

    for(std::size_t i = 0; i < data.size() / 2; ++i) {
        even[i] = data[i * 2];
        odd[i] = data[i * 2 + 1];
    }

    impl(even);
    impl(odd);

    std::complex<double> w = 1;
    std::complex<double> wN = std::complex<double>(std::cos(2 * M_PI / (double)data.size()), std::sin(2 * M_PI / (double)data.size()));
    for (std::size_t i = 0; i < data.size() / 2; ++i) {
        data[i] = even[i] + w * odd[i];
        data[i + data.size() / 2] = even[i] - w * odd[i];
        w *= wN;
    }
}

void restore(complex_vector& data) {
    if(data.size() == 1) {
        return;
    }

    complex_vector even = complex_vector(data.size() / 2);
    complex_vector odd = complex_vector(data.size() / 2);

    for(std::size_t i = 0; i < data.size() / 2; ++i) {
        even[i] = data[i * 2];
        odd[i] = data[i * 2 + 1];
    }

    restore(even);
    restore(odd);

    std::complex<double> w = 1;
    std::complex<double> wN = std::complex<double>(std::cos(-(2 * M_PI / (double)data.size())), std::sin(-(2 * M_PI / (double)data.size())));
    for (std::size_t i = 0; i < data.size() / 2; ++i) {
        data[i] = even[i] + w * odd[i];
        data[i + data.size() / 2] = even[i] - w * odd[i];
        w *= wN;
    }
}

void restore__(complex_vector& signal) {
    //complex_vector data = transform(signal);


    restore(signal);
}

};

}



/*
constexpr bool is2Power() {
    std::size_t N_ = N;
    if(N_ < 2) {
        return false;
    }

    do
    {
        if(N_ % 2 != 0) {
            return false;
        }

        N_ /= 2;
    } while (N_ != 0);

    return true;
}
*/
//static_assert(is2Power(N));