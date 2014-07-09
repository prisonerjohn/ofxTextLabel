//
//  ofxFontUtils.h
//  ofxFontUtils
//
//  Created by Elie Zananiri on 2014-07-09.
//
//

#pragma once

#include "ofMain.h"

//--------------------------------------------------------------
template<typename T>
void ofxFontStringToLines(T& font, const string& str, float lineLength, vector<string>& textLines, ofRectangle& textBounds, float lineSpacing = 1.0f)
{
    textLines.clear();
    
    vector<string> lines = ofSplitString(str, "\n", true, true);
    for (int i = 0; i < lines.size(); i++) {
        vector<string> words = ofSplitString(lines[i], " ", true, true);
        
        if (words.empty()) continue;
        
        string currLine = "";
        int w = 0;
        while (w < words.size()) {
            if (currLine.empty()) {
                // Add a first word to the line, regardless of length.
                currLine = words[w];
                w++;
            }
            else if (font.stringWidth(currLine + " " + words[w]) < lineLength) {
                // It fits, add another word to the line.
                currLine += " " + words[w];
                w++;
            }
            else {
                // It doesn't fit, add a new line and try again.
                textLines.push_back(currLine);
                currLine = "";
            }
        }
        
        // Add the last computed line.
        textLines.push_back(currLine);
    }
    
    // Calculate the bounds.
    textBounds.width = 0;
    textBounds.height = font.getLineHeight() * lineSpacing * (textLines.size() - 1);
    for (int i = 0; i < textLines.size(); i++) {
        textBounds.width = MAX(textBounds.width, font.stringWidth(textLines[i]));
        if (i == textLines.size() - 1) {
            textBounds.height += font.stringHeight(textLines[i]);
        }
    }
}

//--------------------------------------------------------------
template<typename T>
void ofxFontDrawLines(T& font, vector<string>& textLines, ofRectangle& textBounds, const ofRectangle& drawBounds, float lineSpacing = 1.0f, ofAlignHorz alignHorz = OF_ALIGN_HORZ_LEFT, ofAlignVert alignVert = OF_ALIGN_VERT_TOP)
{
    if (alignHorz == OF_ALIGN_HORZ_LEFT) {
        textBounds.x = drawBounds.x;
    }
    else if (alignHorz == OF_ALIGN_HORZ_CENTER) {
        textBounds.x = drawBounds.x + (drawBounds.width - textBounds.width) / 2.0f;
    }
    else {  // (alignHorz == OF_ALIGN_HORZ_RIGHT)
        textBounds.x = drawBounds.x + drawBounds.width - textBounds.width;
    }
    if (alignVert == OF_ALIGN_VERT_TOP) {
        textBounds.y = drawBounds.y;
    }
    else if (alignVert == OF_ALIGN_VERT_CENTER) {
        textBounds.y = drawBounds.y + (drawBounds.height - textBounds.height) / 2.0f;
    }
    else {  // (alignVert == OF_ALIGN_VERT_BOTTOM)
        textBounds.y = drawBounds.y + drawBounds.height - textBounds.height;
    }
    
    float lineX, lineY;
    ofRectangle lineBounds;
    for (int i = 0; i < textLines.size(); i++) {
        lineBounds = font.getStringBoundingBox(textLines[i], 0, 0);
        if (alignHorz == OF_ALIGN_HORZ_LEFT) {
            lineX = textBounds.x;
        }
        else if (alignHorz == OF_ALIGN_HORZ_CENTER) {
            lineX = textBounds.x + (textBounds.width - lineBounds.width) / 2.0f;
        }
        else {  // (alignHorz == OF_ALIGN_HORZ_RIGHT)
            lineX = textBounds.x + textBounds.width - lineBounds.width;
        }
        lineY = textBounds.y + font.getLineHeight() * lineSpacing * i + lineBounds.height;
        
        font.drawString(textLines[i], lineX, lineY);
    }
}

//--------------------------------------------------------------
template<typename T>
void ofxFontDrawString(T& font, const string& str, const ofRectangle& drawBounds, vector<string>& textLines, ofRectangle& textBounds, float lineSpacing = 1.0f, ofAlignHorz alignHorz = OF_ALIGN_HORZ_LEFT, ofAlignVert alignVert = OF_ALIGN_VERT_TOP)
{
    ofxFontStringToLines(font, str, drawBounds.width, textLines, textBounds, lineSpacing);
    ofxFontDrawLines(font, textLines, textBounds, drawBounds, lineSpacing, alignHorz, alignVert);
}
