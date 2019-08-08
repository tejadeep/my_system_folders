echo enter a number
read num
k=$num
res=0
for ((;$num;num=`expr $num / 10`))
do
	rem=`expr $num % 10`
	res=`expr $res \* 10 + $rem`

done
if [ $res == $k ]
then
echo number is palindrome
else
echo number is not a palindrome
fi
