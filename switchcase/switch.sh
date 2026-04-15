#!/bin/bash
echo "enter the option:"
echo "Display : a= print the date"
echo "b=list all files in the current directory"
read choice
case $choice in
	a) date ;;
	b) ls;;
	*) NOT A VALID OPTION
esac
