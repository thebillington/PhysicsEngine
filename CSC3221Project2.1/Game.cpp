//
//  main.cpp
//  CSC3221Project2.1
//
//  Created by Billy Rebecchi on 06/12/2015.
//  Copyright © 2015 Billy Rebecchi. All rights reserved.
//

#include "Square.hpp"
#include "Circle.hpp"
#include <iostream>
#include <iomanip>

//Create two variables to store the height and width of the playing area
int BOUND_WIDTH = 800;
int BOUND_HEIGHT = 600;

//Create two fields to store the number of boxes and number of circles
int noOfBoxes;
int noOfCircles;

int main(int argc, const char * argv[]) {
    
    //Generate a random number for the number of boxes and the number of circles
    noOfBoxes = rand() % 40;
    noOfCircles = rand() % 40;
    
    //Create an empty square and circle array, with the number of squares and the number of circles
    Square *sq [noOfBoxes];
    Circle *c [noOfCircles];
    
    //Count how many shapes there are in total
    int shapesLeft = noOfBoxes + noOfCircles;
    
    //Change these values to change the multipliers for the speed and size of the shapes
    int speedMult = 20;
    int speedAdd = 10;
    int sizeMult = 100;
    int sizeAdd = 50;
    
    //For 0 to the max(noOfBoxes, noOfCircles) iterate through each array and create a new shape
    //Confines are the x and y value must be less than the bounds, the dx and dy values must be between -10 and 10
    //The width/height/radius must be between 50 and 150
    for(int i = 0; i < max(noOfBoxes, noOfCircles); i++) {
        if( noOfBoxes > i) {
            sq[i] = new Square(rand() % BOUND_WIDTH, rand() % BOUND_HEIGHT, (rand() % speedMult) - speedAdd, (rand() % speedMult) - speedAdd, (rand() % sizeMult) + sizeAdd, (rand() % sizeMult) + sizeAdd, BOUND_WIDTH, BOUND_HEIGHT);
            cout << sq[i]->getData() << " created\n\n";
        }
        if(noOfCircles >i) {
            c[i] = new Circle(rand() % BOUND_WIDTH, rand() % BOUND_HEIGHT, (rand() % speedMult) - speedAdd, (rand() % speedMult) - speedAdd, rand() % sizeMult + sizeAdd, BOUND_WIDTH, BOUND_HEIGHT);
            cout << c[i]->getData() << " created\n\n";
        }
    }
    
    //While the number of shapes left is greater than 1, keep moving shapes then checking collision
    while (shapesLeft > 1) {
        
        //Check all the boxes with all the boxes and circles, and all the circles and circles
        for(int i = 0; i < max(noOfBoxes, noOfCircles); i++) {
            if( noOfBoxes > i && sq[i] != NULL) {
                for(int j = i + 1; j < max(noOfBoxes, noOfCircles); j++) {
                    //Check all the boxes with boxes
                    if( noOfBoxes > j && sq[i] != NULL && sq[j] != NULL) {
                        //If there is a collision set both the variables in the array to NULL and ignore
                        //them on further iterations
                        if(sq[i]->collision(sq[j])) {
                            cout << "Collision between:\nß\n" <<sq[i]->getData() << "\n  &\n" << sq[j]->getData() << "\n\n";
                            sq[i] = NULL;
                            sq[j] = NULL;
                            cout << "Square " << i << " and Square " << j << " deleted.\n\n";
                            shapesLeft -= 2;
                        }
                    }
                    //Check all the boxes with circles
                    if(noOfCircles > j && sq[i] != NULL && c[j] != NULL) {
                        //If there is a collision set both the variables in the array to NULL and ignore
                        //them on further iterations
                        if(sq[i]->collision(c[j])) {
                            cout << "Collision between:\n\n" << sq[i]->getData() << "\n  &\n" << c[j]->getData() << "\n\n";
                            sq[i] = NULL;
                            c[j] = NULL;
                            cout << "Square " << i << " and Circle " << j << " deleted.\n\n";
                            shapesLeft -= 2;
                        }
                    }
                }
            }
            //Check all the circles with circles
            if(noOfCircles >i && c[i] != NULL) {
                for(int j = i + 1; j < noOfCircles; j++) {
                    if(noOfCircles > j && c[i] != NULL && c[j] != NULL) {
                        //If there is a collision set both the variables in the array to NULL and ignore
                        //them on further iterations
                        if(c[i]->collision(c[j])) {
                            cout << "Collision between:\n\n" << c[i]->getData() << "\n  &\n" <<c[j]->getData() << "\n\n";
                            c[i] = NULL;
                            c[j] = NULL;
                            cout << "Circle " << i << " and Circle " << j << " deleted.\n\n";
                            shapesLeft -= 2;
                        }
                    }
                }
            }
        }
        
        //For loop to move every shape
        for(int i = 0; i < max(noOfBoxes, noOfCircles); i++) {
            if( noOfBoxes > i && sq[i] != NULL) {
                sq[i]->move();
            }
            if(noOfCircles >i && c[i] != NULL) {
                c[i]->move();
            }
        }
    }
}
