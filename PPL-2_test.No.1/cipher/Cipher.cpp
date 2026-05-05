#include "Cipher.h"
#include <iostream>
#include <cctype>
using namespace std;

Cipher::Cipher(const string& text, int shiftValue) : shift(shiftValue), originalText(text), resultText("") {}
char Cipher::shiftChar(char c, int s) const{
    if (!isalpha(static_cast<unsigned char>(c)))
        return c;

    int norm = ((s % 26) + 26) % 26;
    if (isupper(static_cast<unsigned char>(c)))
        return static_cast<char>('A' + (c - 'A' + norm) % 26);
    else
        return static_cast<char>('a' + (c - 'a' + norm) % 26);
}

string Cipher::encrypt(){
    resultText.clear();
    for (char c : originalText)
        resultText += shiftChar(c, shift);
    return resultText;
}

string Cipher::decrypt(){
    resultText.clear();
    for (char c : originalText)
        resultText += shiftChar(c, -shift);
    return resultText;
}
int Cipher::getShift() const { return shift; }
string Cipher::getOriginalText() const { return originalText; }
string Cipher::getResultText()   const { return resultText; }

void Cipher::display(const string& mode) const
{
    cout << "  Mode:" << mode << "\n";
    cout << "  Shift:" << shift << (shift >= 0 ? "(forward / right)" : "  (backward / left)") << "\n";
    cout << "  Original:" << originalText << "\n";
    cout << "  Result:" << resultText   << "\n";
    
}