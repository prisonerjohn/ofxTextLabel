//
//  ofApp.cpp
//  ofxFontUtils
//
//  Created by Elie Zananiri on 2014-07-09.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    
    ofTrueTypeFont::setGlobalDpi(72);
    font.loadFont("verdana.ttf", 78);
    
    sampleText = "HERE IS SOME AWESOME SAMPLE TEXT";
    lineSpacing = 1.0f;
    
    alignHorz = OF_ALIGN_HORZ_LEFT;
    alignVert = OF_ALIGN_VERT_TOP;
    
    ofRectangle frameBounds(20, 20, 600, 400);
    textLabelFbo.setup(&font, sampleText, frameBounds);
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2) + " FPS");
    
    textLabelFbo.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    
    ofPushMatrix();
    ofTranslate((ofGetWidth() - textLabelFbo.getWidth()) / 2.0f, (ofGetHeight() - textLabelFbo.getHeight()) / 2.0f);
    
    ofSetColor(255, 64);
    ofFill();
    
    ofRect(0, 0, textLabelFbo.getWidth(), textLabelFbo.getHeight());
    ofRect(textLabelFbo.getDrawBounds());
    ofRect(textLabelFbo.getTextBounds());

    ofSetColor(255, 200);
    ofNoFill();
    
    ofLine(textLabelFbo.getDrawBounds().getCenter().x, textLabelFbo.getDrawBounds().getTop(), textLabelFbo.getDrawBounds().getCenter().x, textLabelFbo.getDrawBounds().getBottom());
    ofLine(textLabelFbo.getDrawBounds().getLeft(), textLabelFbo.getDrawBounds().getCenter().y, textLabelFbo.getDrawBounds().getRight(), textLabelFbo.getDrawBounds().getCenter().y);
    
    ofSetColor(255);
    ofFill();

    textLabelFbo.draw();
    
    ofSetColor(255, 255, 0, 127);
    ofNoFill();
    ofSetLineWidth(2.0);
    
    ofRect(textLabelFbo.getTextBounds());
    
    ofPopMatrix();
    
    ofSetColor(255);
    stringstream ss;
    ss << "[h]orizontal align" << endl;
    ss << "[v]ertical align" << endl;
    ss << "[l]ine spacing" << endl;
    ss << "[f]rame width" << endl;
    ofDrawBitmapString(ss.str(), 12, 16);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'h':
            if (textLabelFbo.getAlignHorz() == OF_ALIGN_HORZ_LEFT) textLabelFbo.setAlignHorz(OF_ALIGN_HORZ_CENTER);
            else if (textLabelFbo.getAlignHorz() == OF_ALIGN_HORZ_CENTER) textLabelFbo.setAlignHorz(OF_ALIGN_HORZ_RIGHT);
            else textLabelFbo.setAlignHorz(OF_ALIGN_HORZ_LEFT);
            break;
            
        case 'v':
            if (textLabelFbo.getAlignVert() == OF_ALIGN_VERT_TOP) textLabelFbo.setAlignVert(OF_ALIGN_VERT_CENTER);
            else if (textLabelFbo.getAlignVert() == OF_ALIGN_VERT_CENTER) textLabelFbo.setAlignVert(OF_ALIGN_VERT_BOTTOM);
            else textLabelFbo.setAlignVert(OF_ALIGN_VERT_TOP);
            break;
            
        case 'l':
            textLabelFbo.setLineSpacing(textLabelFbo.getLineSpacing() + 0.1f);
            if (textLabelFbo.getLineSpacing() > 2.0f) textLabelFbo.setLineSpacing(0.2f);
            break;
            
        case 'f':
            textLabelFbo.setLineLength(textLabelFbo.getLineLength() + 50);
            if (textLabelFbo.getLineLength() > 800) textLabelFbo.setLineLength(100);
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
