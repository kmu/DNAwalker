#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(100);

    ofSetBackgroundAuto(FALSE);

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofBackgroundHex(0xffffff);
    //glEnable(GL_DEPTH_TEST);
    ofSetLineWidth(2);
    ofEnableSmoothing();

    cam.setDistance(100);

    light.enable();
    light.setSpotlight();
    light.setPosition(100, 100, 100);
    //light.setAmbientColor(ofFloatColor(0.5, 0.2, 0.1,1.0));
    //light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0));
    //light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    light.setAmbientColor(ofFloatColor(1.0, 1.0, 1.0,1.0));
    light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
    light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));

    phase=0;
    helix=FALSE;
    // Start from linear mode
    camla=0;

    var_init();
}

//--------------------------------------------------------------
void testApp::update(){


    if(phase%4==1){
        update_1();
    }
    else if(phase%4==2){
        update_2();
    }
    else if(phase%4==3){
        update_3();
    }
    else if(phase%4==0&&phase!=0){
        update_4();
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    //ofFill();
    //ofSetHexColor(0xFFFFFF);
    //ofSetColor(255, 255, 255, 0.1);

    ofSetColor(256, 256, 256,30);

    // Modern
    ofRect(0,0,ofGetWidth(), ofGetHeight());

    //ofRect(0,0,2000,300);

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);


    cam.begin();

    ofTranslate(-42,0,-10);


    //camera

    ofTranslate(21*((phase-1)/4),0,0);


    ofSetColor(100, 100, 240);

    // The common part
    ofPushMatrix();
    ofTranslate(-21*((phase-1)/4),0,0);
    {
        ofPushMatrix();
        ofTranslate(0,0,3);
        //T
        ofSetColor(0, 0, 0);
        //ofSetColor(255, 255, 255);
        /*if(helix==TRUE){
            myHelix(84, 0,0, 0, 0, 0, 0);
            myHelix(0, 0, 0, 3*7*LEN, 0,0,180);
            ofSetColor(0, 0, 255);
            myHelix(3*7*LEN, 0, 0, 3*7*LEN*2,0 ,0,0);
            ofSetColor(255, 0, 0);
            myHelix(3*7*LEN*2, 0, 0, 3*7*LEN*3,0 ,0,180);
            ofSetColor(0, 255, 0);
            myHelix(3*7*LEN*3, 0, 0, 3*7*LEN*4, 0,0,180);
        }*/
        //else {
            ofLine(0,0,-2,84,0,-2);
            ofLine(0, 0, 0, 3*7*LEN, 0,0);
            ofSetColor(0, 0, 255);
            ofLine(3*7*LEN, 0, 0, 3*7*LEN*2,0 ,0);
            ofSetColor(255, 0, 0);
            ofLine(3*7*LEN*2, 0, 0, 3*7*LEN*3,0 ,0);
            ofSetColor(0, 255, 0);
            ofLine(3*7*LEN*3, 0, 0, 3*7*LEN*4, 0,0);
        //}
        ofPopMatrix();
    }

        // Leg of S0.
        ofSetColor(0, 0, 0);
        ofLine(0,0,HBOND,3*7*LEN, 0,HBOND);

        // Tail of S1.
        ofSetColor(0, 0, 255);
        ofLine(3*7*LEN, 0, HBOND, 3*7*LEN*2,0 ,HBOND);

        // Tail of S2.
        ofSetColor(255, 0, 0);
        ofLine(3*7*LEN*2, 0, HBOND, 3*7*LEN*3,0 ,HBOND);
        //ofLine(3*7*LEN*3, 0,HBOND, 3*7*LEN*3, 0,HBOND+3*6*LEN);
        //ofSphere(3*7*LEN*3, 0, HBOND+3*6*LEN, 1);

        // Tail of S3.
        ofSetColor(0, 255, 0);
        ofLine(3*7*LEN*3, 0, HBOND, 3*7*LEN*4, 0,HBOND);
        //ofLine(3*7*LEN*4, 0,HBOND, 3*7*LEN*4, 0,HBOND+3*6*LEN);
        //ofSphere(3*7*LEN*4, 0, HBOND+3*6*LEN, 1);
        if((phase-1)/4==0){

            // Tower of S2 and reaction center
            ofSetColor(255, 0, 0);
            ofLine(3*7*LEN*3, 0,HBOND, 3*7*LEN*3, 0,HBOND+3*6*LEN);
            ofSphere(3*7*LEN*3, 0, HBOND+3*6*LEN, 1);
            // Head of S2
            ofLine(3*7*LEN*3, 0, HBOND+3*6*LEN, 3*7*LEN*3, 0, HBOND+3*6*LEN+6);
            // Hair of S2
            ofLine(3*7*LEN*3, 0, HBOND+3*6*LEN+6, 3*7*LEN*3+6, 0, HBOND+3*6*LEN+6+6);

            // Tower of S3 and reaction center
            ofSetColor(0, 255, 0);
            ofLine(3*7*LEN*4, 0,HBOND, 3*7*LEN*4, 0,HBOND+3*6*LEN);
            ofSphere(3*7*LEN*4, 0, HBOND+3*6*LEN, 1);
            // Head of S3
            ofLine(3*7*LEN*4, 0, HBOND+3*6*LEN, 3*7*LEN*4, 0, HBOND+3*6*LEN+6);
            // Hair of S3
            ofLine(3*7*LEN*4, 0, HBOND+3*6*LEN+6, 3*7*LEN*4+6, 0, HBOND+3*6*LEN+6+6);

        }
        if((phase-1)/4==1)
        {
            // Tower of S0
            ofSetColor(0, 0, 0);
            ofLine(3*7*LEN, 0,HBOND, 21, 0, 19);


            // Tower of S3 and reaction center
            ofSetColor(0, 255, 0);
            ofLine(3*7*LEN*4, 0,HBOND, 3*7*LEN*4, 0,HBOND+3*6*LEN);
            ofSphere(3*7*LEN*4, 0, HBOND+3*6*LEN, 1);
            // Head of S3
            ofLine(3*7*LEN*4, 0, HBOND+3*6*LEN, 3*7*LEN*4, 0, HBOND+3*6*LEN+6);
            // Hair of S3
            ofLine(3*7*LEN*4, 0, HBOND+3*6*LEN+6, 3*7*LEN*4+6, 0, HBOND+3*6*LEN+6+6);

        }
        if((phase-1)/4==2){
            // Tower of S0
            ofSetColor(0, 0, 0);
            ofLine(3*7*LEN, 0,HBOND, 21, 0, 19);

            // Leg of S1
            ofSetColor(0, 0, 255);
            ofLine(3*7*LEN*2, 0,HBOND,42,0,19);
        }

    ofPopMatrix();

    if(phase==0){
        draw_1();
    }
    else if(phase%4==1){
        draw_1();
    }
    else if(phase%4==2){
        draw_2();
    }
    else if(phase%4==3){
        draw_3();
    }
    else if(phase%4==0&&phase!=0){
        draw_4();
    }

    if(camla==1){
        ofVec3f pos;
        pos.x=p1[0][0]-42+((phase-1)/4*21);
        pos.y=p1[0][1];
        pos.z=p1[0][2]-10;
        //cam.lookAt(pos);

        cam.setTarget(pos);

        //cout << pos <<endl;

        cam.setDistance(40);
    }

    cam.end();
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='k'){
        phase++;

        if(phase==4){
            // Goal
            /*pp1[0][0]=p1[0][0]+1-1;
            pp1[0][1]=p1[0][1];
            pp1[0][2]=p1[0][2]+1.5+6+1;*/

            // Connection with peptide
            pp1[1][0]=p1[1][0];
            pp1[1][1]=p1[1][1];
            pp1[1][2]=p1[1][2]+6;

            for(int i=0;i<NOFP;i++){
                for(int j=0;j<3;j++){
                    bv[i][j]=ofRandom(-0.5,0.5);
                }
            }
        }
        else if(phase==8){


            // Connection with peptide
            pp1[1][0]=p1[1][0];
            pp1[1][1]=p1[1][1];
            pp1[1][2]=p1[1][2]+6;

            for(int i=0;i<NOFP;i++){
                for(int j=0;j<3;j++){
                    bv[i][j]=ofRandom(-0.5,0.5);
                }
            }
        }
        else if(phase==12){


            // Connection with peptide
            pp1[1][0]=p1[1][0];
            pp1[1][1]=p1[1][1];
            pp1[1][2]=p1[1][2]+6;

            for(int i=0;i<NOFP;i++){
                for(int j=0;j<3;j++){
                    bv[i][j]=ofRandom(-0.5,0.5);
                }
            }
        }
        else if(phase==13){
            phase=0;
            var_init();
        }


        else if(phase%4==1){
            var_init();
        }
        else if(phase%4==3){
            p1[4][0]=p1[0][0]+1;
            p1[4][1]=p1[0][1];
            p1[4][2]=p1[0][2]-3;
        }
        // Determine the velocity
        else if(phase%4==0){
            for(int i=0;i<NOFP;i++){
                for(int j=0;j<3;j++){
                    bv[i][j]=ofRandom(-0.5,0.5);
                }
            }
        }

    }

    else if(key=='j'){
        phase--;
    }
    // Whether helix or not
    else if(key=='x'){
        camla++;
    }
    else if(key=='z'){
        camla--;
    }
    else if(key=='q'){
        helix=FALSE;
    }
    else if(key=='w'){
        helix=TRUE;
    }

    else if(key=='c'){
        phase=0;
        var_init();
    }

}

