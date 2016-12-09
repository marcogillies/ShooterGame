#include "ofApp.h"

#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
    
    gameOver = false;
    
    // load in enemy positions from file
    std::ifstream myfile (ofToDataPath("positions.txt").c_str());
    
    int x, y;
    
    if (myfile.is_open())
    {
        while ( myfile >> x >> y)
        {
            enemies.push_back(Enemy(x,y));
        }
        myfile.close();
    } else {
        std::cout << "could not load file" << std::endl;
    }
    
    myfont.loadFont("verdana.ttf", 32);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // move the enemies
    // note the use of a reference
    // so that we are changing the real enemy
    for (auto & enemy : enemies){
        enemy.move();
    }
    
    
    // check if any of the enemies have
    // collided with the player ship
    // if so game over
    if ( std::any_of(enemies.begin(), enemies.end(), [this](Enemy enemy){
        return ofDist(enemy.getX(), enemy.getY(), ship.getX(), ship.getY()) < 60;}))
    {
        
        gameOver = true;

    }
    
    // remove enemies
    auto it = std::remove_if(enemies.begin(), enemies.end(), [this](Enemy enemy){return enemy.getX() < -30;});
    enemies.erase(it, enemies.end());
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray,ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    
    // draw a game over screen if gameOver is true
    // otherwise draw all enemies and
    // the ship
    if(gameOver){
        myfont.drawString("gameover", 100,100);
    }else {
        for (auto &enemy : enemies){
            enemy.draw();
        }
        ship.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // trigger ship movement
    if(key == OF_KEY_UP){
        ship.up();
    }
    if(key == OF_KEY_DOWN){
        ship.down();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
