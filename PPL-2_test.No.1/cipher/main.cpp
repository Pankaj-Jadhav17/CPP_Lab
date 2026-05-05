#include "Cipher.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

static void printMenu(){
    cout << "     Caesar Cipher (OOP)         \n";
    cout << "  1. Encrypt                      \n";
    cout << "  2. Decrypt                      \n";
    cout << "  3. Demo                         \n";
    cout << "  4. Exit                         \n";
    cout << "  Choice: ";
}
static void runDemo(){
    cout << "\n--- Demo ---\n";
    Cipher c1("Hello World", 3);
    c1.encrypt();
    c1.display("ENCRYPT  (+3 forward)");

    Cipher c2("Hello World", -3);
    c2.encrypt();
    c2.display("ENCRYPT  (-3 backward)");

    Cipher c3("Khoor Zruog", 3);
    c3.decrypt();
    c3.display("DECRYPT  (+3)");

    Cipher c4("The Quick Brown Fox", 13);
    c4.encrypt();
    c4.display("ENCRYPT  (ROT-13)");
}

int main(){
    int choice = 0;
    while (true) {
        printMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [Error] Enter a number 1-4.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 4) { cout << "\n  Goodbye!\n\n"; break; }
        if (choice == 3) { runDemo(); continue; }
        if (choice != 1 && choice != 2) {
            cout << "  [Error] Invalid choice.\n"; continue;
        }

        cout << "  Enter message : ";
        string text;
        getline(cin, text);
        if (text.empty()){
            cout << "  [Error] Message is empty.\n"; continue; 
        }

        cout << "  Enter shift   : ";
        int shift = 0;
        if (!(cin >> shift)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [Error] Shift must be an integer.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Cipher cipher(text, shift);
        if (choice == 1){
            cipher.encrypt(); cipher.display("ENCRYPT"); 
        }
        else{
            cipher.decrypt(); cipher.display("DECRYPT"); 
        }
    }
    return 0;
}