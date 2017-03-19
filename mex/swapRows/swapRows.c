#include "mex.h"

void swapRows(double* inMatrix, double* outMatrix, int firstRow, int secondRow, mwSize row, mwSize col) {
    mwSize i;
    for (i = 0; i < col; ++i) {
        outMatrix[i] = inMatrix[i];
    }
}

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    double* inMatrix;  /* 1xN input vector */
    size_t ncols, nrows;      /* size of input matrix    */
    double* outMatrix; /* Output vector    */

    /* Check input arguments */
    if (nrhs != 3) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs","Three input required. One matrix, two row indexes.");
    }
    if (!mxIsDouble(prhs[0]) || mxIsComplex(prhs[0])) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notDouble","Input matrix must be type double.");
    }
    //if(mxGetM(prhs[0]) > ) {
    //    mexErrMsgIdAndTxt("MyToolbox:arrayProduct","Input must be a row vector.");
    //}
    /* Check output arguments */
    if(nlhs!=1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs","One output required.");
    }
    inMatrix = mxGetPr(prhs[0]);
    ncols = mxGetN(prhs[0]);
    nrows = mxGetM(prhs[0]);
    plhs[0] = mxCreateDoubleMatrix((mwSize)nrows, (mwSize)ncols, mxREAL);
    outMatrix = mxGetPr(plhs[0]);
    swapRows(inMatrix, outMatrix, 1, 2, nrows, ncols);
}