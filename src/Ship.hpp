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
    
public:
    // Properties
    int x;
    int y;
    ofColor color;

    // Constructor
    Ship();
    
    // Methods
    void draw();
    
    void up();
    void down();
    
};

#endif /* Ship_hpp */
