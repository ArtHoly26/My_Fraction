#include <iostream>
using namespace std;

class Fraction;
Fraction operator *(Fraction left, Fraction right);
Fraction operator /(const Fraction left, const Fraction right);
Fraction operator +(Fraction left, Fraction right);
Fraction operator -(Fraction left, Fraction right);
bool operator ==(Fraction left, Fraction right);
bool operator !=(Fraction left, Fraction right);
bool operator >(Fraction left, Fraction right);
bool operator <(Fraction left, Fraction right);
bool operator >=(Fraction left, Fraction right);
bool operator <=(Fraction left, Fraction right);
std::ostream& operator<<(std::ostream& os, const Fraction obj);
std::istream& operator>>(std::istream& is,Fraction &obj);

class Fraction
{
public:

	Fraction();
	explicit Fraction(int integ);
	Fraction(int numer, int den);
	Fraction(int integ, int numer, int den);
	Fraction(const Fraction& other);
	int Get_integ()const;
	int Get_den()const;
	int Get_numer()const;
	void Set_integ (int integ);
	void Set_numer (int numer);
	void Set_den(int den);
	void Print()const;
	Fraction& to_improper();   
	Fraction& to_proper();     
	Fraction& reduce();        
	Fraction  inverted()const; 
	
	Fraction& operator =(const Fraction& other);
	Fraction& operator *= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);
	Fraction& operator +=(const Fraction& other);
	Fraction& operator -=(const Fraction& other);

	Fraction& operator ++();
	Fraction  operator ++(int);
	Fraction& operator --();
	Fraction  operator --(int);

	explicit operator int();
	operator double();

private:
	int integ;
	int numer;
	int den;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Fraction L = (Fraction)2.75;
	cout << L << endl;
}

Fraction::Fraction()
{
	this->integ = 0;
	this->den = 1;
	this->numer = 0;
}
Fraction::Fraction(int integ)
{
	this->integ = integ;
	this->numer = 0;
	this->den = 0;
}
Fraction::Fraction(int numer, int den)
{
	this->integ = 0;
	this->numer = numer;	
	Set_den(den);
}
Fraction::Fraction(int integ, int numer, int den)
{
	this->integ = integ;
	this->numer = numer;
	Set_den(den);
}
Fraction::Fraction(const Fraction& other)
{
	this->integ = other.integ;
	this->den = other.den;
	this->numer = other.numer;
}

Fraction& Fraction::operator = (const Fraction& other)
{
	this->integ = other.integ;
	this->numer = other.numer;
	this->den = other.den;
	return *this;
}
Fraction& Fraction::operator *= (const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator /= (const Fraction & other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator += (const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator -= (const Fraction& other)
{
	return *this = *this - other;
}

Fraction& Fraction::operator ++()
{
	to_proper();
	integ++;
	return *this;
}
Fraction  Fraction::operator ++(int)
{
	to_proper();
	Fraction old = *this;
	integ++;
	return old;
}
Fraction& Fraction::operator --()
{
	to_proper();
	integ--;
	return *this;
}
Fraction  Fraction::operator --(int)
{
	to_proper();
	Fraction old = *this;
	integ--;
	return old;
}

int  Fraction::Get_integ() const
{
	return integ;
}
int  Fraction::Get_numer() const
{
	return numer;
}
int  Fraction::Get_den() const
{
	return den;
}
void Fraction::Set_integ(int integ)
{
	this->integ = integ;
}
void Fraction::Set_numer(int numer)
{
	this->numer = numer;
}
void Fraction::Set_den(int den)
{
	if (den == 0)den = 1;
	this->den = den;
}
void Fraction::Print() const
{
	if (integ) cout << integ;
	if (numer)
	{
		if (integ) cout << "(";
		cout << numer << "/" << den;
		if (integ) cout << ")";
	}
	else if (integ == 0)cout << 0;
	cout << endl;
}

Fraction& Fraction::to_improper()  //убираем целую часть
{
	numer += integ *den;
	integ = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integ += numer / den;
	numer %=den;
	return *this;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numer > den)more = numer, less = den;
	else less = numer, more = den;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);

	int GCD = more;
	numer /= GCD;
	den /= GCD;
	return *this;
}
Fraction  Fraction::inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	inverted.numer ^= inverted.den;
	inverted.den ^= inverted.numer;
	inverted.numer ^= inverted.den;
	return inverted;
}

