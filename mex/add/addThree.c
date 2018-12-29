#include "mex.h"
#include <x86intrin.h>
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
   double *a, *b, *c, *out;

   a = mxGetPr(prhs[0]);
   size_t ncols = mxGetN(prhs[0]);
   b = mxGetPr(prhs[1]);
   c = mxGetPr(prhs[2]);
   //plhs[0] = mxCreateDoubleMatrix(1, (mwSize)ncols, mxREAL);
   //out = mxGetPr(plhs[0]);
   out = mxGetPr(prhs[3]);

   for (unsigned int i = 0; i < ncols; i += 4)
   {
      //out[i] = a[i] + b[i] + c[i];
      // Not optimized
      // __m128d aa = _mm_set_pd(a[i], a[i + 1]);
      // __m128d bb = _mm_set_pd(b[i], b[i + 1]);
      // //out[i] = a[i] + b[i];
      // __m128d rr = _mm_add_pd(aa, bb);
      // __m128d cc = _mm_set_pd(c[i], c[i + 1]);
      // __m128d final = _mm_add_pd(rr, cc);
      // _mm_storer_pd(&out[i], final);

      // Optimized SSE2
      // __m128d aa = _mm_set_pd(a[i], a[i + 1]);
      // __m128d bb = _mm_set_pd(b[i], b[i + 1]);
      // aa = _mm_add_pd(aa, bb);
      // bb = _mm_set_pd(c[i], c[i + 1]);
      // aa = _mm_add_pd(aa, bb);
      // _mm_storer_pd(&out[i], aa);
      // AVX 256 bits
      __m256d aa = _mm256_set_pd(a[i], a[i + 1], a[i + 2], a[i + 3]);
      __m256d bb = _mm256_set_pd(b[i], b[i + 1], b[i + 2], b[i + 3]);
      __m256d cc = _mm256_set_pd(c[i], c[i + 1], c[i + 2], c[i + 3]);
      __m256d rr = _mm256_add_pd(aa, bb);
      rr = _mm256_add_pd(rr, cc);
      _mm256_store_pd(&out[i], rr);
   }
}