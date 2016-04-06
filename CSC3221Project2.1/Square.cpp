//
//  Square.cpp
//  CSC3221Project2.1
//
//  Created by Billy Rebecchi on 06/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#include "Square.hpp"
#include "Circle.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>


using namespace std;

//Create a new square, and call the super method setting the tag of shape equal to SQUARE
Square::Square(float x, float y, float dx, float dy, float width, float height, float boundWidth, float boundHeight) : Shape(x, y, dx, dy, "square", boundWidth, boundHeight) {
    _width = width;
    _height = height;
    
    //Check if the square is outside the bounds of the play area (this is possible as
    //a 0 value can be taken for the midpoint), if so move it to the top left corner
    if ( getX() - (getWidth()/2) < 0 || getX() + (getWidth()/2) > boundWidth ) {
        cout << getData() << " created out of bounds\n";

        setX(getWidth()/2);
    }
    if ( getY() - (getHeight()/2) < 0 || getY() + (getHeight()/2) > boundHeight ) {
        cout << getData() << " created out of bounds\n";
        setY(getHeight()/2);
    }
}

//Getters to return the width and height of the square
float Square::getWidth() {
    return _width;
}
float Square::getHeight() {
    return _height;
}

//Method to check for the collision of this square with another shape
bool Square::collision(Shape* s) {
    
    //Check the type of the shape to compare to
    if (!s->getType().compare(SQUARE)) {
        
        //If the shape is another square then cast to square
        Square* sq = static_cast<Square*>(s);
        
        //Then do a collision detection
        if (fabs(getX() - sq->getX()) < (getWidth()/2) + (sq->getWidth()/2) && fabs(getY() - sq->getY()) < (getHeight()/2) + (sq->getHeight()/2)) {
            return true;
        }
        return false;
    }
    
    //Check the type of the shape to compare to
    if (!s->getType().compare(CIRCLE)) {
        //If the shape is a circle then cast to square
        Circle* c = static_cast<Circle*>(s);
        
        //Then call the circle collision method on this shape to test for collision of circle-square
        //This method does all the collision detection for square-circle to save rewriting the same logic
        return c->collision(this);
    }
    
    return false;
}

//Method to move the square by dx/dy, check if it has hit an edge and if so reverse direction
void Square::move() {
    
    //Check where the shape will be after the move
    float newX = getX() + getDY();
    float newY = getY() + getDY();
    
    //If the x value of the shape is outside the bounds then reverse the x speed
    if ( newX - (getWidth()/2) < 0 || newX + (getWidth()/2) > getBoundWidth() ) {
        cout << getData() << " out of bounds\n";
        setSpeed(-getDX(), getDY());
        setX(getWidth() / 2);
    }
    //Otherwise set the value of x
    else {
        setX(newX);
    }
    
    //If the y value of the shape is outside the bounds then reverse the y speed
    if ( getY() - (getHeight()/2) < 0 || getY() + (getHeight()/2) > getBoundHeight() ) {
        cout << getData() << " out of bounds\n";
        setSpeed(getDX(), -getDY());
        setY(getHeight()/2);
    }
    //Othersie set the y value
    else {
        setY(newY);
    }
}

//Method to return data about square as a JSON style string
string Square::getData() {
    //Create a new oStringStream
    ostringstream stream;
    
    //Set stream precision to 6 digits (not fixed i.e 10 will not be written as 10.00)
    //Then return the stream as a string
    stream << std::setprecision(6) << "Square: {x: " << getX() << ", y:" << getY() << ", dx:" << getDX() <<", dy:" << getDY() << ", width:" << getWidth() << ", height:" << getHeight() << "}";
    return stream.str();
}