void testApp::draw_1(){

    if(helix==TRUE){
        ofSetColor(255, 255, 255);
        myHelix(3*7*LEN, 0,HBOND, p1[0][0], 0, p1[0][2]-3,0);


        //S1
        ofSetColor(0, 0, 255);

        //Leg of S1
        myHelix(3*7*LEN*2, 0,HBOND,p1[1][0], p1[1][1], p1[1][2],0);



        ofSphere(p1[1][0], p1[1][1], p1[1][2], 1);

        myHelix(p1[1][0], p1[1][1], p1[1][2], p1[1][0], p1[1][1], p1[1][2]+6,0);

        myHelix(p1[1][0], p1[1][1], p1[1][2]+6, p1[1][0]+6, p1[1][1], p1[1][2]+6+6,0);


        //DNA walker init

        //ofSetColor(255, 255, 255);
        //    ofLine(3*7*LEN-HBOND, 0,HBOND+LEN*2,3*7*LEN-HBOND, 0,HBOND+LEN*2+LEN*16);

        //ofSetColor(255, 0, 255);

        //aptamer
        ofSetColor(255, 0, 255);

        //ofLine(p1[0][0], p1[0][1],HBOND+LEN*2+LEN*16-2*LEN,3*7*LEN-HBOND-3*LEN, 0,p1[0][2]);




        myHelix(3*7*LEN-HBOND+0.5+1.5, 0,HBOND+LEN*2-0.5,p1[0][0]-1,p1[0][1],p1[0][2]-1.5,0);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]+3);

        ofLine(p1[0][0]-1-3, p1[0][1], p1[0][2]+3, p1[0][0]-1-3, p1[0][1], p1[0][2]-3);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]-1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]-3);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1,p1[0][1],p1[0][2]+1.5+4.5);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+6.0,p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1);

        switch (phase/4) {
            case 0:
                ofSetColor(255, 0, 0);
                ofLine(p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1,p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6);

                break;
            case 2:
                ofSetColor(0, 255, 0);
                break;
        }
    }
    else{
        switch(phase/4){
            case 0:


                ofSetColor(0, 0, 0);
                break;
            case 1:
                ofSetColor(0, 0, 255);
                break;
            case 2:
                ofSetColor(255, 0, 0);
        }
        ofLine(3*7*LEN, 0,HBOND, p1[0][0], 0, p1[0][2]-3);



        switch (phase/4) {
            case 0:
                ofSetColor(0, 0, 255);
                break;
            case 1:
                ofSetColor(255, 0, 0);
                break;
            case 2:
                ofSetColor(0, 255, 0);
            default:
                break;
        }



        ofLine(3*7*LEN*2, 0,HBOND,p1[1][0], p1[1][1], p1[1][2]);



        ofSphere(p1[1][0], p1[1][1], p1[1][2], 1);

        ofLine(p1[1][0], p1[1][1], p1[1][2], p1[1][0], p1[1][1], p1[1][2]+6);

        ofLine(p1[1][0], p1[1][1], p1[1][2]+6, p1[1][0]+6, p1[1][1], p1[1][2]+6+6);




        ofSetColor(255, 255, 255);





        ofSetColor(255, 0, 255);











        ofLine(3*7*LEN-HBOND+0.5+1.5, 0,HBOND+LEN*2-0.5,p1[0][0]-1,p1[0][1],p1[0][2]-1.5);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]+3);

        ofLine(p1[0][0]-1-3, p1[0][1], p1[0][2]+3, p1[0][0]-1-3, p1[0][1], p1[0][2]-3);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]-1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]-3);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1,p1[0][1],p1[0][2]+1.5+4.5);

        ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+6.0,p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1);

        if(phase/4>0){
            ofSetColor(0, 0, 255);
            ofLine(p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1,p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6);
        }
        if(phase/4>1){
            ofSetColor(255, 0, 0);
            ofLine(p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6,p1[0][0]+1-1+6*2,p1[0][1],p1[0][2]+6+1+6*2);
        }
    }


}
void testApp::update_1(){

    double force1[3];
    double vel1[3]={0,0,0};

    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    for(int i=0; i<3;i++){
        vel1[i]+=force1[i];
    }

    for(int i=0;i<3;i++){
        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];
    }

    double force2[3];
    double vel2[3]={0,0,0};

    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    for(int i=0; i<3;i++){
        vel1[i]+=force1[i];
    }

    for(int i=0;i<3;i++){
        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];
    }

    for(int i=0;i<3;i++){
        w1[1][i]=18.0/21.0*p1[1][i]+3.0/21.0*w1[0][i];
    }



}

