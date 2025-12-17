#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string Name;
    int Id;
    int Marks;

public:
    vector<string> name_vect;
    vector<int> id_vect;
    vector<int> marks_vect;

    void intro()
    {
        cout << "Welcome to Student Management System!" << endl;
        cout << "Use this app to efficiently store and retrieve student data\n"
             << endl;
    }

    void addStudent()
    {
        int id, marks;
        string name;

        cout << "Enter ID of Student: ";
        cin >> id;

        cin.ignore(); // IMPORTANT: clear newline before getline
        cout << "Enter name of Student: ";
        getline(cin, name);

        cout << "Enter marks of Student: ";
        cin >> marks;

        id_vect.push_back(id);
        name_vect.push_back(name);
        marks_vect.push_back(marks);

        cout << "Data Added Successfully\n";
    }

    void showStudent()
    {
        int id;
        cout << "Enter Student ID: ";
        cin >> id;

        for (int i = 0; i < id_vect.size(); i++)
        {
            if (id_vect[i] == id)
            {
                cout << "Name: " << name_vect[i] << endl;
                cout << "ID: " << id_vect[i] << endl;
                cout << "Marks: " << marks_vect[i] << endl;
                return;
            }
        }
        cout << "Record Not Found!\n";
    }

    void eraserecord()
    {
        int id;
        cout << "Enter the ID for removal: ";
        cin >> id;

        for (int i = 0; i < id_vect.size(); i++)
        {
            if (id_vect[i] == id)
            {
                id_vect.erase(id_vect.begin() + i);
                name_vect.erase(name_vect.begin() + i);
                marks_vect.erase(marks_vect.begin() + i);
                cout << "Record Deleted Successfully\n";
                return;
            }
        }
        cout << "Record Not Found!\n";
    }

    void instructions()
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. Show Student\n";
        cout << "3. Erase Student\n";
        cout << "4. Exit\n";
        cout << "Press SPACE to show instructions again\n\n";
    }
};

int main()
{
    Student obj;
    obj.intro();
    obj.instructions();

    while (true)
    {
        char choice;
        cout << "Enter your choice: ";
        choice = cin.get();

        if (choice == '\n')
            continue; // 🔑 discard Enter key

        if (choice == '1')
        {
            obj.addStudent();
        }
        else if (choice == '2')
        {
            obj.showStudent();
        }
        else if (choice == '3')
        {
            obj.eraserecord();
        }
        else if (choice == '4')
        {
            cout << "Exiting program...\n";
            break;
        }
        else if (choice == ' ')
        {
            obj.instructions();
        }
        else
        {
            cout << "Invalid choice\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 🔑 clear buffer
        cout << endl;
    }

    return 0;
}
