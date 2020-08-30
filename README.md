# cassie-mujoco-sim
A simulation library for Agility Robotics' Cassie robot using MuJoCo.

Developed and tested on Ubuntu 16.04. Also compiles for Windows using mingw-w64.

To build the shared library:
1.  Install libglfw3-dev
2.  Clone this repository
3.  Download mjpro150_linux.zip from roboti.us
4.  Put mjpro150 in the cassie-mujoco-sim directory
5.  `make`

To cross-compile for Windows, use `make PLATFORM=WIN`.

A directory named release will be created containing the files needed to use the library with a C interface. A Python interface can be generated with `make ctypes`, which requires ctypeslib2 to be installed.

A license file for MuJoCo (mjkey.txt) is required to run the simulation. The library also includes functions that can be used for communicating with Cassie over UDP, and MuJoCo is not required if only these functions are called.

To build and run the examples:
1.  Place mjkey.txt in the cassie-mujoco-sim directory
2.  `make test`
3.  Run the examples in the test directory

The examples include cassiesim, which simulates a physical Cassie robot controlled over UDP, and cassiectrl, a null controller operating over UDP. The file cassietest.c is a minimal example of running the simulation, and cassietest.py demonstrates controlling the simulated robot in Python.

Documentation for the simulation functions is included in include/cassiemujoco.h. The file header/udp.h declares convenience functions for creating a UDP socket and obtaining the most recent packet. The remaining header files include functions for packing and unpacking structures used to communicate with Cassie into UDP packets and for simulating Cassie's internal safety mechanisms and state estimation processes.


# cassie-mujoco-sim-Venki-edit

I have modified the cassietest.c program to make it do my tasks.

Any function that we write needs to be placed inside src folder in a .c file

The corresponding header file will be placed in the header folder.

Any changes to the cassietest.c progeam needs to be done in the example folder( another fplder is created called test- do not touch this)
      
To run the program just run the run_cassietest.sh script or follow the steps in it.

## How to run MATLAB and C together(calling MATLAB functiond from C here): 

***Code:***

We use MATLAB engine API for C to do the task.
The header files required are mentioned in the mat_to_c.c file 

Include mat_to_c.h file in cassietest.c( this has already been added to the code and is just an informative point).

We use mex compiler for compiling the cassietest.c file and linking along with the libraries of MATLAB (see makefile of example folder).

 

***How to run:***

Step 0: Add the BRL-test-folder/MATLAB_CODE to MATLAB PATH.

step 1: `make test`

Step 2: run the `mat_to_c`executable file in the `test` folder (we can set the name of the exec in the make file : look at MATLAB documentation of mex compiler for           more ).

***How to add path to MATLAB ROOT:***

step 1: Click on setPath>Add Folder> (click on th required folder here MATLAB_Code)

Step 2: Click on save

What if it does allow you to save?

The one that you add in the path on the earlier step might be just for the current session of MATLAB and when you restart it, then you might have to set the path again. 

We need  to permanently add the path that we need to MATLAB, this can be done by following the [instructions here](https://www.mathworks.com/matlabcentral/answers/102037-how-can-i-move-the-pathdef-m-file-from-its-default-location-to-another-location-in-matlab-8-1-r20).
