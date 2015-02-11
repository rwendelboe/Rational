#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational(){
	//cout << "inside the constructor without any parameter " << endl ;
	numerator = 0;
	denominator = 1;
	name= "0";
	//cout << "end of the constructor without any parameters " << endl ;
}
Rational::Rational(int n){
	numerator = n;
	denominator=1;
	name= n;

}
Rational::Rational(int n, int d){
	//cout << "inside the constructor -- 2 parameter" << endl ;
	numerator = n;
	denominator=d;
	ostringstream ostr ;
	ostr << n << "/" << d ;
	//name= n + '/' + d;
	name = ostr.str() ;
	//cout << "end of constructor " << endl ;
}
Rational::Rational(string equ){
	char slash;
	stringstream ss;
	ss<<equ;
	ss>>numerator;
	ss>>slash;
	ss>>denominator;

	name = equ;


}
Rational::Rational(const Rational &rtn){
	//cout << "inside the copy constructor " << endl;
	numerator = rtn.numerator ;
    denominator = rtn.denominator ;
	name= rtn.name;

}

//Assignment operator
Rational & Rational::operator=(const Rational &rtn){
 
	numerator = rtn.numerator ;
    denominator = rtn.denominator ;
	return *this;
}

Rational & Rational::operator=(const int n){
	Rational a(n);
	*this = a;
	return a;

}
Rational & Rational::operator=(const string equ){
	Rational b(equ);
	*this = b;
	return b;
}

//Arithmetic binary operators
Rational Rational::operator+(const Rational &rtn){
	
	int NewNumerator, NewDenominator;
	NewNumerator= (numerator*rtn.denominator) + (rtn.numerator*denominator);
	NewDenominator= denominator*rtn.denominator;
	//cout<<"Im in +Ration&"<<endl;
	Simplify(NewNumerator,NewDenominator);
	Rational temp(NewNumerator, NewDenominator);

	return temp;
}
Rational Rational::operator+(int n){
	int NewNumerator, NewDenominator;
	NewNumerator= numerator+(n*denominator);
	NewDenominator= denominator*1;
	//cout<<"Im in +int"<<endl;
	Simplify(NewNumerator,NewDenominator);
	Rational temp(NewNumerator, NewDenominator);
	return temp;

}
Rational operator+(int n,const Rational &rtn){
	return rtn+n;
	
}

Rational Rational::operator+(string equ){
	Rational a(equ);
	//cout<<"Im in string equ"<<endl;
	return *this + a;
}

//Compound assginment operators
Rational & Rational::operator+=(const Rational &rtn){

	*this = *this + rtn ;
	return *this ;
}

Rational & Rational::operator+=(int n){
	*this = *this + n;
	return *this;
}
Rational & Rational::operator+=(string equ){
	*this = *this + equ;
	return *this;
}

// Relational operators

bool Rational::operator==(const Rational &rtn){
	
	return (double)*this == (double)rtn;

}
bool Rational::operator>(const Rational &rtn){
	return (double)*this > (double)rtn;
}

// Prefix and Postfix operators
Rational  Rational::operator ++ (){
	ostringstream ostr ;
	
	numerator = numerator + denominator;
	//Simplify(numerator, denominator);
	ostr << numerator << "/" << denominator;
	name = ostr.str();
	//cout << "inside the pre fix " << endl ;
	
	return *this ;

}// postpix ++ 
Rational Rational::operator ++(int){
	//cout << "inside the post fix operator " << endl ;
	ostringstream ostr ;
	Rational temp (numerator,denominator);
	numerator = numerator + denominator;
	//Simplify(numerator, denominator) ;
	ostr << numerator << "/" << denominator;
	name = ostr.str();
	return temp;

}// postfix ++

// convert a Rational object to a double

Rational::operator double() const{
	double value = (numerator*1.0)/denominator;
	//cout<<"Calling double converter"<<endl;
	return value;
}

ostream & operator << (ostream &in,const Rational &out){
	if(out.denominator==1)
	{
		in << out.numerator;
	}
	else
	{
		in << out.numerator << "/" << out.denominator;
	}
	return in;
}
istream & operator >> (istream &in, Rational &out){
	in >> out.numerator;
	in.ignore();
	in >> out.denominator;
	Rational::Simplify(out.numerator, out.denominator);
	return in; 
}

int Rational::ComputeGCD(int num, int denom){
	int remainder= denom%num;
	while(remainder!=0)
	{
		denom=num;
		num=remainder;
		remainder=denom%num;
	}
	return num;
}

void Rational::Simplify(int &num, int &denom){
	if (num ==0){
		return;
	}
	int gcd=ComputeGCD(num,denom);

	num=num/gcd;
	denom=denom/gcd;
}



		