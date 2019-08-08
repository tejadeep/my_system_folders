test1()
{
	echo "in test funtion"
	echo $10
	echo $11
	return `expr $1 + $2`

}


test1 90 20
ret=$?
echo "after fun" $ret
