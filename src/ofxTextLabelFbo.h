//
//  ofxTextLabelFbo.h
//  textLabelExample
//
//  Created by Elie Zananiri on 1/23/15.
//
//

#pragma once

#include "ofMain.h"
#include "ofxTextLabel.h"

//--------------------------------------------------------------
template<typename T>
class ofxTextLabelFbo_
: public ofxTextLabel_<T>
, public ofBaseDraws
{
public:
    ofxTextLabelFbo_();
    ~ofxTextLabelFbo_();
    
    virtual void rebuild();
    virtual void draw();
    
#if OF_VERSION_MINOR > 8
    virtual void draw(float x, float y) const;
    virtual void draw(float x, float y, float w, float h) const;
    virtual float getHeight() const { return _fbo.getHeight(); }
    virtual float getWidth() const { return _fbo.getWidth(); }
#else
    virtual void draw(float x, float y);
    virtual void draw(float x, float y, float w, float h);
    virtual float getHeight() { return _fbo.getHeight(); }
    virtual float getWidth() { return _fbo.getWidth(); }
#endif
    
    virtual void setLineLength(float lineLength);
    void setLineLength(float lineLength, float paddingX, float paddingY);
    
    virtual void setDrawBounds(const ofRectangle& drawBounds);
    
    void setClearColor(const ofColor& clearColor);
    const ofColor& getClearColor() { return _clearColor; }
    
    ofFbo& getFbo() { return _fbo; }
    
protected:
    ofFbo _fbo;
    ofFbo::Settings _fboSettings;
    ofColor _clearColor;
};

//--------------------------------------------------------------
typedef ofxTextLabelFbo_<ofTrueTypeFont> ofxTextLabelFbo;

// Include the cpp so that we can use the template with non-core font types.
// Make sure not to include the cpp in the target sources!
#include "ofxTextLabelFbo.cpp"
