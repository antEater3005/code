#include <bits/stdc++.h>
using namespace std;
class Person
{
protected:
    string name;
    int age;
    friend class MP;
    friend class PM;
    friend class Minister;

public:
    Person(string set_name, int set_age)
    {
        name = set_name;
        age = set_age;
    }
    Person() {}
};

class MP : public Person
{
protected:
    string constituency;
    int area;
    int spending_left = 50000;
    friend class Minister;

public:
    void get_details()
    {
        cout << "Name :\t" << name;
        cout << "\nAge :\t" << age;
        cout << "\nArea :\t" << area << " Km^2";
        cout << "\nConstituency :\t" << constituency;
        cout << "\nMoney left:\t" << spending_left;
    }
    MP(string set_name, int set_age, string set_constituency, int set_area)
    {
        name = set_name;
        age = set_age;
        constituency = set_constituency;
        area = set_area;
    }
    MP() {}
};
class Minister : public MP
{
protected:
    Person driver;

public:
    Minister(string set_name, int set_age, string set_constituency, int set_area, string set_driver_name, int set_driver_age)
    {
        name = set_name;
        age = set_age;
        constituency = set_constituency;
        area = set_area;
        spending_left = 70000;
        driver.age = set_driver_age;
        driver.name = set_driver_name;
    }
    void get_details()
    {
        MP::get_details();
        cout << "\nDiver Name:\t" << driver.name;
        cout << "\nDiver age:\t" << driver.age;
    }
    Minister() {}
};
class PM : protected Minister
{
    int numberOfCars;

public:
    PM(string set_name, int set_age, string set_constituency, int set_area, string set_driver_name, int set_driver_age, int numOfCars)
    {
        if (numOfCars < 1 || numOfCars > 5)
            throw invalid_argument("Warning:: Number of cars should be greater than 0 and less than or equal to 5!");
        name = set_name;
        age = set_age;
        constituency = set_constituency;
        area = set_area;
        spending_left = 170000;
        driver.age = set_driver_age;
        driver.name = set_driver_name;
        numberOfCars = numOfCars;
    }
    void get_details()
    {
        Minister::get_details();
        cout << "\nNumber of cars:\t" << numberOfCars;
    }
};

int main()
{
    PM *a = new PM("avinash", 98, "sdad", 21, "ramesh", 89, 1);
    a->get_details();

    return 0;
}