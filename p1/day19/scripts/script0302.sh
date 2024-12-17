#!/bin/bash
read -p "Enter number: " num1
read -p "Enter number: " num2
read -p "Enter number: " num3

count=0

if [ $(( $num1 % 2 )) -eq 1 ]; then
	count=$(( $count + 1 ))
fi

if [ $(( $num2 % 2 )) -eq 1 ]; then
	count=$(( $count + 1 ))
fi

if [ $(( $num3 % 2 )) -eq 1 ]; then
	count=$(( $count + 1 ))
fi

echo "There are $count odd numbers among $num1,$num2,$num3"
