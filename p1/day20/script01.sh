#!/bin/bash
findSum(){
	read -p "num1: " num1
	read -p "num2: " num2
	echo $((num1 + num2))
}
findSum
