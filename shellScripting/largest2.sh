#!/bin/bash
echo "enter number 1"
read a
echo "enter number 2"
read b
if [ $a > $b ]
then
	echo "Largest number is number 1"
else
	echo "Largest number is number 2"
fi
