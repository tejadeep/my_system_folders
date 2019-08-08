#include<iostream>
using namespace std;
class hari
{
public:
int a;
int c;

	hari(int b)
	{
	a=b;
	cout << a;
	}

	hari(hari &m)
	{
	cout << "deep copy\n";
	c=m.a;


	}

};

main()
{
hari ob1(10),ob2(ob1);
cout << ob2.c;


}