Fraction operator *( Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.Get_numer() * right.Get_numer(),
		left.Get_den() * right.Get_den()
	).to_proper().reduce();
}
Fraction operator /(const Fraction left, const Fraction right)
{
	return left * right.inverted();
}
Fraction operator +(const Fraction left,const Fraction right)
{
	return Fraction
	(
		left.Get_integ() + right.Get_integ(),
		left.Get_numer() * right.Get_den() + left.Get_den() * right.Get_numer(),
		left.Get_den() * right.Get_den()
	).to_proper().reduce();
}
Fraction operator -(const Fraction left, const Fraction right)
{
	    int more, less, rest, num1, num2;
		if (left.Get_den() > right.Get_den()) more =left.Get_den(), less = right.Get_den();
		else less = left.Get_den(), more = right.Get_den();
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
        more;
		num1 = left.Get_den() / more;
		num2 = right.Get_den() / more;
		
		if (num2 * left.Get_numer() < num1 * right.Get_numer());
		{
			return Fraction
			(
				(left.Get_integ() - right.Get_integ()) - 1,
				(left.Get_numer() * num2 + (left.Get_den() * num2)) - (right.Get_numer() * num1),
				left.Get_den() * num2
			).reduce();
		}

		if (num2 * left.Get_numer() >= num1 * right.Get_numer());
		{
			return Fraction
			(
				left.Get_integ() - right.Get_integ(),
				(left.Get_numer() * num2) - (right.Get_numer() * num1),
				left.Get_den() * num2
			).reduce();
		}
		
		
}
bool operator ==(Fraction left, Fraction right)
{
	return left.Get_integ() == right.Get_integ() && left.Get_numer() == right.Get_numer() && left.Get_den() == right.Get_den();
}
bool operator !=(Fraction left, Fraction right)
{
	return !(left.Get_integ() == right.Get_integ() && left.Get_numer() == right.Get_numer() && left.Get_den() == right.Get_den());
}
bool operator >(Fraction left, Fraction right)
{ 
	if (left.Get_integ() > right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ()) return left.Get_den() > right.Get_den();
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den()) return left.Get_numer() > right.Get_numer();
	else return false;
}
bool operator <(Fraction left, Fraction right)
{
	if (left.Get_integ() < right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ()) return left.Get_den() < right.Get_den();
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den()) return left.Get_numer() < right.Get_numer();
	else return false;
}
bool operator >=(Fraction left, Fraction right)
{
	if (left.Get_integ() > right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() > right.Get_den()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() > right.Get_numer()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() == right.Get_numer()) return true;
	else return false;
}
bool operator <=(Fraction left, Fraction right)
{
	if (left.Get_integ() < right.Get_integ())  return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() < right.Get_den()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() < right.Get_numer()) return true;
	if (left.Get_integ() == right.Get_integ() && left.Get_den() == right.Get_den() && left.Get_numer() == right.Get_numer()) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& os, const Fraction obj)
{
	if (obj.Get_integ())os << obj.Get_integ();
	if (obj.Get_numer())
	{
		if (obj.Get_integ())os << "(";
		os << obj.Get_numer() << "/" << obj.Get_den();
		if (obj.Get_integ()) os << ")";
	}
	else if (obj.Get_integ() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is,Fraction &obj)
{
	int integ;
	int den;
	int numer;
	if (is >> integ >> numer >> den)
	{
	    obj.Set_integ(integ);
		obj.Set_numer(numer);
		obj.Set_den(den);
	}
	return is;
}

Fraction::operator int()
{
	to_proper();
	return integ;
}
Fraction::operator double()
{
	return integ+(double)numer/den;
}




