#!/bin/bash
read -p "Enter number: " num

if [ $(( $num % 2 )) -eq 1 ]; then
	echo "$num is an odd number"
else
	echo "$num is an even number"
fi
