#include "ofApp.h"

#include <algorithm>

//--------------------------------------------------------------
void ofApp::setup(){
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
    
    gameOver = false;
    
    
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
    for (auto & enemy : enemies){
        enemy.move();
    }
    
//    if (ofDist(enemy.x, enemy.y, ship.x, ship.y) < 60){
//        for (auto & enemy : enemies)
//        {
//            gameOver = true;
//        }
//    }
    
    if ( std::any_of(enemies.begin(), enemies.end(), [this](Enemy enemy){return ofDist(enemy.x, enemy.y, ship.x, ship.y) < 60;})){
        
        gameOver = true;

    }
    
    std::remove_if(enemies.begin(), enemies.end(), [this](Enemy enemy){return enemy.x < -30;});
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray,ofColor(30,10,30), OF_GRADIENT_CIRCULAR);
    if(gameOver){
        myfont.drawString("gameover", 100,100);
    }else {
        for (auto enemy : enemies){
            enemy.draw();
        }
        ship.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
