#!/bin/bash

# variables
programName="main"
count=60
fileExtension="res"

# get args
for i in `seq 1 $#`
do
	if [ $i -eq 1 ]; then
		programName=$1
	else
	if [ $i -eq 2 ]; then
		count=$2
	else 
	if [ $i -eq 3 ]; then
		fileExtension=$3
	fi
	fi
	fi
done

# generate output files
for i in `seq 1 $count`
do	
	if [ $i -lt 10 ]; then
		fileName=$i
	else
		fileName=$i
	fi 	

	./$programName < $fileName.in > $fileName.$fileExtension
	echo "$i"
done
