declare -A arr
arr["a"]="abadsa"
arr["Aa"]="cd"

for key in "${!arr[@]}"	# The use of quotes is necessary!
do
	echo  Key is $key and value is ${arr[$key]}
done

for pair in ${arr[@]};
do
	echo $pair	# Prints the key value pair as [key]:pair
done

