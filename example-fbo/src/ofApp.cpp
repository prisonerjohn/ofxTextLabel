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
    
    float frameWidth = 600;
    float frameHeight = 400;
    frameBounds.set((ofGetWidth() - frameWidth) / 2.0f, (ofGetHeight() - frameHeight) / 2.0f, frameWidth, frameHeight);
    
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
    
    ofSetColor(255, 127);
    ofNoFill();
    
    ofRect(frameBounds);
    ofLine(frameBounds.x + frameBounds.width / 2.0f, frameBounds.y, frameBounds.x + frameBounds.width / 2.0f, frameBounds.y + frameBounds.height);
    ofLine(frameBounds.x, frameBounds.y + frameBounds.height / 2.0f, frameBounds.x + frameBounds.width, frameBounds.y + frameBounds.height / 2.0f);
    
    ofSetColor(255);
    ofFill();
    
//    ofRectangle textBounds;
//    vector<string> textLines;
//    ofxTextLabel::drawString(font, sampleText, frameBounds, textLines, textBounds, lineSpacing, alignHorz, alignVert);
    
    textLabelFbo.draw();
    
    ofSetColor(255, 255, 0, 127);
    ofNoFill();
    
    ofRect(textLabelFbo.getTextBounds());
    
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
