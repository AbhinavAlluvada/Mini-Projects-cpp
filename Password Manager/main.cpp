#include <bits/stdc++.h>
using namespace std;

class PasswordManager
{
public:
    vector<string> name_vect;
    vector<string> pass_vect;
    vector<string> app_vect;

    void intro()
    {
        cout << "Welcome to Password Manager!" << endl;
        cout << "Use this app to store your passwords securely" << endl;
    }

    void instructions()
    {
        cout << "\nFollow the instructions to proceed further" << endl;
        cout << "1. Add Password" << endl;
        cout << "2. Get a specific platform password" << endl;
        cout << "3. Get all passwords" << endl;
        cout << "4. Erase all records" << endl;
        cout << "5. Update a password" << endl;
        cout << "6. Exit" << endl;
        cout << "(Press SPACE to show this menu again)" << endl;
    }

    void addPassword(string name, string app, string pwd)
    {
        name_vect.push_back(name);
        app_vect.push_back(app);
        pass_vect.push_back(pwd);
        cout << "Data added successfully." << endl;
    }

    void showPassword(string app)
    {
        vector<int> matches;

        // FIX: collect all matching app entries
        for (int i = 0; i < app_vect.size(); i++)
        {
            if (app_vect[i] == app)
                matches.push_back(i);
        }

        if (matches.empty())
        {
            cout << "No entry found for this platform." << endl;
            return;
        }

        if (matches.size() == 1)
        {
            int i = matches[0];
            cout << "Username: " << name_vect[i] << endl;
            cout << "Platform: " << app_vect[i] << endl;
            cout << "Password: " << pass_vect[i] << endl;
            return;
        }

        // FIX: duplicate app → ask for username
        string username;
        cout << "Multiple entries found. Enter username: ";
        getline(cin, username);

        for (int i : matches)
        {
            if (name_vect[i] == username)
            {
                cout << "Username: " << name_vect[i] << endl;
                cout << "Platform: " << app_vect[i] << endl;
                cout << "Password: " << pass_vect[i] << endl;
                return;
            }
        }

        cout << "No matching username found for this platform." << endl;
    }

    void listallpassword()
    {
        if (name_vect.empty())
        {
            cout << "No passwords stored yet." << endl;
            return;
        }

        for (int i = 0; i < name_vect.size(); i++)
        {
            cout << "Name: " << name_vect[i] << endl;
            cout << "Platform: " << app_vect[i] << endl;
            cout << "Password: " << pass_vect[i] << endl;
            cout << "-----------------" << endl;
        }
    }

    void wipeout()
    {
        name_vect.clear();
        app_vect.clear();
        pass_vect.clear();
        cout << "Hard reset successful." << endl;
    }

    void updatepassword(string app)
    {
        vector<int> matches;

        // FIX: collect all matching app entries
        for (int i = 0; i < app_vect.size(); i++)
        {
            if (app_vect[i] == app)
                matches.push_back(i);
        }

        if (matches.empty())
        {
            cout << "No entry found for this platform." << endl;
            return;
        }

        int targetIndex;

        if (matches.size() == 1)
        {
            targetIndex = matches[0];
        }
        else
        {
            // FIX: duplicate app → ask for username
            string username;
            cout << "Multiple entries found. Enter username: ";
            getline(cin, username);

            bool found = false;
            for (int i : matches)
            {
                if (name_vect[i] == username)
                {
                    targetIndex = i;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "No matching username found for this platform." << endl;
                return;
            }
        }

        string newpass;
        cout << "Enter new password: ";
        getline(cin, newpass);
        pass_vect[targetIndex] = newpass;

        cout << "Password updated successfully." << endl;
    }
};

int main()
{
    PasswordManager pwd;
    pwd.intro();
    pwd.instructions();

    while (true)
    {
        cout << "\nEnter choice (or press SPACE): ";
        string input;
        getline(cin, input);

        if (input == " ")
        {
            pwd.instructions();
            continue;
        }

        int choice;
        try
        {
            choice = stoi(input);
        }
        catch (...)
        {
            cout << "Invalid input." << endl;
            continue;
        }

        if (choice == 1)
        {
            string name, app, password;
            cout << "Enter username: ";
            getline(cin, name);
            cout << "Enter platform: ";
            getline(cin, app);
            cout << "Enter password: ";
            getline(cin, password);
            pwd.addPassword(name, app, password);
        }
        else if (choice == 2)
        {
            string app;
            cout << "Enter platform name: ";
            getline(cin, app);
            pwd.showPassword(app);
        }
        else if (choice == 3)
        {
            pwd.listallpassword();
        }
        else if (choice == 4)
        {
            pwd.wipeout();
        }
        else if (choice == 5)
        {
            string app;
            cout << "Enter platform name: ";
            getline(cin, app);
            pwd.updatepassword(app);
        }
        else if (choice == 6)
        {
            cout << "Program terminated." << endl;
            break;
        }
        else
        {
            cout << "Please choose a valid option." << endl;
        }
    }

    return 0;
}