void testApp::draw_2(){


    switch(phase/4){
        case 0:
            ofSetColor(0, 0, 0);
            break;

        case 1:
            ofSetColor(0, 0, 255);
            break;
        case 2:
            ofSetColor(255, 0, 0);
    }
    ofLine(3*7*LEN, 0,HBOND, p1[0][0], 0, p1[0][2]-3);

    switch (phase/4) {
        case 0:
            ofSetColor(0, 0, 255);
            break;
        case 1:
            ofSetColor(255, 0, 0);
            break;
        case 2:
            ofSetColor(0, 255, 0);
        default:
            break;
    }

    ofLine(3*7*LEN*2, 0,HBOND,p1[1][0], p1[1][1], p1[1][2]);

    ofSphere(p1[1][0], p1[1][1], p1[1][2], 1);
    ofLine(p1[1][0], p1[1][1], p1[1][2], p1[1][0], p1[1][1], p1[1][2]+6);
    ofLine(p1[1][0], p1[1][1], p1[1][2]+6, p1[1][0]+6, p1[1][1], p1[1][2]+6+6);


    ofSetColor(255, 255, 255);

    ofSetColor(255, 0, 255);

    ofSetColor(255, 0, 255);



     ofLine(p1[3][0]+1.5, p1[3][1],p1[3][2]-0.5,p1[0][0]-1,p1[0][1],p1[0][2]-1.5);

    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]+3);
    ofLine(p1[0][0]-1-3, p1[0][1], p1[0][2]+3, p1[0][0]-1-3, p1[0][1], p1[0][2]-3);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]-1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]-3);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1,p1[0][1],p1[0][2]+1.5+4.5);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+6.0,p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1);

    if(phase/4>0){
        ofSetColor(0, 0, 255);
        ofLine(p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1,p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6);
    }
    if(phase/4>1){
        ofSetColor(255, 0, 0);
        ofLine(p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6,p1[0][0]+1-1+6*2,p1[0][1],p1[0][2]+6+1+6*2);
    }
}
void testApp::update_2(){


/*    if(phase==1){
        t++;
    }*/
    double force1[3];
    double vel1[3]={0,0,0};

    double force2[3];
    double vel2[3]={0,0,0};

    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    force2[0]=(p1[1][0]-42.0)*0.05;
    force2[1]=(p1[1][1]- 0.0)*0.05;
    force2[2]=(p1[1][2]-21.0)*0.05;


    for(int i=0; i<3;i++){

        vel1[i]+=force1[i];

        vel2[i]+=force2[i];
    }


    for(int i=0;i<3;i++){

        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];


        p1[1][i]-=vel2[i];
    }



    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    for(int i=0; i<3;i++){
        vel1[i]+=force1[i];
    }

    for(int i=0;i<3;i++){
        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];
    }

    for(int i=0;i<3;i++){
        w1[1][i]=18.0/21.0*p1[1][i]+3.0/21.0*w1[0][i];
    }


}

