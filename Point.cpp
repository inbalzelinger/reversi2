//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "Point.h"

#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x , int y): x(x) , y(y){}

Point::Point(): x(-1) , y(-1) {}


int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}



ostream &operator <<(ostream &out , const Point &point) {
    out <<"(" << point.x <<"," << point.y <<")";
        return out;
    }



bool Point::operator ==(const Point &point) const {
    return (this->x == point.x && this->y == point.y);

}
