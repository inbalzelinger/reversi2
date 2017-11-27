//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "Point.h"

#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int row , int col): row(row) , col(col){}

Point::Point(): row(-1) , col(-1) {}


int Point::getRow(){
    return this->row;
}

int Point::getCol() {
    return this->col;
}



ostream &operator <<(ostream &out , const Point &point) {
    out <<"(" << point.row <<"," << point.col <<")";
        return out;
    }



bool Point::operator ==(const Point &point) const {
    return (this->row == point.row && this->col == point.col);

}
