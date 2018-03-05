#pragma once
#include "ofMain.h"
#define ACC1 0.02
#define PIRAD 3.141592
#define THICK 1
#define LEN 1
#define HBOND 3
#define NOFP 10
//1塩基の長さ

class testApp : public ofBaseApp{

public:

    void setup();
	void update();
	void draw();  
    
    void draw_1();
    void draw_2();
    void draw_3();
    void draw_4();

    void update_1();
    void update_2();
    void update_3();
    void update_4();
    
    void var_init();
    void myHelix(double x1, double y1, double z1, double x2, double y2, double z2, double pitch);
    
    char phase;
    char camla;
    bool helix;

    //座標
    double p1[4][3];
    double w1[3][3];
    
    //ペプチド合成のための座標
    double pp1[2][3];
    
    //破裂するparticle
    double bp[NOFP][3];
    double bv[NOFP][3];

    
    //カメラのインスタンス
    ofEasyCam cam;
    //Lightのinstance
    ofLight light;

    void keyPressed  (int key);
    

};
/*
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
*/		
//};
