addpath('/home/quepas/PhD/Tools/PAPI Wrappers/mPAPI')
%clear all;
N = 1e8;
A = rand(1, N);
B = rand(1, N);
E = rand(1, N);
C = rand(1,N);
D = rand(1, N);

mPAPI_register('PAPI_L1_TCM', 'PAPI_L2_TCM', 'PAPI_L3_TCM');

%tic;
%C = ones(1, N);
mPAPI_tic;
tic
%C = A(1:N) + B(1:N);
D = A + B + C;
toc
mPAPI_toc

%toc

A = rand(1, N);
B = rand(1, N);
C = rand(1, N);
%tic;
mPAPI_tic;
tic
%addTwo(A(1:N), B(1:N), E);
addThree(A, B, C, E);
toc
mPAPI_toc



%all(C == E) 
%t1/t2