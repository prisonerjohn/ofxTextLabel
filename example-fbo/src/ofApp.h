//
//  ofApp.h
//  ofxTextLabel
//
//  Created by Elie Zananiri on 2014-07-09.
//
//

#pragma once

#include "ofMain.h"
#include "ofxTextLabelFbo.h"

//--------------------------------------------------------------
class ofApp
: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    float lineSpacing;
    string sampleText;
    
    ofTrueTypeFont font;
    
    ofAlignHorz alignHorz;
    ofAlignVert alignVert;
        
    ofxTextLabelFbo textLabelFbo;
};
