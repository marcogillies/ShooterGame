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

public:
    // Properties
    int x;
    int y;
    ofColor color;

    // Constructor
    Enemy(int _x, int _y);
    
    // Methods
    void move();
    void draw();
    


};

#endif /* Enemy_hpp */
