//
//  Circle.cpp
//  CSC3221Project2.1
//
//  Created by Billy Rebecchi on 06/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#include "Circle.hpp"
#include "Square.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

//Create a new circle, and call the super method setting the tag of shape equal to CIRCLE
Circle::Circle(float x, float y, float dx, float dy, float radius, float boundWidth, float boundHeight) : Shape(x, y, dx, dy, "circle", boundWidth, boundHeight) {
    _radius = radius;
    
    //Check if the circle is outside the bounds of the play area (this is possible as
    //a 0 value can be taken for the midpoint), if so move it to origin
    if ( getX() - getRadius() < 0 || getX() + getRadius() > boundWidth ) {
        cout << getData() << " created out of bounds\n";
        setX(getRadius());
    }
    if ( getY() - getRadius() < 0 || getY() + getRadius() > boundHeight ) {
        cout << getData() << " created out of bounds\n";
        setY(getRadius());
    }

}

//Return the radius of the circle
float Circle::getRadius() {
    return _radius;
}

bool Circle::collision(Shape* s) {
    //Check the type of the shape to compare to
    //If circle then check if there is a circle-circle collision
    if (!s->getType().compare(CIRCLE)) {
        
        //If the shape is another circle then cast to circle
        Circle* c = static_cast<Circle*>(s);
        
        //Then do a collision detection
        if(pythagoras( fabs (getX() - c->getX()), fabs(getY() - c->getY())) < getRadius() + c->getRadius()) {
            return true;
        }
        return false;
    }
    //If square then check if there is a square-circle collision
    if(!s->getType().compare(SQUARE)) {
        
        //If the shape is a square then cast to square
        Square* sq = static_cast<Square*>(s);
        
        //In the diagram below E is inside the square, B D F H are alongside the square and are nearest an edge
        // A C G I are nearest the corner of the square
        
        // A|B|C
        // -+-+-
        // D|E|F
        // -+-+-
        // G|H|I
        
        //Check if the centre of the circle is within the bounds of the square
        //In the above diagram this would mean the centre of the circle is within the box E
        if ((getX() > sq->getX() - (sq->getWidth() / 2) && getX() < sq->getX() + (sq->getWidth() / 2)) && (getY() > sq->getY() - (sq->getHeight() / 2) && getY() < sq->getY() + (sq->getHeight() / 2))) {
            cout << "HERE";
            return true;
        }
        
        //Check if the centre of the circle is above, below, or next to the square
        //Do this by checking if the x value is within the width of the square but outside the height
        //Or is the y value inside the height of the square but outside the width
        //In the diagram above this would mean the centre of the circle is either in B D F or H
        
        //The number of methods could have been reduced improving efficiency by including the check for above/below and the check
        //for left/right in one if statement, halving the number of tests required
        
        //However for readibility of the code I have kept this split up as the nested if statements were starting to look
        //even more complicated than they already are
        
        //Check if the centre of the circle is above the square in position B
        if ((getX() > sq->getX() - (sq->getWidth() / 2) && getX() < sq->getX() + (sq->getWidth() / 2)) && getY() > sq->getY() + (sq->getHeight() / 2)) {
            //Check if the circle overlaps the top of the square
            if(fabs(getY() - sq->getY()) < (getRadius()) + (sq->getHeight()/2)) {
                return true;
            }
        }
        //Check if the centre of the circle is below the square in position H
        if ((getX() > sq->getX() - (sq->getWidth() / 2) && getX() < sq->getX() + (sq->getWidth() / 2)) && getY() < sq->getY() - (sq->getHeight() / 2)) {
            //Check if the circle overlaps the bottom of the square
            if(fabs(getY() - sq->getY()) < (getRadius()) + (sq->getHeight()/2)) {
                return true;
            }
        }
        //Check if the centre of the circle is left of the square in position D
        if ((getY() > sq->getY() - (sq->getHeight() / 2) && getY() < sq->getY() + (sq->getHeight() / 2)) && getX() < sq->getX() - (sq->getWidth() / 2)) {
            //Check if the circle overlaps the left of the square
            if(fabs(getX() - sq->getX()) < (getRadius()) + (sq->getWidth()/2)) {
                return true;
            }
        }
        //Check if the centre of the circle is right of the square in position D
        if ((getY() > sq->getY() - (sq->getHeight() / 2) && getY() < sq->getY() + (sq->getHeight() / 2)) && getX() > sq->getX() + (sq->getWidth() / 2)) {
            //Check if the circle overlaps the right of the square
            if(fabs(getX() - sq->getX()) < (getRadius()) + (sq->getWidth()/2)) {
                return true;
            }
        }
        
        //Check if the centre of the circle is diagonally above or below the square
        //Do this by checking if the x and y values are below and/or above the perimeter
        //values of the square
        //In the diagram above this would mean the centre of the circle lies in A C G I
        
        //Then check whether the distance between the centre point of the circle and the corner of the square that
        //it is closest to is less than the radius.
        
        //Check if the centre of the circle is left of and above the square
        if( ( getX() < sq->getX() - (sq->getWidth() / 2) ) && ( getY() < sq->getY() - (sq->getHeight() / 2) ) ) {
            //Check if the distance from the circle midpoint to the top left corner of the square is less than the radius
            if ( pythagoras ( abs(getX() - ( sq->getX() - (sq->getWidth()/2)) ) , abs(getY() - ( sq->getY() - (sq->getHeight()/2)) ) ) < getRadius() ) {
                return true;
            }
        }
        
        //Check if the centre of the circle is right of and above the square
        if( ( getX() > sq->getX() + (sq->getWidth() / 2) ) && ( getY() < sq->getY() - (sq->getHeight() / 2) ) ) {
            //Check if the distance from the circle midpoint to the top right corner of the square is less than the radius
            if ( pythagoras ( abs(getX() - ( sq->getX() + (sq->getWidth()/2)) ) , abs(getY() - ( sq->getY() - (sq->getHeight()/2)) ) ) < getRadius() ) {
                return true;
            }
        }
        
        //Check if the centre of the circle is left of and below the square
        if( ( getX() < sq->getX() - (sq->getWidth() / 2) ) && ( getY() > sq->getY() + (sq->getHeight() / 2) ) ) {
            //Check if the distance from the circle midpoint to the bottom left corner of the square is less than the radius
            if ( pythagoras ( abs(getX() - ( sq->getX() - (sq->getWidth()/2)) ) , abs(getY() - ( sq->getY() + (sq->getHeight()/2)) ) ) < getRadius() ) {
                return true;
            }
        }
        
        //Check if the centre of the circle is right of and below the square
        if( ( getX() > sq->getX() + (sq->getWidth() / 2) ) && ( getY() > sq->getY() + (sq->getHeight() / 2) ) ) {
            //Check if the distance from the circle midpoint to the bottom right corner of the square is less than the radius
            if ( pythagoras ( abs(getX() - ( sq->getX() + (sq->getWidth()/2)) ) , abs(getY() - ( sq->getY() + (sq->getHeight()/2)) ) ) < getRadius() ) {
                return true;
            }
        }

    }
    return false;
}

