#include <stdio.h>

#include "fft.hpp"
#include "test_funcs.hpp"


c_vec calcy(int N);
c_vec alt_calcy(int N);
c_vec calcA_work(std::vector< complex > y);
c_vec calcA(int N);
c_vec alt_calcA(int N);

int main() {
  int N = 2;
  
  c_vec A     = calcA(N),
    A_d1  = kDeriv(A, 1),
    A_d2  = kDeriv(A, 2),
    A_d3  = kDeriv(A, 3);

  c_vec At    = alt_calcA(N),
    At_d1 = kDeriv(At, 1),
    At_d2 = kDeriv(At, 2),
    At_d3 = kDeriv(At, 3);

  c_vec f_vec = genFromFunction((-N/2 + 1), (N/2), f),
    df_vec   = genFromFunction((-N/2 + 1), (N/2), df),
    ddf_vec  = genFromFunction((-N/2 + 1), (N/2), ddf),
    dddf_vec = genFromFunction((-N/2 + 1), (N/2), dddf);

  c_vec g_vec = genFromFunction((-N/2 + 1), (N/2), g),
    dg_vec   = genFromFunction((-N/2 + 1), (N/2), dg),
    ddg_vec  = genFromFunction((-N/2 + 1), (N/2), ddg),
    dddg_vec = genFromFunction((-N/2 + 1), (N/2), dddg);

  return 0;
}


c_vec calcy(int N) {
  c_vec f_t(N);
  for(int l=(-N/2 + 1), i=0; l<=(N/2); l++, i++) {
    f_t[i] = f(2*l / N);
  }
  return fft(f_t);
}

c_vec alt_calcy(int N) {
  c_vec y = calcy(N);
  y[N] = 0;
  return y;
}

c_vec calcA_work(c_vec y) {
  int N = y.size();
  c_vec A(N);
  for (int i = 0; i < N; i++) {
    A[i] = 0.0;
    for (int j=(-N/2 +1); j <=N/2; j++) {
      complex exp1 = IM;
      exp1 *= M_PI * j * i;
      A[i] += y[i] * exp(exp1);
    }
  }
  return A;
}

c_vec calcA(int N) {
  c_vec y = calcy(N);
  return calcA_work(y);
}

c_vec alt_calcA(int N)  {
  c_vec y = alt_calcy(N);
  return calcA_work(y);
}
