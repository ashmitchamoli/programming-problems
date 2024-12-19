#!/bin/bash

DNO=$1

# check if the directory exists
if [ -d $DNO ]; then
	echo "Directory $DNO already exists. Please choose a different number."
	exit 1
fi

# create the directory
mkdir $DNO
mkdir $DNO/1
mkdir $DNO/2
touch $DNO/input.txt
cp template.py $DNO/1/solution.py
cp template.py $DNO/2/solution.py
cd $DNO

echo "Success"