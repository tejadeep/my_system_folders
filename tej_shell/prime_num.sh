echo enter a number
read num
#for x in {2..$num}
for ((x=2;x<num;x++))
do
k=`expr $num % $x`
echo $k
	if [ $k == 0 ]
	then
	break
	fi	
done

if [ $num -eq $x ]
then
echo number is a prime number
else
echo number is not a prime 
fi