void testApp::draw_3(){

    switch(phase/4){
        case 0:
            ofSetColor(0, 0, 0);
            break;

        case 1:
            ofSetColor(0, 0, 255);
            break;
        case 2:
            ofSetColor(255, 0, 0);
    }

    ofLine(3*7*LEN, 0,HBOND,p1[4][0], p1[4][1],p1[4][2]);

    switch (phase/4) {
        case 0:
            ofSetColor(0, 0, 255);
            break;
        case 1:
            ofSetColor(255, 0, 0);
            break;
        case 2:
            ofSetColor(0, 255, 0);
        default:
            break;
    }

    ofLine(3*7*LEN*2, 0,HBOND,p1[1][0], p1[1][1], p1[1][2]);

    ofSphere(p1[1][0], p1[1][1], p1[1][2], 1);
    ofLine(p1[1][0], p1[1][1], p1[1][2], p1[1][0], p1[1][1], p1[1][2]+6);
    ofLine(p1[1][0], p1[1][1], p1[1][2]+6, p1[1][0]+6, p1[1][1], p1[1][2]+6+6);



    ofSetColor(255, 255, 255);

    ofSetColor(255, 0, 255);

    ofSetColor(255, 0, 255);






    ofLine(p1[3][0], p1[3][1],p1[3][2],p1[0][0]-1,p1[0][1],p1[0][2]-1.5);

    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]+3);
    ofLine(p1[0][0]-1-3, p1[0][1], p1[0][2]+3, p1[0][0]-1-3, p1[0][1], p1[0][2]-3);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]-1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]-3);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1,p1[0][1],p1[0][2]+1.5+4.5);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+6.0,p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1);

    if(phase/4>0){
        ofSetColor(0, 0, 255);
        ofLine(p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1,p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6);
    }
    if(phase/4>1){
        ofSetColor(255, 0, 0);
        ofLine(p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6,p1[0][0]+1-1+6*2,p1[0][1],p1[0][2]+6+1+6*2);
    }
}
void testApp::update_3(){

    /*    if(phase==1){
     t++;
     }*/
    double force1[3];
    double vel1[3]={0,0,0};

    double force2[3];
    double vel2[3]={0,0,0};

    double force3[3];
    double vel3[3]={0,0,0};

    double force4[3];
    double vel4[3]={0,0,0};

    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    force2[0]=(p1[1][0]-42.0)*0.05;
    force2[1]=(p1[1][1]- 0.0)*0.05;
    force2[2]=(p1[1][2]-21.0)*0.05;

    force3[0]=(p1[3][0]-p1[0][0]+1)*0.01;
    force3[1]=(p1[3][1]- 0.0)*0.01;
    force3[2]=(p1[3][2]-p1[0][2]+21-4.5)*0.01;

    force4[0]=(p1[4][0]-21.0)*0.01;
    force4[1]=(p1[4][1]- 0.0)*0.01;
    force4[2]=(p1[4][2]-19.0)*0.01;



    for(int i=0; i<3;i++){

        vel1[i]+=force1[i];

        vel2[i]+=force2[i];

        vel3[i]+=force3[i];

        vel4[i]+=force4[i];
    }


    for(int i=0;i<3;i++){

        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];


        p1[1][i]-=vel2[i];


        p1[3][i]-=vel3[i];
        p1[4][i]-=vel4[i];

    }



    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    for(int i=0; i<3;i++){
        vel1[i]+=force1[i];
    }

    for(int i=0;i<3;i++){
        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];
    }

    for(int i=0;i<3;i++){
        w1[1][i]=18.0/21.0*p1[1][i]+3.0/21.0*w1[0][i];
    }



}

