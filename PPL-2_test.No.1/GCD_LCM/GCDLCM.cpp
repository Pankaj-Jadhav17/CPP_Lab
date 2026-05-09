#include "GCDLCM.h"
using namespace std;

GCDLCM::GCDLCM(int a, int b) {
    this->a = a;
    this->b = b;
}
int GCDLCM::findGCD() const {
    int x = a;
    int y = b;

    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}
int GCDLCM::findLCM() const {
    int gcd = findGCD();
    return (a * b) / gcd;
}
