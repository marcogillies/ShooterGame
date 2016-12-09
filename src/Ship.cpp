//
//  Ship.cpp
//  ShooterGame2
//
//  Created by Marco Gillies on 09/10/2015.
//
//

#include "Ship.hpp"

// set x to a constant but
// write some code to calcualate y and color
Ship::Ship(): x(50){
    y = ofGetHeight()/2;
    // Set the initial color
    color.set( 255, 255, 255);
}

// draw the ship (very boring, just a circle)
void Ship::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle( x, y, 30);
}


/*
 * Move the ship (called when the keys are pressed)
 */
void Ship::up()
{
    y -= 10;
}


void Ship::down()
{
    y += 10;
}
