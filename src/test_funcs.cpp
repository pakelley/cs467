#ifndef _TEST_FUNCS_CPP_
#define _TEST_FUNCS_CPP_


#include "test_funcs.hpp"

/**********************************************************/
/////////////////// f: exp(sin( x*pi )) ////////////////////
/**********************************************************/
// pi * exp(sin( x*pi ))
complex f(complex x){
  return exp(sin(M_PI * x));
}

// pi * exp(sin(x*pi)) * cos(x*pi)
complex   df(complex x) {
  complex val = M_PI * f(x),   // pi * exp(sin(x*pi))
    val_chain = cos(M_PI * x); // cos(x*pi)
  
  return val * val_chain;
}

// pi^2 * exp(sin(x*pi)) * [ sin(x*pi) - cos(x*pi)^2 ]
complex  ddf(complex x) {
  complex val = pow(M_PI,2) * f(x),      // pi^2 * exp(sin(x*pi))
    val_chain1 =      sin(x * M_PI),     // sin(x*pi)
    val_chain2 = pow( cos(x * M_PI), 2); // cos(x*pi)^2
  
  return val * (val_chain1 - val_chain2);
}

// pi^3 * exp(sin(x*pi)) * { cos(x*pi) * [ -3*sin(x*pi) + cos(x*pi)^2 - 1 ] }
complex dddf(complex x) {
  complex val =  pow(M_PI, 3) * f(x),     // pi^3 * exp(sin(x*pi))
    val_chain1 =      cos(x * M_PI),      // cos(x*pi)
    val_chain2 = -3.0*sin(x * M_PI),      // -3 * sin(x*pi)
    val_chain3 = pow( cos(x * M_PI),  2); // cos(x*pi)^2
  
  return val * val_chain1 * (val_chain2 + val_chain3 - 1.0);
}


/**********************************************************/
/////////////////////// g: exp(x^2) ////////////////////////
/**********************************************************/
// exp(x^2)
complex g(complex x) {
  return exp( pow(x, 2) );
}

// exp(x*2) * 2x
complex   dg(complex x) {
  complex val = exp( pow(x,2) ), // exp(x^2)
    val_chain = 2.0 * x;         // 2x

  return val * val_chain;
}

// exp(x*2) * 2[ 2(x^2) + 1 ]
complex  ddg(complex x) {
  complex val = exp( pow(x,2) ),            // exp(x^2)
    val_chain = 2.0 * (2.0*pow(x,2) + 1.0); // 2[2(x^2) + 1]

  return val * val_chain;
}

// exp(x*2) * 4x[ 2(x^2) + 3 ]
complex dddg(complex x) {
  complex val = exp( pow(x,2) ),              // exp(x^2)
    val_chain = 4.0*x * (2.0*pow(x,2) + 3.0); // 4x[2(x^2) + 3]

  return val * val_chain;
}

/**********************************************************/
////////////////////////// extras //////////////////////////
/**********************************************************/

// just make a vector of values from one of the above functions
// sorry for function pointer weirdness... didn't want to write 8 of these
c_vec genFromFunction(int start, int end, complex (*func)(complex)) {
  int len = end - start;
  c_vec vec(len);
  for(int i=0, j=start; j<end; i++, j++) {
    vec[i] = func(j); // Note: i and j are just shifted by 'start' from eachother
  }
  return vec;
}

#endif
