#!/bin/bash
read -p "Enter number: " num
#tenPercent=$(( num * 10 / 100))
#newNumber=$(( num + tenPercent ))
let tenPercent=num/100*10
let newNumber=num+tenPercent
echo "result: $newNumber"
