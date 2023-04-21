#include <iostream>
#include <string>
using namespace std;

class Fraction
{
public:

	Fraction();
	Fraction(int integ);
	Fraction(int den, int numer);
	Fraction(int integ, int den, int numer);
	Fraction(const Fraction& other);
	void GetIntDenNum() const;
	void SetIntDenNum(int integ,int den,int num);
	Fraction& Transformation();
	Fraction& operator =(const Fraction& other);
	Fraction operator +(const Fraction& other);
	Fraction operator -(const Fraction& other);
	Fraction operator /(const Fraction& other);
	Fraction operator *(const Fraction& other);

private:
	int numer;
	int den;
	int integ;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Fraction fr1(0, 1, 5);  //Умножение
	Fraction fr2(0, 5, 1);

	Fraction fr3(4, 0, 0);
	Fraction fr4(0, 3, 4);

	Fraction fr5(0, 21, 30);
	Fraction fr6(0, 5 , 15);

	Fraction fr7(2, 0, 0);   //Деление
	Fraction fr8(0, 1, 2);

	Fraction fr9(0, 1, 2);
	Fraction fr10(0, 1, 4);

	Fraction fr11(0, 5, 7);
	Fraction fr12(0, 3, 5);

	Fraction fr13(0, 2, 3);  //Сложение
	Fraction fr14(0, 1, 2);

	Fraction fr15(0, 5, 1);
	Fraction fr16(0, 1 ,5);

	Fraction fr17(0, 2, 3);
	Fraction fr18(0, 1, 2);

	Fraction fr19(0, 3, 4);  //Вычитание
	Fraction fr20(0, 1, 4);

	Fraction fr21(0, 13, 7);
	Fraction fr22(0, 3, 7);

	Fraction fr23(0, 2, 3);
	Fraction fr24(0, 1, 4);

	Fraction fr01 = fr1 * fr2;
	Fraction fr02 = fr3 * fr4;
	Fraction fr03 = fr5 * fr6;

	Fraction fr04 = fr7 / fr8;
	Fraction fr05 = fr9 / fr10;
	Fraction fr06 = fr11 / fr12;

	Fraction fr07 = fr13 + fr14;
	Fraction fr08 = fr15 + fr16;
	Fraction fr09 = fr17 + fr18;

	Fraction fr010 = fr19 - fr20;
	Fraction fr011 = fr21 - fr22;
	Fraction fr012 = fr23 - fr24;
	
	fr07.GetIntDenNum();
	fr07.Transformation();
	fr07.GetIntDenNum();
	cout << "------------" << endl;
	fr08.GetIntDenNum();
	fr08.Transformation();
	fr08.GetIntDenNum();
	cout << "------------" << endl;
	fr09.GetIntDenNum();
	fr09.Transformation();
	fr09.GetIntDenNum();
	cout << "------------" << endl;
	
}

Fraction::Fraction()
{
	numer = den = integ = 0;
}

Fraction::Fraction(int integ)
{
	numer = den = 0;
	this->integ = integ;
}

Fraction::Fraction(int den, int numer)
{
	integ = 0;
	this->den = den;
	this->numer = numer;
	
}

Fraction::Fraction(int integ, int den, int numer)
{
	this->integ = integ;
	this->den = den;
	this->numer = numer;
}

Fraction::Fraction(const Fraction & other)
{
	this->integ = other.integ;
	this->den = other.den;
	this->numer = other.numer;
}

void Fraction::GetIntDenNum() const
{
	cout << "Целое число равно: " <<this->integ << endl;
	cout << "Знаменатель равен: " <<this->den << endl;
	cout << "Числитель равен  : " <<this->numer << endl;
}

void Fraction::SetIntDenNum(int integ,int den,int numer)
{
	this->integ = integ;
	this->den = den;
	this->numer = numer;
}

Fraction& Fraction:: Transformation()
{
	if (this->den == this->numer)
	{
			this->integ++;
			this->den = 0;
			this->numer = 0;
	}

	if (this->integ == 0)
	{
		if (this->den > this->numer)
		{

			if (this->numer != 1)
			{
				this->integ = (this->den / this->numer) + this->integ;
				this->den = this->den - this->numer;
				this->numer = this->numer;

				if (this->den > this->numer)
				{
					this->den = this->den - this->numer;
					this->numer = this->numer;
				}
			}

			if (this->numer == 1)
			{
				this->integ = this->den / this->numer;
				this->den = 0;
				this->numer = 0;
			}

			if (this->den == this->numer)
			{
				this->den = 0;
				this->numer = 0;
			}
		}
	}
	return *this;
}

Fraction& Fraction :: operator =(const Fraction& other)
{
	this->integ = other.integ;
	this->den = other.den;
	this->numer = other.numer;
	return *this;
}

