//
//  Ball.cpp
//  ShooterGame2
//
//  Created by Marco Gillies on 08/10/2015.
//
//

#include "Enemy.hpp"

// set the position from parameters
// and the colour at random
Enemy::Enemy(int _x, int _y): x(_x), y(_y){
    // Set the initial color
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
}

// just constantly move left
void Enemy::move(){
    x -= 1;
}

// draw the enemy (very boring, just a circle)
void Enemy::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle( x, y, 30);
}
