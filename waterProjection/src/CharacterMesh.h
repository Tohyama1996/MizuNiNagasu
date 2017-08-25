#pragma once
#include "ofMain.h"

class CharacterMesh {
public:
    CharacterMesh();
    //CharacterMesh(vector<ofPoint> _positions, ofPoint _linePosition);
    CharacterMesh(vector<ofPoint> _positions,
                  ofColor _color,
                  ofPoint _linePosition,
                  float _friction = 0.005f,
                  float _maxspeed = 10.0f);
    //~CharacterMesh();
    void update(ofPoint* _accelerations, Boolean _damping);
    void draw();
    void checkBorders();
    int getVertexNum();
    void eraceVertex(int _num);
    
    int vertexNum;
    ofPoint* positions;
    ofPoint* velocities;
    float friction;
    float maxspeed;
    ofFloatColor* colors;
    int limitMax = 1200;
    int limit = limitMax;
};
