// based on Todd Vanderlin's ofxBox2dJoint class
// class originally written by nay
// modified by PAT

#pragma once

#include "ofMain.h"
#include "Box2D.h"
#include "ofxBox2dUtils.h"

class ofxBox2dRevoluteJoint {
    
public:
    b2World * world;
    b2Joint * joint;
    bool alive;
    b2RevoluteJointDef jd;
    b2Body * body2;
    
    ofxBox2dRevoluteJoint();
    
    void destroyJoint();
    
    void addJoint(b2World * _w, b2Body * _bod1, b2Body * _bod2, b2RevoluteJointDef _jd, b2Vec2 _anchor);
    
    void draw(int alpha=200);
    
    b2Vec2 getAnchorA();
    b2Vec2 getBodyBPos();
    float getTheta();
};