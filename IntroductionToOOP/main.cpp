//IntroductionToOOP
#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------------\n"

/*
---------------
�������� ��������� ��� �����, �� ������� ����� ��� ������,
���������������� ��� ������.
				  ����� - ��� ��� ������
				��������� - ��� ��� ������
---------------
*/

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	//				Methods:
	double distance(const Point& other)const//Point other - ������ ������ (������ �����)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	//type name;
	int a;		//���������� ���������� 'a' ���� 'int'
	Point A;	//���������� ���������� 'A' ���� 'Point'
	//���������� ������� 'A' ��������� 'Point'
	//�������� ���������� 'A' ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;	//Default constructor
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;	//Copy constructor (Deep copy) new
	//Shallow copy
	D.print();

	Point E;
	E = D;		//Copy assignment (�������� ������������)
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();
	cout << delimiter << endl;
	cout << "���������� �� ����� A �� ����� B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� A �� ����� B: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� A � B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� B � A:   " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

}

/*
------------------------------------
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
------------------------------------
*/

/*
------------------------------------
1. Encapsulation - ��� �������� ������������ ����� ������ �� �������� ����;
	������������ �������:
		private:	�������� ����, �������� ������ ������ ������
		public:		�������� ����, �������� �� ������ ����� ���������
		protected:	���������� ����, �������� ������ ������ ������, � ��� �������� �������
	get/set-������
	get (�����, ��������) ��������� �������� �������� �������� ����������, �.�.,
		��������� ������ � �������� ���������� �� ������.
	set (������, ����������) ��������� �������� �������� �������� ���������� � ������, �.�.,
		��������� ������ � �������� ���������� �� ������.
2. Inheritance;
3. Polymorphism;
------------------------------------
*/

/*
------------------------------------
1. Constructor - ��� �����, ������� ������� ������, � ������, �������� ������ ��� ������,
   � �������������� ��� ���� ��� ��������;
2. ~Destructor - ��� �����, ������� ���������� ������ �� ��������� ��� ������� �����.
   ����� ����� ������� ���������� ��� ������ �� ������� ������� ���������, � ������� �� ��������;
3. Assignment operator;
				���� �������������:
	-� �����������;
	-��� ����������;
	-�� ��������� - ��� �����������, ������� ����� ���� ������ ��� ����������;
	-����������� �����������;
	-����������� ��������;
------------------------------------
*/

/*
------------------------------------
				Overloading rules:
1. ����������� ����� ������ ������������ ���������.
   ��������� ����� ��������� ����������.
	+  �������������;
	++ �������������;
	%  �������������;
	%% �� �������������;
	@  �� �������������;
2. �� ��� ������������ ��������� ����� �����������.
   �� ��������������:
	?: - Conditional ternary operator
	:: - Scope operator (�������� ���������� ���������)
	.  - Point operator (�������� ������� �������)
	.* - Pointer to member selection
	#
	##
3. ������������� ��������� ��������� ���������;
4. �������� ��������� ���������� ��� ����������� ������ ����������;
------------------------------------
	type operator@(parameters)
	{
		...;
		group-of-statements;
		...;
	}
------------------------------------
*/