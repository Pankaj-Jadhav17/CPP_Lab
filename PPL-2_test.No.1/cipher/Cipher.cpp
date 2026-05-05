#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;

class Cipher {
private:
    int shift;
    string originalText;
    string resultText;
    char shiftChar(char c, int s) const;
public:
    Cipher(const string& text, int shiftValue);
    string encrypt();
    string decrypt();

    int getShift() const;
    string getOriginalText() const;
    string getResultText()   const;

    void display(const string& mode) const;
};
#endif