#include "Cipher.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void printMenu() {
    cout << "\n--- Caesar Cipher ---\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "3. Demo\n";
    cout << "4. Exit\n";
    cout << "Choice: ";
}

void runDemo() {
    cout << "\n--- Demo ---\n";

    Cipher c1("Hello World", 3);
    c1.encrypt();
    c1.display("ENCRYPT (+3)");

    Cipher c2("Khoor Zruog", 3);
    c2.decrypt();
    c2.display("DECRYPT (+3)");
}

int main() {
    int choice;

    while (true) {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 4) break;
        if (choice == 3) {
            runDemo();
            continue;
        }

        string text;
        int shift;

        cout << "Enter text: ";
        getline(cin, text);

        cout << "Enter shift: ";
        cin >> shift;
        cin.ignore();

        Cipher cipher(text, shift);

        if (choice == 1) {
            cipher.encrypt();
            cipher.display("ENCRYPT");
        } else if (choice == 2) {
            cipher.decrypt();
            cipher.display("DECRYPT");
        } else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}