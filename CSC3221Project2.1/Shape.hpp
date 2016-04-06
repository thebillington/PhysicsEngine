//
//  Shape.hpp
//  CSC3221Project2.1
//
//  Created by Billy Rebecchi on 06/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <string.h>
#pragma once

using namespace std;

class Shape {
    
    //Public methods that every shape needs
public:
    
    //Fields to hold the tags that a shape can be
    string CIRCLE = "circle";
    string SQUARE = "square";
    
    //Constructor that takes in an x and y value for position, as well as the speed, tag and bounding box
    Shape(float x, float y, float dx, float dy, string type, float boundWidth, float boundHeight);
    
    //Getters for the attributes of the shape
    float getX();
    float getY();
    float getDX();
    float getDY();
    float getBoundWidth();
    float getBoundHeight();
    void setX(float x);
    void setY(float y);
    
    //Returns the type of shape as a string
    string getType();
    
    //Virtual methods to be implemented
    //Collision takes another shape in by pointer and then must find if the shape has collided
    //With another shape depending on the shape that is input
    virtual bool collision(Shape* s) = 0;
    
    //Check if the shape is at the edge of the playing area
    //If so then the method will reverse the direction of the shape
    virtual void move() = 0;
    
    //Method to compute the length of hypotenuse given an x and y value
    float pythagoras(float a, float b) {
        return sqrtf(powf(a, 2) + powf(b, 2));
    }
    
    //Method to set speed of shape
    void setSpeed(float dx, float dy);
    
    //Private variables to store important information about the shape
private:
    //x and y values to store the position of the shape
    float _x;
    float _y;
    
    //dx and dy values to store the speed of the shape
    float _dx;
    float _dy;
    
    //store the type of the shape ie circle, square
    string _type;
    
    //Create two variables to store the width and height of the bounding box
    float _boundWidth;
    float _boundHeight;
};

#endif /* Shape_hpp */
