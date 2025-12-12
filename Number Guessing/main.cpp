#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int key = 65;
    int choice;
    int tries = 10;
    cout << "No of tries left: " << tries << endl;
    while (key != choice || tries > 0)
    {
        cout << "Enter your choice: " << endl;
        cin >> choice;
        if (tries == 0)
        {
            cout << "Out of turns!" << endl;
            break;
        }
        if (key > choice)
        {
            tries--;
            cout << "Guess is lower, Try high!" << endl;
            cout << "No of tries left: " << tries << endl;
            continue;
        }
        else if (key < choice)
        {
            tries--;
            cout << "Guess is high, Try low!" << endl;
            cout << "No of tries left: " << tries << endl;
            continue;
        }
        else
        {
            cout << "You Found it!" << endl;
            break;
        }
    }
    return 0;
}