void testApp::draw_4(){

    switch(phase/4-1){
        case 0:
            ofSetColor(0, 0, 0);
            break;
        case 1:
            ofSetColor(0, 0, 255);
            break;
        case 2:
            ofSetColor(255, 0, 0);
    }

    ofLine(3*7*LEN, 0,HBOND,p1[4][0], p1[4][1],p1[4][2]);

    switch (phase/4-1) {
        case 0:
            ofSetColor(0, 0, 255);
            break;
        case 1:
            ofSetColor(255, 0, 0);
            break;
        case 2:
            ofSetColor(0, 255, 0);
            break;
    }
    ofLine(3*7*LEN*2, 0,HBOND,p1[1][0], p1[1][1], p1[1][2]-2);

    for(int i=0;i<NOFP;i++){
        ofSphere(p1[1][0]+bp[i][0], p1[1][1]+bp[i][1],p1[1][2]+bp[i][2],0.1);
    }
0][2]);p1[1][2]+6+6+bp[0][2]);
    switch(phase/4-1){
        case 0:
            ofLine(pp1[1][0],pp1[1][1],pp1[1][2],pp1[1][0]+6,pp1[1][1],pp1[1][2]+6);
            break;
        case 1:
             ofLine(pp1[1][0],pp1[1][1],pp1[1][2],pp1[1][0]+6,pp1[1][1],pp1[1][2]+6);
            break;
        case 2:
            ofLine(pp1[1][0],pp1[1][1],pp1[1][2],pp1[1][0]+6,pp1[1][1],pp1[1][2]+6);
            break;
        default:
            break;
    }




    ofSetColor(255, 0, 255);




    ofLine(p1[3][0], p1[3][1],p1[3][2],p1[0][0]-1,p1[0][1],p1[0][2]-1.5);



    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]+3);
    ofLine(p1[0][0]-1-3, p1[0][1], p1[0][2]+3, p1[0][0]-1-3, p1[0][1], p1[0][2]-3);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]-1.5,p1[0][0]-1-3,p1[0][1],p1[0][2]-3);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+1.5,p1[0][0]-1,p1[0][1],p1[0][2]+1.5+4.5);
    ofLine(p1[0][0]-1,p1[0][1],p1[0][2]+6.0,p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1);

    if(phase/4>1){
        ofSetColor(0, 0, 255);
        ofLine(p1[0][0]+1-1,p1[0][1],p1[0][2]+6+1,p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6);
    }
    if(phase/4>2){
        ofSetColor(255, 0, 0);
        ofLine(p1[0][0]+1-1+6,p1[0][1],p1[0][2]+6+1+6,p1[0][0]+1-1+6*2,p1[0][1],p1[0][2]+6+1+6*2);
    }
}
void testApp::update_4(){

    for(int i=0;i<NOFP;i++){
        for(int j=0;j<3;j++){
            bp[i][j]+=bv[i][j];
        }
    }




    double force1[3];
    double vel1[3]={0,0,0};

    double force2[3];
    double vel2[3]={0,0,0};

    double force3[3];
    double vel3[3]={0,0,0};

    double force4[3];
    double vel4[3]={0,0,0};

    double force5[3];
    double vel5[3];


    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    force2[0]=(p1[1][0]-42.0)*0.01;
    force2[1]=(p1[1][1]- 0.0)*0.01;
    force2[2]=(p1[1][2]-21.0)*0.01;

    force3[0]=(p1[3][0]-p1[0][0]+1)*0.05;
    force3[1]=(p1[3][1]- 0.0)*0.05;
    force3[2]=(p1[3][2]-p1[0][2]+21-4.5)*0.05;

    force4[0]=(p1[4][0]-21.0)*0.05;
    force4[1]=(p1[4][1]- 0.0)*0.05;
    force4[2]=(p1[4][2]-19.0)*0.05;



    pp1[0][0]=p1[0][0]+1-1+6*(phase/4-1);
    pp1[0][1]=p1[0][1];
    pp1[0][2]=p1[0][2]+6+1+6*(phase/4-1);


    for(int i=0;i<3;i++){
        force5[i]=(pp1[1][i]-pp1[0][i])*0.05;



        cout << endl;
    }


    for(int i=0; i<3;i++){

        vel1[i]+=force1[i];

        vel2[i]+=force2[i];

        vel3[i]+=force3[i];

        vel4[i]+=force4[i];

        vel5[i]+=force5[i];
    }


    for(int i=0;i<3;i++){

        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];


        p1[1][i]-=vel2[i];


        p1[3][i]-=vel3[i];
        p1[4][i]-=vel4[i];


        pp1[1][i]-=vel5[i];
    }


    force1[0]=(p1[0][0]-p1[1][0])*0.01;
    force1[1]=(p1[0][1]-p1[1][1])*0.01;
    force1[2]=(p1[0][2]-p1[1][2])*0.01;

    for(int i=0; i<3;i++){
        vel1[i]+=force1[i];
    }

    for(int i=0;i<3;i++){
        p1[0][i]-=vel1[i];
        p1[1][i]+=vel1[i];
    }

    for(int i=0;i<3;i++){
        w1[1][i]=18.0/21.0*p1[1][i]+3.0/21.0*w1[0][i];
    }


}

