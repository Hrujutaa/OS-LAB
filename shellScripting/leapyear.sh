#!/bin/bash

echo "Enter  year:"
read year

if [ $((year % 4)) == 0 ]
then
    echo "$year is leap Year"
else
    echo "$year is not leap Year"
fi
