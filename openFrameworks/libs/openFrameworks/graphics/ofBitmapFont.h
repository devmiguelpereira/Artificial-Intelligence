#pragma once

#include "ofConstants.h"
#include "ofRectangle.h"
#include "ofPixels.h"
#include "ofTexture.h"
class ofMesh;
class ofRectangle;

/*
 
 note, the data in this code is taken from freeglut, and included in OF for compatability 
 with non glut windowing toolkits.  see .cpp for license info
 
 also, note that while this is used internally in ofGraphics, it's not really useful for end user usage.
 
 */

class ofBitmapFont{
public:
	ofBitmapFont();
	~ofBitmapFont();
	ofMesh getMesh(const string & text, int x, int y, ofDrawBitmapMode mode=OF_BITMAPMODE_MODEL_BILLBOARD, bool vFlipped=true) const;
	const ofTexture & getTexture() const;
	ofRectangle getBoundingBox(const string & text, int x, int y) const;
private:
	static void init();
	static ofPixels pixels;
	void unloadTexture();
	mutable ofTexture texture;
};