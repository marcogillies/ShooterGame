//
//  Ship.hpp
//  ShooterGame2
//
//  Created by Marco Gillies on 09/10/2015.
//
//

#ifndef Ship_hpp
#define Ship_hpp

#include "ofMain.h"

#include <stdio.h>


class Ship {
    

    // Postion and colour
    int x;
    int y;
    ofColor color;

public:
    
    // Constructor
    Ship();
    
    // Methods
    void draw();
    
    // move the ship
    // called when the keys are pressed
    void up();
    void down();
    
    //getters
    int getX(){return x;};
    int getY(){return y;};
    
};

#endif /* Ship_hpp */
