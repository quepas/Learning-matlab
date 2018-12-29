#include "mex.h"
#include <x86intrin.h>
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
   double *a;
   double *b, *out;

   a = mxGetPr(prhs[0]);
   size_t ncols = mxGetN(prhs[0]);
   //size_t ncols = 100000000;
   b = mxGetPr(prhs[2]);
   //plhs[0] = mxCreateDoubleMatrix(1, (mwSize)ncols, mxREAL);
   //out = mxGetPr(plhs[0]);
   out = mxGetPr(prhs[2]);

   for (unsigned int i = 0; i < ncols; i += 2)
   {
      __m128d aa = _mm_set_pd(a[i], a[i + 1]);
      __m128d bb = _mm_set_pd(b[i], b[i + 1]);
      //out[i] = a[i] + b[i];
      __m128d cc = _mm_add_pd(aa, bb);
      _mm_storer_pd(&out[i], cc);
   }
}