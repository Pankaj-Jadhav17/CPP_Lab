#include "Cipher.h"
#include <iostream>
#include <cctype>

using namespace std;

Cipher::Cipher(const string& text, int shiftValue)
    : shift(shiftValue), originalText(text), resultText("") {}

char Cipher::shiftChar(char c, int s) const {
    if (!isalpha(static_cast<unsigned char>(c)))
        return c;

    int norm = ((s % 26) + 26) % 26;

    if (isupper(c))
        return 'A' + (c - 'A' + norm) % 26;
    else
        return 'a' + (c - 'a' + norm) % 26;
}

string Cipher::encrypt() {
    resultText.clear();
    for (char c : originalText)
        resultText += shiftChar(c, shift);
    return resultText;
}

string Cipher::decrypt() {
    resultText.clear();
    for (char c : originalText)
        resultText += shiftChar(c, -shift);
    return resultText;
}

int Cipher::getShift() const { return shift; }
string Cipher::getOriginalText() const { return originalText; }
string Cipher::getResultText() const { return resultText; }

void Cipher::display(const string& mode) const {
    cout << "\nMode: " << mode << endl;
    cout << "Shift: " << shift << endl;
    cout << "Original: " << originalText << endl;
    cout << "Result: " << resultText << endl;
}