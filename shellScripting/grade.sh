#!/bin/bash

echo "Enter marks:"
read marks

if (( marks > 75 ))
then
    echo "Distinction"
elif (( marks >= 65 && marks <= 75 ))
then
    echo "1st Division"
elif (( marks >= 55 && marks < 65 ))
then
    echo "2nd Division"
else
    echo "3rd Division"
fi
