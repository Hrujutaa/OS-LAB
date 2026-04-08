#!/bin/bash
echo "enter country name: "
read country
if [ "$country" == "India" ]
then
echo "Then country name is India"
elif [ "$country" == "Nepal" ]
then
echo "The country is Nepal"
else
echo "Not matching with India and Nepal"
fi
