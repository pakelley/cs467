#ifndef _FFT_HPP_
#define _FFT_HPP_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.hpp"


void fftwork(int N,int s, complex *x, complex *y);
c_vec fft(c_vec x);
c_vec alt_fft(c_vec x);
complex approx(int N, std::vector< complex > y, complex x);
complex f(complex x);
c_vec kDeriv(c_vec f_f, int k);
complex error(c_vec A, c_vec f, int N, int k);

#endif
