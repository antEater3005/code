// Function overloading means passing more arguments then specified number of parameters in the actual function
#include <iostream>
using namespace std;
int sum(int a, int b) // here we created two function with name sum;
{
    cout << "using function with two arguments.\n";
    return a + b;
}
int sum(int a, int b, int c)
{
    cout << "using function with three arguments.\n";
    return a + b + c;
}
// Calculate the value of cylinder.
int volume(double r, int h)
{
    return (3.14 * r * r * h);
}
// Calculate the value of cube.
int volume(int a)
{
    return (a * a * a);
}
// Volume of cuboid.
int volume(int l, int b, int h)
{
    return (l * b * h);
}
int main()
{
    cout << "The sum of 4 and 5 is=" << sum(4, 5) << endl;
    cout << "The sum of 4, 5 and 8 is=" << sum(4, 5, 8) << endl; // this function has three arguments so the compiler will automatically call the function with three parameteres.
    cout << "The volume of cube of side 4 cm is" << volume(4) << endl;
    cout << "The volume of cylinder of radius 8 cm and hight 14 cm is " << volume(8, 14) << endl;
    cout << "The volume of cuboid of lenght 7cm breadth 6cm and hieght 8cm is " << volume(7, 6, 8) << endl;
    return 0;
}