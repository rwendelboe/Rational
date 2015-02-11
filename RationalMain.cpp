#include <iostream>
#include "Rational.h"

using namespace std;

int main(){
	char q;
	Rational a;
	Rational b(a) ;
	Rational c(3), d(2, 3), e("2/4");
	
	
	cout<<"Input a rational number with a / in the middle"<<endl;
	cin>>a;
	cout<<a<<endl;
	a += 2 ;
	cout << "That rational number plus 2 is: " << a << endl; // output is 11/4
	b = a+3; 
	cout << "That rational number plus 3 is: " << b << endl;
	
	cout <<b++<<endl; // output is 23/4

	cout << b << endl; // output is 27/4
	b=12;
	cout<<b<<endl;
	b= "3/2";
	double x = b;
	cout << b <<" is equivalent to " << x << endl; // output is: 3/2 is equivalent to 1.5
	if (a>b)
	{
		cout<<"A is greater "<<endl;
	}
	else 
	{
		cout<<"its not greater "<<endl;
	}
	cin>>q;
	return 0;
}

