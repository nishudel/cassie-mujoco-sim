#!/bin/bash
# My first script



#The following creates a backup of cassietest.c and store it
#in the folder /example/BRL-examples  
#cp -b ~/Documents/cassie-mujoco-sim-master/example/cassietest.c ~/Documents/cassie-mujoco-sim-master/example/BRL-examples

#mv ~/Documents/cassie-mujoco-sim-master/example/BRL-examples/cassietest.c cassietest_smlnk.c

#cd ~/Documents/cassie-mujoco-sim-master/
make test
#Note : we edit in the file in  example folder and once we use the 
# 	make test command, it gets updated in the test folder.
#	we just have to run the file in the test folder now
cd test/

echo "Running cassietest.c"


#python 3 cassietest.py

#cassietest
./cassietest 

#cassietest_simulink
#./cassietest_simlnk 
