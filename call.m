N=100000000;
a=zeros(1,N);
mex sqrtcpp.cpp;
tic 
b=sqrt( a );
toc
c=sqrtcpp(a);
toc
