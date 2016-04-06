//
//  Square.hpp
//  CSC3221Project2.1
//
//  Created by Billy Rebecchi on 06/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#ifndef Square_hpp
#define Square_hpp

#include <iostream>
#include "Shape.hpp"
#pragma once

using namespace std;

class Square: public Shape {
    
    //Public methods to be accessed from our game class
public:
    
    //Constructor that takes the information required for a shape, plus a width and height for a square
    Square(float x, float y, float dx, float dy, float width, float height, float boundWidth, float boundHeight);
    
    //Getters to return the width and height of the shape
    float getWidth();
    float getHeight();    
    //Define the collision and move functions as per parent class
    bool collision(Shape* s);
    void move();
    
    //Method to return data about a square as JSON style string
    string getData();
    
    //Private fields to store the width and height of each square
private:
    float _width;
    float _height;
};

#endif /* Square_hpp */
