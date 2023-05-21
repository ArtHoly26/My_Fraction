#include <iostream>
using namespace std;

class String;
String operator + (const String left, const String right);
std::ostream& operator << (std::ostream& os, const String& obj);

class String
{
	char* str;

public:

	String()
	{
		str = nullptr;
	}
	String(const char *str)
	{
		int size = strlen(str);
		this->str = new char[size+1];
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		this->str[size] = '\0';
	}
	String(const String& other)
	{
		int size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		this->str[size] = '\0';
	}
	String(String&& other)
	{
		this->str = other.str;
		other.str = nullptr;
	}
	~String()
	{
		delete[] this->str;
	}

	char* Get_Str()const
	{
		return str;
	}

	String& operator = (String&& moved)
	{
		if (&moved!=this)
		{
			delete[] str;
			str = moved.str;
			moved.str = nullptr;
		}
		return *this;
	}
	String& operator = (const String& other)
	{
		if (this -> str != nullptr) delete[] str;
		int size = strlen(other.str);
		this->str = new char[size + 1];
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		this->str[size] = '\0';
		return *this;
	}
	String& operator +=(const String& other)
	{
		return *this = *this + other;
	}
	char& operator [](int i) {return str[i];}
	char& operator [](int i) const{return str[i];}
};

String operator + (const String left ,const String right)
{
	String newStr;
	int size1 = strlen(left.Get_Str());
	int size2 = strlen(right.Get_Str());
	newStr = new char[size1 + size2 + 1];
	for (int i = 0; i < size1; i++) newStr[i] = left[i];
	for (int i = 0; i < size2; i++) newStr[i+size1] = right[i];
	
	newStr[size1 + size2] = '\0';
	return newStr;
}
std::ostream& operator << (std::ostream& os, const String &obj)
{
	os << obj.Get_Str();
	return os;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	String str1= "Hellooooo";
	cout << str1 << endl;
	String str2 = "Worldddddd";
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	str1 += str2;
	String hello;
	hello=String{ "Hello World" };
	cout << hello << endl;
}