Fraction Fraction :: operator +(const Fraction& other)
{
	Fraction temp;
	if (this->integ != 0 || other.integ != 0)        // Cмешанные числа
	{
		if (this->numer == other.numer)
		{
			temp.integ = this->integ + other.integ;
			temp.den = this->den + other.den;
			temp.numer = this->numer;
		}
		if (this->den == 0 || this->numer == 0)     //сложение целых чисел и правильной дроби
		{
			temp.integ = this->integ;
			temp.den = other.den;
			temp.numer = other.numer;
		}

		if (this->den == 0 && this->numer == 0)    //cложение целого и смешанного числа
		{
			temp.integ = this->integ + other.integ;
			temp.den = other.den;
			temp.numer = other.numer;
		}

		if (this->integ != 0 && other.integ != 0)
		{
			temp.integ = this->integ + other.integ; //сложение смешанных чисел
			temp.den = ((this->den * other.numer) + (this->numer * other.den));
			temp.numer = (this->numer * other.numer);
		}
	}


	if (this->integ == 0 && other.integ == 0)         //Действия с дробями
	{
		if (this->numer == other.numer)               // Сложение дробей с одинаковыми знаменателями
		{
			temp.den = this->den + other.den;
			temp.numer = this->numer;
		}

		if (this->numer!=other.numer)                  // Сложение дробей с разными знаменателями
		{
			temp.den = ((this->den * other.numer) + (this->numer * other.den));
		    temp.numer = (this->numer * other.numer);
			
		}

		return temp;
	}
}

Fraction Fraction :: operator -(const Fraction& other)
{
	Fraction temp;
	if (this->integ != 0 || other.integ != 0)        // Cмешанные числа
	{
		if (this->numer == other.numer)
		{
			temp.integ = this->integ - other.integ;
			temp.den = this->den - other.den;
			temp.numer = this->numer;
		}
		if (this->den == 0 || this->numer == 0)       //вычитание целых чисел и правильной дроби
		{
			temp.integ = this->integ;
			temp.den = other.den;
			temp.numer = other.numer;
		}

		if (this->den == 0 && this->numer == 0)       //вычитание целого и смешанного числа
		{
			temp.integ = this->integ + other.integ;
			temp.den = other.den;
			temp.numer = other.numer;
		}

		if (this->integ != 0 && other.integ != 0)
		{
			temp.integ = this->integ - other.integ;   //вычитание смешанных чисел
			temp.den = ((this->den * other.numer) - (this->numer * other.den));
			temp.numer = (this->numer * other.numer);
		}
	}


	if (this->integ == 0 && other.integ == 0)         //Действия с дробями
	{
		if (this->numer == other.numer)               // Вычитание дробей с одинаковыми знаменателями
		{
			temp.den = this->den - other.den;
			temp.numer = this->numer;
		}

		if (this->numer != other.numer)               // Вычиатние дробей с разными знаменателями
		{
			if (other.numer % this->numer)
			{
				temp.den = ((this->den * other.numer) - (this->numer * other.den));
				temp.numer = (this->numer * other.numer);
			}

			if (other.numer % this->numer)
			{
				temp.den = ((this->den * other.numer) - (this->numer * other.den));
				temp.numer = (this->numer * other.numer);
			}

			if (this->numer % other.numer)
			{
				temp.den = ((this->den * other.numer) - (this->numer * other.den));
				temp.numer = (this->numer * other.numer);
			}
		}
	}
	return temp;
}

Fraction Fraction :: operator /(const Fraction& other)
{
	Fraction temp;
	if (this->integ != 0 || other.integ != 0)        //Cмешанные числа
	{
		if (this->integ != 0 && other.integ == 0)    //Умножение дроби на число
		{
			temp.den = this->integ * other.numer;
			temp.numer = other.den;
		}
	}


	if (this->integ == 0 && other.integ == 0)
	{
		temp.den = this->den * other.numer;
		temp.numer = this->numer * other.den;
	}
	return temp;
}

Fraction Fraction :: operator *(const Fraction& other)
{
	Fraction temp;
	if (this->integ != 0 || other.integ != 0)        //Cмешанные числа
	{
		if (this->integ == 0 && other.integ != 0)    //Умножение дроби на число
		{
			temp.den = this->den * other.integ;
			temp.numer = this->numer;
		}

		if (this->integ != 0 && other.integ == 0)    //Умножение дроби на число
		{
			temp.den = this->integ * other.den;
			temp.numer = other.numer;
		}
	}


	if (this->integ == 0 && other.integ == 0)
	{
		temp.den = this->den * other.den;
		temp.numer = this->numer * other.numer;
	}
	return temp;
}