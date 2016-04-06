//
//  Circle.hpp
//  CSC3221Project2.1
//
//  Created by Billy Rebecchi on 06/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include "Shape.hpp"
#pragma once

using namespace std;

class Circle: public Shape {
    
    //Public methods to be accessed from our game class
public:
    
    //Constructor that takes the information required for a shape, plus a radius for a circle
    Circle(float x, float y, float dx, float dy, float radius, float boundWidth, float boundHeight);
    
    //Getters to return the width and height of the shape
    float getRadius();
    
    //Define the collision and atEdge functions as per parent class
    bool collision(Shape* s);
    void move();
    
    //Method to return data about a circle as JSON style string
    string getData();
    
    //Private fields to store the radius
private:
    float _radius;
};


#endif /* Circle_hpp */
