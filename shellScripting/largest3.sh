#!/bin/bash

echo "Enter num1:"
read a
echo "Enter num2:"
read b
echo "Enter num3:"
read c

if [ "$a" -ge "$b" ] && [ "$a" -ge "$c" ]
then
    echo "$a is the largest number"
elif [ "$b" -ge "$a" ] && [ "$b" -ge "$c" ]
then
    echo "$b is the largest number"
else
    echo "$c is the largest number"
fi
