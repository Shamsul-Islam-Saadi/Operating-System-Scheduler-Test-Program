#!/bin/sh
echo "Bash Script Started!"
echo " "

#Compiling and Calling FCFS scheduler 
gcc scheduler_FCFS.c -o scheduler_FCFS
time ./scheduler_FCFS
echo " "

#Compiling and Calling SJF scheduler
gcc scheduler_SJF.c -o scheduler_SJF
time ./scheduler_SJF
echo " "

#Compiling and Calling Priority_Based scheduler 
gcc scheduler_PriorityBased.c -o scheduler_PriorityBased
time ./scheduler_PriorityBased
echo " "

echo "Bash Script Finish!"
echo " "

