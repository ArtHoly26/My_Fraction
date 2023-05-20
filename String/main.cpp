#include <iostream>

using namespace std;

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
	~String()
	{
		delete[] this->str;
	}
	char* Get_Str()const
	{
		return str;
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
};

String operator + (const String left ,const String right)
{
	String newStr;
	int size1 = strlen(left.Get_Str());
	int size2 = strlen(right.Get_Str());
	newStr = new char[size1 + size2 + 1];

	int i = 0;
	for (; i < size1; i++)
	{
		newStr.Get_Str()[i] = left.Get_Str()[i];
	}

	for (int j = 0; j < size2; j++, i++)
	{
		newStr.Get_Str()[i] = right.Get_Str()[j];
	}
	newStr.Get_Str()[size1 + size2] = '\0';

	return newStr;
}
std::ostream& operator<<(std::ostream& os, const String &obj)
{
	os << obj.Get_Str();
	return os;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	String str1= "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
}