#include "FlowField.h"

void FlowField::setup(int _width, int _height, int _squareSize) {
    squareSize = _squareSize;
    rows = _width / squareSize;
    cols = _height / squareSize;
    image.allocate(cols, rows, OF_IMAGE_GRAYSCALE);
    pixels = image.getPixels().getData();
}

void FlowField::update() {
    for (int y=0; y<cols; y++) {
        for (int x=0; x<rows; x++) {
            float noiseX = x*xscale+xoff;
            float noiseY = y*yscale+yoff;
            int noiseVal = ofNoise(noiseX, noiseY)*255;
            pixels[y*rows+x] = noiseVal;
        }
    }
    image.update();
    xoff += ofMap(ofNoise(ofGetFrameNum()*0.01), 0, 1, minoff, maxoff);
    yoff += ofMap(ofNoise(ofGetFrameNum()*0.02), 0, 1, minoff, maxoff);
    xscale = ofMap(ofNoise(ofGetFrameNum()*0.01), 0, 1, minscale, maxscale);
    yscale = ofMap(ofNoise(ofGetFrameNum()*0.02), 0, 1, minscale, maxscale);
}

void FlowField::draw() {
    image.draw(0, 0, image.getWidth()*squareSize, image.getHeight()*squareSize);
}

ofPoint FlowField::lookup(ofPoint _position) {
    int x = _position.x / squareSize;
    if (x < 0) x = 0;
    else if (x > rows-1) x = rows-1;
    int y = _position.y / squareSize;
    if (y < 0) y = 0;
    else if (y > cols-1) y = cols-1;
    float theta = ofMap(pixels[y*rows+x], 0, 255, 0, TWO_PI);
    ofPoint _vector = ofPoint(cos(theta), sin(theta));
    return _vector;
}
