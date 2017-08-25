#pragma once
#include "ofMain.h"
#include "ofEventUtils.h"
#include "ofxTrueTypeFontUC.h"
#include "CharacterMesh.h"
#include "FlowField.h"

class SecondApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void pushString(string _line);
    
    FlowField field;
    ofxTrueTypeFontUC font;
    int fontSize = 42;
    ofVec2f linePosition;
    float resampleLength = 0.5;
    
    ofVboMesh vboMesh;
    vector<CharacterMesh> meshes;
    int vertexNumAll = 0;
    int vertexNumMax = 100000;
    float forceMag;
    float forceMagMin = 0.001;
    float forceMagMax = 0.1;
    
    ofSerial serial;
    string serialPort = "/dev/cu.usbmodem14411";
    Byte serialData;
    string serialState;
    
    Boolean debugMode = false;
};
