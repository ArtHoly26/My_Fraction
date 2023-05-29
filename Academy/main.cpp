#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
class Human
{
	std::string last_name;
	std::string first_name;
	int age;

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
	}
	virtual ~Human()
	{

	}

	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " y/o"  << endl;
	}
};

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	Student(HUMAN_TAKE_PARAMETRS,STUDENT_TAKE_PARAMETRS):Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
	}

	~Student()
	{

	}

	void print()const
	{
	    Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}

};

#define TEACHER_TAKE_PARAMETRS const std::string& speciality,int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience
class Teacher : public Human
{
	std::string speciality;
	int experience;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	Teacher (HUMAN_TAKE_PARAMETRS,TEACHER_TAKE_PARAMETRS):Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experience(experience);
	}
	
	~Teacher()
	{

	}

	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
};

class Graduate: public Student
{
	std::string subject;

public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS,const string& subject):Student(HUMAN_GIVE_PARAMETRS,STUDENT_GIVE_PARAMETRS)
	{
		this->subject = subject;
	}

	void print()const
	{
		Student::print();
		cout << subject << " " << endl;
	}
};

std::ostream& operator << (std::ostream& os, const Human& obj)
{
	return os << obj.get_first_name() << obj.get_last_name() << obj.get_age();
}
std::ostream& operator << (std::ostream& os, const Student& obj)
{
	return os << obj.get_first_name() << obj.get_last_name() << obj.get_age() << obj.get_speciality() << obj.get_group() << obj.get_rating() <<" "<< obj.get_attendance();
}
std::ostream& operator << (std::ostream& os, const Teacher& obj)
{
	return os << obj.get_first_name() << obj.get_last_name() << obj.get_age() << obj.get_speciality()<<" "<< obj.get_experience();
}


void AddData(const Human group)
{
	string path = "GroupHuman.txt";
	ofstream add;
	string Data;
	try
	{
		add.open(path, ofstream::app);
		add << group << "\n";
		add.close();
		
    }
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void AddData(const Student group)
{
	string path = "GroupStudent.txt";
	ofstream add;
	try
	{
		add.open(path, ofstream::app);
		add << group << "\n";
		add.close();

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void AddData(const Teacher group)
{
	string path = "GroupTeacher.txt";
	ofstream add;
	string Data;
	try
	{
		add.open(path, ofstream::app);
		add << group << "\n";
		add.close();

	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void ReadData(int choise)
{
	string path;
	string Data;
	ifstream read;
	if (choise == 1)  path = "GroupHuman.txt";
	if (choise == 2)  path = "GroupStudent.txt";
	if (choise == 3)  path = "GroupTeacher.txt";
	try
	{
		read.open(path,ifstream::in);
		if (read.peek() == EOF) cout << "Этот файл пустой" << endl;
		else
		{
			while (!read.eof())
			{
				Data = "";
				getline(read, Data);
				cout << Data << endl;
			}
		}
		read.close();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}
void Delete_Data(int choise)
{
	string path;
	ifstream del;
	if (choise == 1) path = "GroupHuman.txt";
	if (choise == 2) path = "GroupStudent.txt";
	if (choise == 3) path = "GroupTeacher.txt";
	try
	{
	    del.open(path, ifstream::out | ifstream::trunc);
		if (del.peek() == EOF) cout << "Этот файл пустой" << endl;
		del.close();
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	Human* group1[] =
	{
		new Student(" Oleg ", " Zelenskii ", 25, " Game-dev ", " 221SBD ", 85, 70),
		new Teacher(" White ", " Walter ", 50, " Chemistry ", 20),
		new Graduate(" Schreader ", " Hank ", 40, " Criminalistic ", " OBN ", 90, 70, " How to catch Heizenburg "),
		new Student(" Nikolay ", " Remark ", 36," Front-dev "," 245SBD ",90,80),
		new Teacher(" Dmitry ", " Gorlan ", 25," Weapons distr ",25)
	};
	Student* group2[] =
	{
		new Student(" Oleg ", " Zelenskii ", 25, " Game-dev ", " 221SBD ", 85, 70),
		new Graduate(" Schreader ", " Hank ", 40, " Criminalistic ", " OBN ", 90, 70, " How to catch Heizenburg "),
		new Student(" Nikolay ", " Remark ", 36," Front-dev "," 245SBD ",90,80)
	};
	Teacher* group3[] =
	{
		new Teacher(" White ", " Walter ", 50, " Chemistry ", 20),
		new Teacher(" Dmitry ", " Gorlan ", 25," Weapons distr ",25)
	};

	int choise;
	bool flag = false;
	do
	{
		cout << "Main menu " << endl
			<< "1 - Output data about Human" << endl
			<< "2 - Output data about Student" << endl
			<< "3 - Output data about Teacher" << endl
			<< "4 - Exit" << endl;
		cin >> choise;
		system("pause");
		system("cls");
		switch (choise)
		{
		case 1:
			cout << "Группа Human" << endl;
			for (int i = 0; i < sizeof(group1) / sizeof(group1[0]); i++)
			{
				AddData(*group1[i]);
			}
			ReadData(choise);
			system("pause");
			system("cls");
			Delete_Data(choise);
			break;
		case 2:
			cout << "Группа Student" << endl;
			for (int i = 0; i < sizeof(group2) / sizeof(group2[0]); i++)
			{
				AddData(*group2[i]);
			}
			ReadData(choise);
			system("pause");
			system("cls");
			Delete_Data(choise);
			break;
		case 3:
			cout << "Группа Teacher" << endl;
			for (int i = 0; i < sizeof(group3) / sizeof(group3[0]); i++)
			{
				AddData(*group3[i]);
			}
			ReadData(choise);
			system("pause");
			system("cls");
			Delete_Data(choise);
			break;
		case 4:
			flag = true;
			break;
		default:
			cout << "Данной команды не существует!" << endl;
			break;
		}
	}
	while (!flag);
	     
	for (int i = 0; i < sizeof(group1) / sizeof(group1[0]); i++)
	{
		delete group1[i];	
	}
	for (int i = 0; i < sizeof(group2) / sizeof(group2[0]); i++)
	{
		delete group2[i];
	}
	for (int i = 0; i < sizeof(group3) / sizeof(group3[0]); i++)
	{
		delete group3[i];
	}
}