//
//  Shape.cpp
//  CSC3221Project2
//
//  Created by Billy Rebecchi on 05/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#include "Shape.hpp"

//Constructor to take 4 inputs and set the x and y values, as well as the speed, tag and bounding box
Shape::Shape(float x, float y, float dx, float dy, string type, float boundWidth, float boundHeight) {
    
    //Initialise all of the class variables
    _x = x;
    _y = y;
    _dx = dx;
    _dy = dy;
    _type = type;
    _boundWidth = boundWidth;
    _boundHeight = boundHeight;
    
}

//Getters to return the x, y values of the shape
float Shape::getX() {
    return _x;
}
float Shape::getY() {
    return _y;
}
float Shape::getDX() {
    return _dx;
}
float Shape::getDY() {
    return _dy;
}
float Shape::getBoundWidth() {
    return _boundWidth;
}
float Shape::getBoundHeight() {
    return _boundHeight;
}
string Shape::getType() {
    return _type;
}

//Setters to set x and y values
void Shape::setX(float x) {
    _x = x;
}
void Shape::setY(float y) {
    _y = y;
}

//Method to change the speed of the shape
void Shape::setSpeed(float dx, float dy) {
    _dx = dx;
    _dy = dy;
}