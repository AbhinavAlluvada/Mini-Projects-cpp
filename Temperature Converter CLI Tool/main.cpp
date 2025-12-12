#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
void showmenu()
{
    cout << "Temperature Converter CLI Tool" << endl;
    cout << "1. Celsius -- Fahrenheit" << endl;
    cout << "2. Fahrenheit -- Celsius" << endl;
    cout << "3. Celsius -- Kelvin" << endl;
    cout << "4. Kelvin -- Celsius" << endl;
    cout << "5. Exit" << endl;
}
int main()
{
    showmenu();
    int choice;
    while (true)
    {
        cout << "Enter your choice: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Celsius temp: ";
            float cel;
            cin >> cel;
            float fra = (cel * 9 / 5) + 32;
            cout << "Fahrenheit temp: " << fra << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter Fahrenheit temp: ";
            float fra;
            cin >> fra;
            float cel = (fra - 32) * 5 / 9;
            cout << "Celsius temp: " << cel << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter Celsius temp: ";
            float cel;
            cin >> cel;
            float kel = cel + 273.15;
            cout << "Kelvin temp: " << kel << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter Kelvin temp: ";
            float kel;
            cin >> kel;
            float cel = kel - 273.15;
            cout << "Celsius temp: " << cel << endl;
        }
        else
        {
            cout << "Terminated!" << endl;
            break;
        }
    }
    return 0;
}