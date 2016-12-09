#pragma once

#include "ofMain.h"
#include "Enemy.hpp"
#include "Ship.hpp"
#include <vector>
using std::vector;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
        void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // all of the game enemies
        vector<Enemy *> enemies;
    
        // the player ship
        Ship *ship;
    
        // flag when you die
        bool gameOver;
    
        ofTrueTypeFont myfont;
};
