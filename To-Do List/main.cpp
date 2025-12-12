#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
void showmenu()
{
    cout << "\n--- To-Do List ---\n";
    cout << "1. Add task\n";
    cout << "2. List tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Exit\n";
    cout << "Choose: ";
}
void listtasks(vector<string> &todos)
{
    if (todos.empty())
    {
        cout << "No Tasks involved!" << endl;
    }
    for (size_t i = 0; i < todos.size(); i++)
    {
        cout << (i + 1) << ". " << todos[i] << endl;
    }
}
int main()
{
    vector<string> todos;
    int choice = 0;
    while (true)
    {
        showmenu();
        cout << "Enter your choice: " << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the task: " << endl;
            string task;
            cin.ignore();
            getline(cin, task);
            if (!task.empty())
            {
                todos.push_back(task);
                cout << "Task added!" << endl;
            }
            else
            {
                cout << "Empty task!" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Your tasks: " << endl;
            listtasks(todos);
        }
        else if (choice == 3)
        {
            cout << "Deleting tasks: " << endl;
            if (todos.empty())
            {
                cout << "Nothing here mate..." << endl;
                continue;
            }
            todos.pop_back();
            cout << "Deleted the last task!" << endl;
        }
        else if (choice == 4)
        {
            cout << "Terminated!" << endl;
            break;
        }
        else
        {
            cout << "Pick Again!" << endl;
        }
    }
    return 0;
}