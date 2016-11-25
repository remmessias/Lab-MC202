#!/bin/bash

RED=`tput setaf 1`
NC='\033[0m'

count=27
ext1="out"
ext2="res"

# get args
for i in `seq 1 $#`
do
    if [ $i -eq 1 ]; then
        count=$1
    else
    if [ $i -eq 2 ]; then
        ext1=$2
    else 
    if [ $i -eq 3 ]; then
        ext2=$3
    fi
    fi
    fi
done

# make the diff
for i in `seq 1 $count`
do
	fileName=$i
	echo "Arquivo: $fileName"
	diff $fileName.$ext1 $fileName.$ext2
done

echo "${RED}=== DIFF COMPLETED ==="
