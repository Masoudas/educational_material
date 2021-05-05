#!/bin/bash

result=`expr 3 + 4`
result=$(expr $no1 + 5)

echo $result

no1=1
no2=2

let result=no1+no2

echo $result