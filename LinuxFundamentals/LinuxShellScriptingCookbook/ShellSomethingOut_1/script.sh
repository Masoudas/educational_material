var="Why does the old woman in front of me want to kill me?"
for i in `seq 0 ${#var}`
do
	echo  ${var:$i:1}
done