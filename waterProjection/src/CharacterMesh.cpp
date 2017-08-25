#include "CharacterMesh.h"

CharacterMesh::CharacterMesh() {
    
}

/*
CharacterMesh::CharacterMesh(vector<ofPoint> _positions, ofPoint _linePosition) {
    vertexNum = _positions.size();
    positions = new ofPoint[vertexNum];
    velocities = new ofPoint[vertexNum];
    colors = new ofFloatColor[vertexNum];
    for (int i=0; i<vertexNum; i++) {
        positions[i] = _positions[i] + _linePosition;
        colors[i] = ofColor(255);
    }
}
*/

CharacterMesh::CharacterMesh(vector<ofPoint> _positions,
                             ofColor _color,
                             ofPoint _linePosition,
                             float _friction,
                             float _maxspeed) {
    
    vertexNum = _positions.size();
    positions = new ofPoint[vertexNum];
    velocities = new ofPoint[vertexNum];
    colors = new ofFloatColor[vertexNum];
    for (int i=0; i<vertexNum; i++) {
        positions[i] = _positions[i] + _linePosition;
        colors[i] = _color;
    }
    friction = _friction;
    maxspeed = _maxspeed;
    
}

/*
CharacterMesh::~CharacterMesh() {
    delete &positions;
    delete &velocities;
    delete &colors;
}
*/

void CharacterMesh::update(ofPoint* _accelerations, Boolean _damping) {
    for (int i=0; i<vertexNum; i++) {
        velocities[i] += _accelerations[i] - velocities[i]*friction;
        velocities[i].limit(maxspeed);
        positions[i] += velocities[i];
        if (_damping) colors[i].a = ofMap(limit, 0, limitMax, 0, 1);
    }
    if (_damping) limit--;
}

void CharacterMesh::checkBorders() {
    int minx = 0;
    int miny = 0;
    int maxx = ofGetWidth();
    int maxy = ofGetHeight();
    
    for (int i=0; i<vertexNum; i++) {
        if (positions[i].x < minx) positions[i].x += maxx;
        if (positions[i].y < miny) positions[i].y += maxy;
        if (positions[i].x > maxx) positions[i].x -= maxx;
        if (positions[i].y > maxy) positions[i].y -= maxy;
    }
    
    /*
    for (int i=0; i<vertexNum; i++) {
        if (positions[i].x < minx) velocities[i].x *= -1;
        if (positions[i].y < miny) velocities[i].y *= -1;
        if (positions[i].x > maxx) velocities[i].x *= -1;
        if (positions[i].y > maxy) velocities[i].y *= -1;
    }
    */
}

int CharacterMesh::getVertexNum() {
    return vertexNum;
}

void CharacterMesh::eraceVertex(int _num) {
    for (int i=0; i<vertexNum-1; i++) {
        if (i >= _num) {
            positions[i] = positions[i+1];
            velocities[i] = velocities[i+1];
            colors[i] = colors[i+1];
        }
    }
    vertexNum--;
}
