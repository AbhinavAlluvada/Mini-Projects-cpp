#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string filename;
    cout << "Enter filename: " << endl;
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Some error!" << endl;
        return 1;
    }
    int linecount = 0;
    int wordcount = 0;
    int charcount = 0;
    string line;
    while (getline(file, line))
    {
        linecount++;

        charcount += line.size();
        bool inWord = false;
        for (char c : line)
        {
            if (isspace(c))
            {
                inWord = false;
            }
            else if (!inWord)
            {
                wordcount++;
                inWord = true;
            }
        }
    }
    file.close();

    cout << "\n--- File Analysis Result ---\n";
    cout << "Lines: " << linecount << endl;
    cout << "Words: " << wordcount << endl;
    cout << "Characters: " << charcount << endl;

    return 0;
}