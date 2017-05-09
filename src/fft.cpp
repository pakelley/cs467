#ifndef _FFT_CPP_
#define _FFT_CPP_

#include "fft.hpp"


void fftwork(int N,int s, complex *x, complex *y){
    if(N==1){
        y[0]=x[0];
        return;
    }
    if(N%2){
        printf("Error N was not divisible by 2!\n");
        exit(1);
    }
    int K=N/2;
    fftwork(K,2*s,x,y);
    fftwork(K,2*s,x+s,y+K);
    for(int j=0;j<K;j++){
      complex ye=y[j];
      complex yo=y[j+K];
      complex exp1 = IM;
      exp1 *= -2 * M_PI * j / N;
      y[j]=ye+exp(exp1) * yo;
      complex exp2 = IM;
      exp2 *= -2 * M_PI * (j+K) / N;
      y[j+K]=ye+exp(exp2) * yo;
    }
}
c_vec fft(c_vec x){
  int N = x.size();
  c_vec y(N);
  fftwork(N,1,&x[0],&y[0]);
  for(int j=0;j<N;j++) y[j]/=N;
  return y;
}

c_vec alt_fft(c_vec x){
  c_vec y = fft(x);
  *(y.end()) = 0;
  return y;
}

complex approx(int N, std::vector< complex > y,complex x){
    complex r=0.0;
    for(int j=0;j<N;j++){
        int n;
        if(j<=N/2) n=j;
        else n=j-N;
	complex exp1 = IM * x;
	exp1 *= M_PI*n;
        r+=y[j]*exp(exp1);
    }
    return r;
}

c_vec kDeriv(c_vec f_f, int k) {
  int size = f_f.size();
  for (int j=0; j<size; j++) {
    complex exp1 = IM;
    exp1 *= 2 * M_PI * j;
    f_f[j] *= pow( (exp1), k);
  }
  return f_f;
}


complex error(c_vec A, c_vec f, int N, int k) {
  complex err = 0.0;
  auto A_k = kDeriv(A, k);
  auto f_k = kDeriv(f, k);
  for(int l=(-N/2)+1; l<=N/2; l++) {
    complex diff = A_k[l] - f_k[(2*l)/N];
    err += pow( abs(diff), 2 );
  }
  err /= N;
  err = pow(err, 0.5);
  return err;
}

#endif