//Method to move the square by dx/dy, check if it has hit an edge and if so reverse direction
void Circle::move() {
    
    //Check where the shape will be after the move
    float newX = getX() + getDY();
    float newY = getY() + getDY();
    
    //If the x value of the shape is outside the bounds then reverse the x speed
    if ( newX - getRadius() < 0 || newX + getRadius() > getBoundWidth() ) {
        cout << getData() << " out of bounds\n";
        setSpeed(-getDX(), getDY());
        setX(getRadius());
    }
    //Otherwise set the value of x
    else {
        setX(newX);
    }
    
    //If the y value of the shape is outside the bounds then reverse the y speed
    if ( getY() - getRadius() < 0 || getY() + getRadius() > getBoundHeight() ) {
        cout << getData() << " out of bounds\n";
        setSpeed(getDX(), -getDY());
        setY(getRadius());
    }
    //Othersie set the y value
    else {
        setY(newY);
    }
}




//Method to return data about circle as a JSON style string
string Circle::getData() {
    //Create a new oStringStream
    ostringstream stream;
    
    //Set stream precision to 6 digits (not fixed i.e 10 will not be written as 10.00)
    //Then return the stream as a string
    stream << std::setprecision(6) << "Circle: {x: " << getX() << ", y:" << getY() << ", dx:" << getDX() <<", dy:" << getDY() << ", radius:" << getRadius() << "}";
    return stream.str();
}