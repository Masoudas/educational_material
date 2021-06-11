read ip

oldIFS=$IFS	# IFS affects the echo output, so we should keep the old one.
IFS='.'
tokens=($ip)
IFS=$oldIFS

for word in ${tokens[*]}; do
	octet=$(bc <<< "obase=2; $word")

	# A very bizzare way of making sure the output has exactly eight digits!
	octet=$(bc <<< "obase=2; ibase=2; $octet + 100000000")
	octet=${octet:1:8}	# Alternatively, octet=$(expr substr $octet 2 8)

	# Concatenating ip.
	binary_ip+="$octet."
done

binary_ip=${binary_ip:0:35} # Remove final dot.	
# Alternatively, binary_ip=$(expr substr $binary_ip 1 35)
echo $binary_ip