#include "mex.h"
#include <iostream>
#include <math.h>


void _main();

static void mexcpp ( const double &arg, double &dest )
{
  dest = std::sqrt( arg );
}

void mexFunction ( int nlhs, mxArray *plhs[],
                   int nrhs, const mxArray *prhs[] )
{
  /* Check for proper number of arguments */

  if( nrhs != 1 )
    mexErrMsgIdAndTxt( "MATLAB:mexcpp:nargin",
                       "MEXCPP requires one input arguments." );
  else if( nlhs != 1 )
    mexErrMsgIdAndTxt( "MATLAB:mexcpp:nargout",
                       "MEXCPP requires one output argument." );

  double* vals = mxGetPr( prhs[0] );
  std::size_t nArgs = mxGetN( prhs[0] );
  plhs[0] = mxCreateDoubleMatrix((mwSize) nArgs, 1, mxREAL );
  double* dests = mxGetPr( plhs[0] );

  for( std::size_t i =0;i<nArgs; ++i )
    mexcpp( vals[ i ], dests[ i ] );
}

