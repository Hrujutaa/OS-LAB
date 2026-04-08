#!/bin/bash
echo "enter num:"
read n
c=0
for ((i=2; i<n; i++))
do
  if ((n%i==0))
  then
    c=1
  fi
done
if ((n<=1 || c==1))
then
  echo "Not Prime"
else
  echo "Prime"
fi
