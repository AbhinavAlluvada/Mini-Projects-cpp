#include <bits/stdc++.h>
using namespace std;

class Chat {
public:
    string message;
    vector<string> enr;

    void display() {
        if (message.empty()) {
            cout << "No message entered!" << endl;
        } else {
            if (!enr.empty()) {
                cout << "Encrypted message: " << endl;
                cout << enr.back() << endl;  // show the latest encrypted version
            } else {
                cout << "Message not yet encrypted!" << endl;
            }
        }
    }

    void encrypter() {
        if (!message.empty()) {
            string encrypted = message;
            char c = 'S';
            for (int i = 0; i < encrypted.length(); i++) {
                encrypted[i] = encrypted[i] ^ c;
            }
            enr.push_back(encrypted);
            cout << "Message successfully encrypted!" << endl;
        } else {
            cout << "Please enter a message first!" << endl;
        }
    }
};

int main() {
    Chat obj;
    cout << "Welcome to MessageEncrypter!" << endl;
    cout << "Let's Begin..." << endl;

    while (true) {
        int choice;
        cout << "\n1. Enter a message" << endl;
        cout << "2. Encrypt the message" << endl;
        cout << "3. Display the encrypted message" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter a message: ";
            getline(cin, obj.message);
            cout << "Message Entered!" << endl;
        } else if (choice == 2) {
            obj.encrypter();
        } else if (choice == 3) {
            obj.display();
        } else if (choice == 4) {
            cout << "Come Again Soon!" << endl;
            break;
        } else {
            cout << "Invalid choice. Try again!" << endl;
        }
    }

    return 0;
}