void testApp::var_init(){
    for(int j=0; j<10; j++){
        for(int i=0; i<3; i++){
            p1[j][i]=0;
            w1[j][i]=0;

        }
    }

    for (int j=0; j<NOFP; j++) {
        for(int i=0;i<3;i++){
            bp[j][i]=0;
            bv[j][i]=0;
        }
    }

    p1[1][0]=3*7*LEN*2;
    p1[1][1]=0;
    p1[1][2]=HBOND+3*6*LEN;


    p1[0][0]=18+1.5;
    p1[0][1]=0;
    p1[0][2]=23-1.5;

    p1[2][0]=15;
    p1[2][1]=0;
    p1[2][2]=25;

    w1[0][0]=18;
    w1[0][1]=0;
    w1[0][2]=4;


    p1[3][0]=3*7*LEN-HBOND+0.5;
    p1[3][1]=0;
    p1[3][2]=HBOND+LEN*2;




}
void testApp::myHelix(double x1, double y1, double z1, double x2, double y2, double z2, double pitch){

    double distance;

    distance=sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));


    ofPushMatrix();

    ofRotateX(pitch);
    ofTranslate(x1,y1,z1);

    /*if(pow((y1-y2),2)+pow(z1-z2,2)!=0){

        ofRotateX(asin((y2-y1)/sqrt((pow((y1-y2),2)+pow(z1-z2,2))))/3.1415*180);
        cout << "X" << acos((y2-y1)/sqrt((pow((y1-y2),2)+pow(z1-z2,2))))/3.1415*180 << ' ';


    }*/

    if(pow((x1-x2),2)+pow(y1-y2,2)!=0){
        //OK
        ofRotateZ(-acos((x2-x1)/sqrt((pow((x1-x2),2)+pow(y1-y2,2))))/3.1415*180);
 //       cout << "Z" <<acos((x2-x1)/sqrt((pow((x1-x2),2)+pow(y1-y2,2))))/3.1415*180 << ' ';
    }
    if(pow((z1-z2),2)+pow(x1-x2,2)!=0){
        ofRotateY(-asin((z2-z1)/sqrt((pow((z1-z2),2)+pow(x1-x2,2))))/3.1415*180);
        //    cout << "Y" << -asin((z2-z1)/sqrt((pow((z1-z2),2)+pow(x1-x2,2))))/3.1415*180 << ' ';
    }


    for(int i=0;i<distance;i++){
        ofLine(i,cos(i),sin(i),i+1,cos(i+1),sin(i+1));
    }

    ofPopMatrix();
}

/*
//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}*/