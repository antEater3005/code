#include <bits/stdc++.h>
using namespace std;
class Vehicle
{
protected:
    string name;
    string fuel_type;
    bool isImported;
    bool isUsed;

public:
    void get_details()
    {
        cout << "Name: " << name << "\n";
        cout << "Fuel Type: " << fuel_type << "\n";
        cout << "Imported : " << (isImported ? "Yes" : "Made in India") << "\n";
        cout << "Used : " << (isUsed ? "Yes" : "No") << "\n";
    }
};
class Car : public Vehicle
{
public:
    void get_details()
    {
        cout << "Vehicle Type: Car\n";
        Vehicle::get_details();
    }
    Car(string set_name, string set_fuel_type, bool is_imported, bool is_used)
    {
        name = set_name;
        fuel_type = set_fuel_type;
        isImported = is_imported;
        isUsed = is_used;
    }
};
class Bike : public Vehicle
{
public:
    void get_details()
    {
        cout << "Vehicle Type: Bike\n";
        Vehicle::get_details();
    }
    Bike(string set_name, string set_fuel_type, bool is_imported, bool is_used)
    {
        name = set_name;
        fuel_type = set_fuel_type;
        isImported = is_imported;
        isUsed = is_used;
    }
};

int main()
{
    Bike a("Ducati", "petrol", 1, 1);

    a.get_details();

    Car b("Honda", "Diesel", 0, 0);
    return 0;
}