//
//  ofxTextLabel.h
//  ofxTextLabel
//
//  Created by Elie Zananiri on 2014-07-10.
//
//

#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
template<typename T>
class ofxTextLabel_
{
public:
    static void stringToLines(T& font, const string& str, float lineLength, vector<string>& textLines, ofRectangle& textBounds, float lineSpacing = 1.0f);
    static void drawLines(T& font, vector<string>& textLines, ofRectangle& textBounds, const ofRectangle& drawBounds, float lineSpacing = 1.0f, ofAlignHorz alignHorz = OF_ALIGN_HORZ_LEFT, ofAlignVert alignVert = OF_ALIGN_VERT_TOP);
    static void drawString(T& font, const string& str, const ofRectangle& drawBounds, vector<string>& textLines, ofRectangle& textBounds, float lineSpacing = 1.0f, ofAlignHorz alignHorz = OF_ALIGN_HORZ_LEFT, ofAlignVert alignVert = OF_ALIGN_VERT_TOP);
    
    ofxTextLabel_();
    ~ofxTextLabel_();
    
    void setup(T * font, const string& text, float lineLength, float lineSpacing = 1.0f, ofAlignHorz alignHorz = OF_ALIGN_HORZ_LEFT, ofAlignVert alignVert = OF_ALIGN_VERT_TOP);
    void setup(T * font, const string& text, const ofRectangle& drawBounds, float lineSpacing = 1.0f, ofAlignHorz alignHorz = OF_ALIGN_HORZ_LEFT, ofAlignVert alignVert = OF_ALIGN_VERT_TOP);
    
    virtual void rebuild();
    virtual void update();
    virtual void draw();
    
    void setFont(T * font);
    T * getFont() { return _font; }
    
    void setText(const string& text);
    const string& getText() { return _text; }
    
    void setLineLength(float lineLength);
    float getLineLength() { return _drawBounds.width; }
    
    void setDrawBounds(const ofRectangle& drawBounds);
    const ofRectangle& getDrawBounds() {  return _drawBounds; }
    
    void setLineSpacing(float lineSpacing);
    float getLineSpacing() { return _lineSpacing; }

    void setAlignHorz(ofAlignHorz alignHorz);
    ofAlignHorz getAlignHorz() { return _alignHorz; }
    
    void setAlignVert(ofAlignVert alignVert);
    ofAlignVert getAlignVert() { return _alignVert; }
    
    const vector<string>& getTextLines() { return _textLines; }
    const ofRectangle& getTextBounds() { return _textBounds; }
    
    bool isDirty() { return _bDirty; }
    
protected:
    T * _font;
    string _text;
    ofRectangle _drawBounds;
    
    float _lineSpacing;
    ofAlignHorz _alignHorz;
    ofAlignVert _alignVert;
        
    vector<string> _textLines;
    ofRectangle _textBounds;
    
    bool _bDirty;
};

//--------------------------------------------------------------
typedef ofxTextLabel_<ofTrueTypeFont> ofxTextLabel;

// Include the cpp so that we can use the template with non-core font types.
// Make sure not to include the cpp in the target sources!
#include "ofxTextLabel.cpp"
