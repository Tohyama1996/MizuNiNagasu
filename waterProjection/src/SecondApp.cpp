#include "SecondApp.h"

void SecondApp::setup(){
    ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0);
    
    vboMesh.setMode(OF_PRIMITIVE_POINTS);
    
    field.setup(ofGetWidth(), ofGetHeight(), 2);
    
    font.load("NotoSansCJKjp-Regular.otf", fontSize, true, true);
    
    ofColor _color = ofColor::fromHsb(255,0,255,100);
    vector<ofPoint> _positions;
    for (int i=0; i<10000; i++) {
        _positions.push_back(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
    meshes.push_back(CharacterMesh(_positions, _color, linePosition, 0.001, 3.0));
    vertexNumAll = meshes[0].getVertexNum();
    
    if (serial.setup(serialPort, 9600)) {
        cout << "serial found" << endl;
    } else {
        cout << "no serial found" << endl;
    }
}

void SecondApp::update(){
    if (serial.isInitialized() && serial.available()) {
        serialData = serial.readByte();
        if (serialData == 1) {
            forceMag = forceMagMax;
            serialState = "HIGH";
        } else {
            forceMag = forceMagMin;
            serialState = "LOW";
        }
        serial.flush();
    } else {
        forceMag = forceMagMin;
        serialState = "no serial";
    }
    //cout << serialState << endl;
    
    
    field.update();
    
    vboMesh.clear();
    
    for (int i=0; i<meshes.size(); i++) {
        ofPoint* _acceleration = new ofPoint[meshes[i].getVertexNum()];
        for (int j=0; j<meshes[i].getVertexNum(); j++) {
            ofPoint _position = meshes[i].positions[j] + linePosition;
            _acceleration[j] = field.lookup(_position) * forceMag;
        }
        if (i == 0) meshes[i].update(_acceleration, false);
        else meshes[i].update(_acceleration, true);
        meshes[i].checkBorders();
        delete[] _acceleration;
        
        if (meshes[i].limit > 0) {
            vboMesh.addColors(meshes[i].colors, meshes[i].vertexNum);
            vboMesh.addVertices(meshes[i].positions, meshes[i].vertexNum);
        } else {
            vertexNumAll -= meshes[i].vertexNum;
            meshes.erase(meshes.begin() + i);
        }
    }
}

void SecondApp::draw(){
    if (debugMode) field.draw();
    vboMesh.draw();
    if (debugMode) {
        ofDrawBitmapStringHighlight("vertices : " + ofToString(vertexNumAll), 10, 15);
        ofDrawBitmapStringHighlight("sensor : " + serialState, 10, 30);
    }
}

void SecondApp::mousePressed(int x, int y, int button) {
    debugMode = !debugMode;
}

void SecondApp::pushString(string _line) {
    linePosition = ofVec2f(ofGetWidth()/2 - font.stringWidth(_line)/2 , ofGetHeight()/2);
    linePosition += ofVec2f(ofRandom(-50,50), ofRandom(-200,200));
    
    ofColor _color = ofColor::fromHsb(ofRandom(130,180),127,255);
    //ofColor _color = ofColor::fromHsb(130,100,255);
    //ofColor _color = ofColor::fromHsb(180,100,255);
    
    vector<ofPath> _path = font.getStringAsPoints(_line);
    for (int i=0; i<_path.size(); i++) {
        vector<ofPolyline> _polyline = _path[i].getOutline();
        for (int j=0; j<_polyline.size(); j++) {
            _polyline[j] = _polyline[j].getResampledBySpacing(resampleLength);
            meshes.push_back(CharacterMesh(_polyline[j].getVertices(), _color, linePosition));
        }
    }
    
    vertexNumAll = 0;
    for (int i=0; i<meshes.size(); i++) {
        vertexNumAll += meshes[i].getVertexNum();
    }
    
    while (vertexNumAll > vertexNumMax) {
        vertexNumAll -= meshes[1].vertexNum;
        meshes.erase(meshes.begin()+1);
        if (vertexNumAll <= vertexNumMax) break;
    }
}
