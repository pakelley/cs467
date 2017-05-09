#ifndef _TEST_FUNCS_HPP_
#define _TEST_FUNCS_HPP_

#include <complex>
#include <vector>

#include "utils.hpp"

complex    f(complex x);
complex   df(complex x);
complex  ddf(complex x);
complex dddf(complex x);

complex    g(complex x);
complex   dg(complex x);
complex  ddg(complex x);
complex dddg(complex x);

c_vec genFromFunction(int start, int end, complex (*func)(complex));

#endif
