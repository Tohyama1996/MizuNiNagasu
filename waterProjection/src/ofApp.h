#pragma once
#include "ofMain.h"
#include "SecondApp.h"
#include "ofxTrueTypeFontUC.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void draw();
    void keyPressed(int key);
    int checkByte();
    void keyJudge(int key);
    
    shared_ptr<SecondApp> secondApp;
    
    ofxTrueTypeFontUC font;
    int fontSize = 24;
    ofVec2f linePosition;
    string line;
    string consonant;
    string newChar;
    Boolean completed;
    Boolean doubleConsonant;
    int charByte;
};
