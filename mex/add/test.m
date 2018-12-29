addpath('/home/quepas/PhD/Tools/PAPI Wrappers/mPAPI')
%clear all;
N = 1e8;
A = rand(1, N);
B = rand(1, N);
E = rand(1, N);
C = rand(1,N);

mPAPI_register('PAPI_L1_TCM', 'PAPI_L2_TCM', 'PAPI_L3_TCM');

%tic;
%C = ones(1, N);
mPAPI_tic;
tic
%C = A(1:N) + B(1:N);
C = A + B;
toc
mPAPI_toc

%toc

A = rand(1, N);
B = rand(1, N);
%tic;
mPAPI_tic;
tic
%addTwo(A(1:N), B(1:N), E);
addTwo(A, B, E);
toc
mPAPI_toc



%all(C == E) 
%t1/t2