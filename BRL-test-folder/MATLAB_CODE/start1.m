% save starting directory
startdir = pwd ;

% specify arbitrary directory containing pathdef.m
pathdir = '/home/nishanth/Documents/cassie-mujoco-sim-master/BRL-test-folder/MATLAB_CODE' ;

% change directory so that target 'pathdef.m' has highest precedence
% in the MATLAB search path
cd(pathdir)

% set the MATLAB search path using PATH
path(pathdef)

% change directory back to the starting directory
cd(startdir)