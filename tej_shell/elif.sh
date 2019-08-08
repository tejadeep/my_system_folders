#in .c  else if and in .sh  elif
#      --------             ----

echo "enter marks"
read num
if [ $num -lt 20 ]
then 
echo "poor"
elif [ $num -lt 40 ] 
then
echo "below avg"
elif [ $num -lt 60 ]
then
echo "avg"
elif [ $num -lt 80 ]
then
echo "abv avg"
else
echo "topper"
fi
