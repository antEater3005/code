#include <bits/stdc++.h>
using namespace std;
/*
1. Scope resolution operator- (::)
*/
class Box
{
protected:
    int length;
    int width;

public:
    int height;
    //**** constructors are of three types ****
    // default constructor:: this does not take any arguments::It's provided by compiler;
    Box()
    {
        cout << "a new box object created.[1]\n";
        object_count++;
    }
    // parametrized constructor
    Box(int l, int w, int h)
    {
        cout << "a new box object created.[2]\n";
        object_count++;
        length = l;
        width = w;
        height = h;
    }
    // copy constructor::same as parametrized constructor it takes an object of same type as input and copies all data into the newly created object;

    // Destructor:: it's a member function of a class which is called out whenever an object of that class is goes out of scope or a delete expression is applied to it;
    // to create a destructor function us tilde (~) sign before a default constructor::it doesn't take any arguments.
    ~Box()
    {
        object_count--;
        cout << "Object is destructed.\n";
    }

    /**** Static data members ****/
    // static data members are declared using 'static' keyword::for a class only a single copy of static members are created and shared across all the objects of that class;
    // A static data member cannot be private:: often used to count the total number of objects created of a specific class;
    static int object_count;

    /**** Static member function ****/
    // static member fuction has scope only within the class::It can be accessed only using 'class_name::static_member_function'::     A static member function can called even if there are no any object exist of that class;
    // It can only access the static data and function members:: They don't have access to this pointer;
    static int get_objectCount()
    {
        return object_count;
    }

    // normal member function
    int getWidth()
    {
        return width;
    }
    void get_dimensions()
    {
        cout << "L " << length;
        cout << "\nW " << width;
        cout << "\nH " << height;
    }
};

// the static data members of a class is initialised outside the class using scope resolution operator;
int Box::object_count = 0;

/*
 ***** INHERITANCE *****
  1. This feature of object-oriented programming allows user to create a new class(derived_class) from a preexisting class(base_class)
  2. It provides reusability of code::The class which inherits data member and member fuctions is called "Derived/Child class" and the class from which the data members and functions are inherited are called "Base/Parent class";
  3. A class can be derived using following syntax
        derived_class_name : access_specifiers base_class_name;
        There are three access specifiers keyword "private","public" and "protected";
        If a access_specifier is not used, it's private as default.
*/

class BoxFunctions : public Box
{
public:
    void set_width(int w)
    {
        width = w;
    }
};

// Multilevel Inheritance
class shapes : public BoxFunctions
{
public:
    int volume()
    {
        return (length * height * width);
    }
    // shapes(int l, int h, int w)
    // {
    //     length = l, height = h, width = w;
    // }
};

class student_info
{
private:
    string name;
    char sex;
    int age;
    int roll_no;
    static int number_of_student;
    friend void change_name(class student_info &st, string newName); // a friend function can access all the data of a class
    // friend void Admin::add_student(class student_info st);
    // friend class Admin;

public:
    student_info(int roll, string na, char se, int age);
    void display_info(int code);
    static void get_total();
    int get_roll();
    class date
    {
    private:
        int day;
        int month;
        int year;

    public:
        date(int day, int month, int year);
        void display_date();
    };
};
void change_name(class student_info &st, string newName)
{
    st.name = newName;
    cout << "Name has been changed.\n";
}
int student_info::number_of_student; // the static data member should be initialised before the main block
int student_info::get_roll()
{
    return roll_no;
}
student_info::student_info(int roll, string na, char se, int ag)
{
    roll_no = roll;
    number_of_student += 1;
    name = na;
    sex = se;
    age = ag;
}
void student_info::get_total()
{
    cout << "Number of students \t:\t" << number_of_student;
}
void student_info::display_info(int code = 0)
{
    cout << "-------------------------------------------------\n";
    if (code == 1) // means call made by find student function
        cout << "[INFORMATION FOUND]\n";
    cout << "Roll-No\t:\t" << roll_no << "\n";
    cout << "Name \t:\t" << name << "\n";
    cout << "Sex  \t:\t" << sex << "\n";
    cout << "Age  \t:\t" << age << "\n";
}
student_info::date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
void student_info::date::display_date()
{
    cout << day << "/" << month << "/" << year << "\n";
}
// Admin
class Admin
{
    string admin_name;
    map<int, student_info> students;
    static int total_students;

public:
    Admin(string s);
    void add_student(class student_info st);
    void display_students();
    void find_student(int roll);
};
Admin::Admin(string s)
{
    admin_name = s;
}
void Admin::display_students()
{
    for (auto it : students)
        it.second.display_info();
}
void Admin::add_student(class student_info st)
{
    students.insert({st.get_roll(), st});
}
void Admin::find_student(int roll)
{
    auto it = students.find(roll);
    if (it == students.end())
    {
        cout << "[Warning] No data available.\n";
        return;
    }
    it->second.display_info(1);
}
int main()
{
    // student_info st1(1, "Avinash", 'M', 21);
    // student_info::date date1(30, 05, 2002);
    // Admin ad1("Avinash");
    // ad1.add_student(st1);
    // ad1.add_student(student_info(2, "Hariom", 'M', 32));
    // ad1.display_students();
    // ad1.find_student(2);
    Box a(3, 4, 5);
    a.get_dimensions();
    return 0;
}
