#include<iostream>
#include<cstring>
using namespace std;
class hari
{
public:
char *a;
int c;

	hari(const char *s)
	{
	a=new char[strlen(s)+1];
	strcpy(a,s);
	}

	void modi()
	{
	a[0]='k';
	}
	hari(hari &temp)
	{
	a=new char[strlen(temp.a)+1];
	strcpy(a,temp.a);

	}

};

main()
{
hari ob1("votary"),ob2(ob1);

cout << ob2.a;
ob1.modi();

cout << "after\n";
cout << ob1.a << " " << ob2.a;

}
