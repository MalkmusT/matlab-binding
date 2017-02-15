N=100000000;
a=zeros(1,N);
mex  COMPFLAGS='$COMPFLAGS -O3' sqrtcpp.cpp;
tic 
b=sqrt( a );
toc
tic
c=sqrtcpp(a);
toc
