#!/bin/bash
echo "options :"
echo "a) add"
echo "b)subtraction"
echo "c) multiplication"
echo "d)division"
echo "enter your choice: "
read choice
echo "enter num1: "
read a
echo "enter num2: "
read b
case $choice in
a)echo "$((a+b))";;
b)echo "$((a-b))";;
c)echo "$((a*b))";;
d)echo "$((a/b))";;
*)echo "enter a valid option"
esac
