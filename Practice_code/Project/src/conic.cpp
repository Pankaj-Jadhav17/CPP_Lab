#include "conic.h"
#include <cmath>
static bool isZero(double x) { return std::abs(x) < 1e-9; }
std::string classifyConic(double a, double b, double c, double h, double g, double f) {
    double delta = a*(b*c - f*f) - h*(h*c - g*f) + g*(h*f - b*g);
    double J = a*b - h*h;

    if (!isZero(delta)) {
        if (J > 1e-9) {
            if (isZero(a - b) && isZero(h)) return "circle";
            return "ellipse";
        }
        if (isZero(J)) return "parabola";
        return "hyperbola";
    } else {
        if (J > 1e-9)  return "two imaginary lines";
        if (isZero(J)) return "two real parallel lines";
        return "two real intersecting lines";
    }
}
