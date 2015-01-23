//
//  ofxTextLabelFbo.cpp
//  textLabelExample
//
//  Created by Elie Zananiri on 1/23/15.
//
//

#include "ofxTextLabelFbo.h"

//--------------------------------------------------------------
template<typename T>
ofxTextLabelFbo_<T>::ofxTextLabelFbo_()
: ofxTextLabel_<T>()
{
    
}

//--------------------------------------------------------------
template<typename T>
ofxTextLabelFbo_<T>::~ofxTextLabelFbo_()
{
    
}

//--------------------------------------------------------------
template<typename T>
void ofxTextLabelFbo_<T>::rebuild()
{
    ofxTextLabel_<T>::rebuild();
    
    // Set the height based on the text height, if necessary.
    if (this->_drawBounds.height == 0) {
        this->_drawBounds.height = this->_textBounds.height;
    }
    
    // Reallocate the FBO if necessary.
    float totalWidth = this->_drawBounds.x * 2 + this->_drawBounds.width;
    float totalHeight = this->_drawBounds.y * 2 + this->_drawBounds.height;
    if (_fbo.getWidth() != totalWidth || _fbo.getHeight() != totalHeight) {
        _fboSettings.width = totalWidth;
        _fboSettings.height = totalHeight;
		_fboSettings.internalformat = GL_RGBA;
        _fbo.allocate(_fboSettings);
    }
    
    _fbo.begin();
    {
        ofClear(_clearColor.r, _clearColor.g, _clearColor.b, 0);
        
        ofPushStyle();
        ofSetColor(255);
		ofEnableBlendMode(OF_BLENDMODE_ADD);
        
        ofxTextLabel_<T>::draw();
        
        ofDisableAlphaBlending();
        ofPopStyle();
    }
    _fbo.end();
}

//--------------------------------------------------------------
template<typename T>
void ofxTextLabelFbo_<T>::draw()
{
    _fbo.draw(0, 0);
}

//--------------------------------------------------
template<typename T>
#if OF_VERSION_MINOR > 8
void ofxTextLabelFbo_<T>::draw(float x, float y) const
#else
void ofxTextLabelFbo_<T>::draw(float x, float y)
#endif
{
    _fbo.draw(x, y);
}

//--------------------------------------------------
template<typename T>
#if OF_VERSION_MINOR > 8
void ofxTextLabelFbo_<T>::draw(float x, float y, float w, float h) const
#else
void ofxTextLabelFbo_<T>::draw(float x, float y, float w, float h)
#endif
{
    _fbo.draw(x, y, w, h);
}

//--------------------------------------------------------------
template<typename T>
void ofxTextLabelFbo_<T>::setLineLength(float lineLength)
{
    setLineLength(lineLength, this->_drawBounds.x, this->_drawBounds.y);
}

//--------------------------------------------------------------
template<typename T>
void ofxTextLabelFbo_<T>::setLineLength(float lineLength, float paddingX, float paddingY)
{
    // Always rebuild because we can't tell if the height has changed or not.
    this->_drawBounds.set(paddingX, paddingY, lineLength, 0);
    this->_bDirty = true;
}

//--------------------------------------------------------------
template<typename T>
void ofxTextLabelFbo_<T>::setDrawBounds(const ofRectangle& drawBounds)
{
    if (this->_drawBounds != drawBounds) {
        this->_drawBounds = drawBounds;
        this->_bDirty = true;
    }
}
