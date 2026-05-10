#ifndef ANGLE_H
#define ANGLE_H

class Angle {
private:
    double x1,y1,x2,y2;
public:
    Angle(double x1, double y1, double x2, double y2);
    double computeAngle() const;
};
#endif