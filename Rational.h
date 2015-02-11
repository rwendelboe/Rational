#ifndef Rational_H
#define Rational_H
#include <string>
#include <sstream>

using namespace std;

class Rational{
	public:
		//Constructors and Copy Construtors
		Rational();
		Rational(int);
		Rational(int, int);
		Rational(string) ;
		Rational(const Rational &);

		//Assignment operator
		Rational &operator=(const Rational &);
		Rational &operator=(const int);
		Rational &operator=(const string);

		//Arithmetic binary operators
		Rational operator+(const Rational &);
		Rational operator+(int);
		Rational operator+(string);

		//Compound assginment operators
		Rational &operator+=(const Rational &);
		Rational &operator+=(int) ;
		Rational &operator+=(string) ;

		// Relational operators
		bool operator==(const Rational &);
		bool operator>(const Rational &);
		
		// Prefix and Postfix operators
		Rational operator ++ (); // prefix ++ 
		Rational operator ++(int); // postfix ++

		
		//Prin -Input
		friend istream & operator >> (istream &in, Rational &out) ;
		friend ostream & operator << (ostream &in, const Rational &out) ;
		operator double() const; // convert a Rational object to a double
		;

	private:
		int numerator;
		int denominator;
		string name;
		static void Simplify(int &num, int &denom);
		static int ComputeGCD(int num, int denom);

};
Rational operator+(int n, const Rational& rtn);
//ostream &operator << (ostream& out, Rational obj) ;
#endif
