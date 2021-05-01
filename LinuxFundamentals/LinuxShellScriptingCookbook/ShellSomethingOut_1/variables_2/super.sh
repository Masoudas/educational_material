#!/bin/bash

my="Has Space and; semicolon"

var1=${my}
var2="${my}"
var3=\"${my}\"

var4=$var3

echo $var1
echo $var2 
echo $var3
echo $var4