for i in {2..100}
do
	j=2
	while [ $j -lt $i ]
	do
		k=`expr $i % $j`	
		if [ $k == 0 ]
		then
		break
		fi

		j=`expr $j + 1`
	done
	if [ $i -eq $j ]
	then
	echo $i
	fi
done
