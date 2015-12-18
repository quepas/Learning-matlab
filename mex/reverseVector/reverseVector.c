#include "mex.h"

void reverseVector(double* vec, double* out, mwSize n)
{
    mwSize i;
    for (i = 0; i < n; i++) {
        out[i] = vec[n-i-1];
    }
}

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    double* inVector;  /* 1xN input vector */
    size_t ncols;      /* Vector size N    */
    double* outVector; /* Output vector    */

    /* Check input arguments */
    if (nrhs != 1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","One input required.");
    }
    if (!mxIsDouble(prhs[0]) || mxIsComplex(prhs[0])) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notDouble","Input vector must be type double.");
    }
    if(mxGetM(prhs[0])!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notRowVector","Input must be a row vector.");
    }
    /* Check output arguments */
    if(nlhs!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    inVector = mxGetPr(prhs[0]);
    ncols = mxGetN(prhs[0]);
    plhs[0] = mxCreateDoubleMatrix(1, (mwSize)ncols, mxREAL);
    outVector = mxGetPr(plhs[0]);
    reverseVector(inVector, outVector, (mwSize) ncols);
}