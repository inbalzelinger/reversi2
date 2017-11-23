//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_POINT_H
#define UNTITLED2_POINT_H

#include <iostream>
using namespace std;



class Point {
private:
    int x;
    int y;



    friend ostream &operator <<(ostream &out , const Point &point);

public:

    /**
* function name: Point
* constuctor.
* @param - x - the x value. y - the y value.

**/


    Point(int x , int y);

    /**
* function name: Point
* defult constuctor.
**/

    Point();


    /**
* function name: operator ==
* compare between this point to the given one
*@return boolean.
**/

    bool operator == (const Point &point) const;

    /**
* function name: getX
*@return int
**/

    int getX();

    /**
* function name: getY
*@return int
**/

    int getY();
};



#endif //UNTITLED2_POINT_H
