echo enter a two number
read a b
echo "1)addition 2)subtraction 3)division 4)multiplication"
read q
case $q in

	1) echo `expr $a + $b`
	;;	
	2) echo `expr $a - $b`
	;;
	3) echo `expr $a / $b`
	;;
	4) echo `expr $a \* $b`
	;;
	*) echo invalid selection
esac
