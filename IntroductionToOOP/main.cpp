//IntroductionToOOP
#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------------\n"

/*
---------------
Создавая структуру или класс, мы создаем новый тип данных,
пользовательский тип данных.
				  класс - это тип данных
				структуры - это тип данных
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
	double distance(const Point& other)const//Point other - другой объект (другая точка)
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
	int a;		//Объявление переменной 'a' типа 'int'
	Point A;	//Объявление переменной 'A' типа 'Point'
	//Объявление объекта 'A' структуры 'Point'
	//Создание экземпляра 'A' структуры 'Point'
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
	E = D;		//Copy assignment (оператор присваивания)
#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
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
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
------------------------------------
*/

/*
------------------------------------
1. Encapsulation - это сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа:
		private:	закрытые поля, доступны только внутри класса
		public:		открытые поля, доступны из любого места программы
		protected:	защищенные поля, доступны внутри нашего класса, и его дочерних классов
	get/set-методы
	get (взять, получить) позволяют получить значение закрытой переменной, т.е.,
		открывают доступ к закрытым переменным на чтение.
	set (задать, установить) позволяют задавать значения закрытой переменной в классе, т.е.,
		открывают доступ к закрытым переменным на запись.
2. Inheritance;
3. Polymorphism;
------------------------------------
*/

/*
------------------------------------
1. Constructor - это метод, который создает объект, а именно, выделяет память под объект,
   и инициализирует его поля при создании;
2. ~Destructor - это метод, который уничтожает объект по завршении его времени жизни.
   Время жизни объекта завршается при выходе за пределы области видимости, в которой он объявлен;
3. Assignment operator;
				Типы конструкторов:
	-с параметрами;
	-без параметров;
	-по умолчанию - это конструктор, который может быть вызван без параметров;
	-конструктор копирования;
	-конструктор переноса;
------------------------------------
*/

/*
------------------------------------
				Overloading rules:
1. Перегрузить можно только существующие операторы.
   Создавать новые операторы невозможно.
	+  перегружается;
	++ перегружается;
	%  перегружается;
	%% НЕ перегружается;
	@  НЕ перегружфется;
2. НЕ все существующие операторы можно перегрузить.
   НЕ перегружаеются:
	?: - Conditional ternary operator
	:: - Scope operator (Оператор разрешения видимости)
	.  - Point operator (Оператор прямого доступа)
	.* - Pointer to member selection
	#
	##
3. Перегруженные операторы сохраняют приоритет;
4. Изменить поведение операторов над встроенными типами невозможно;
------------------------------------
	type operator@(parameters)
	{
		...;
		group-of-statements;
		...;
	}
------------------------------------
*/