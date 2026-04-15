#!/bin/bash
echo "Choose an option:"
echo "a) Leap Year"
echo "b) Even or Odd"
echo "c) Largest of 3 numbers"
read choice
case $choice in
a)echo "Enter year:"
  read year
	if  (year % 4 == 0)
  then
    echo "Leap Year"
  else
    echo "Not a Leap Year"
  fi
  ;;

b)
  echo "Enter number:"
  read num

  if (( num % 2 == 0 ))
  then
    echo "Even number"
  else
    echo "Odd number"
  fi
  ;;

c)
  echo "Enter three numbers:"
  read a b c

  if (( a >= b && a >= c ))
  then
    echo "Largest is $a"
  elif (( b >= a && b >= c ))
  then
    echo "Largest is $b"
  else
    echo "Largest is $c"
  fi
  ;;

*)
  echo "Invalid choice (default case)"
  ;;

esac
