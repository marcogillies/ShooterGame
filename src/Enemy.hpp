//
//  Ball.hpp
//  ShooterGame2
//
//  Created by Marco Gillies on 08/10/2015.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "ofMain.h"


class Enemy {

    // Properties
    int x;
    int y;
    ofColor color;
    
public:
    
    // Constructor
    Enemy(int _x, int _y);    
    // Methods
    void move(); // move the enemy forward
    void draw(); // draw the enemy
    
    //getters
    int getX() const { return x;};
    int getY() const {return y;};

};

#endif /* Enemy_hpp */
