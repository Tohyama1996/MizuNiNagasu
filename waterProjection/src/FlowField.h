#pragma once
#include "ofMain.h"

class FlowField {
public:
    void setup(int _width, int _height, int _resolution);
    void update();
    void draw();
    ofPoint lookup(ofPoint _position);
    
    ofImage image;
    unsigned char* pixels;
    int squareSize;
    int rows;
    int cols;
    float xoff;
    float yoff;
    float minoff = -0.01;
    float maxoff = 0.01;
    float xscale;
    float yscale;
    float minscale = 0.004;
    float maxscale = 0.005;
};
