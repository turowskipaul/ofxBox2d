#include "ofxBox2dRevoluteJoint.h"

ofxBox2dRevoluteJoint::ofxBox2dRevoluteJoint() {
    world = NULL;
    alive = false;
}

void ofxBox2dRevoluteJoint::destroyJoint() {
    world->DestroyJoint(joint);
    joint = NULL;
}

void ofxBox2dRevoluteJoint::addJoint(b2World * _w, b2Body * _bod1, b2Body * _bod2, b2RevoluteJointDef _jd, b2Vec2 _anchor) {
    
    if(_w == NULL) {
        ofLog(OF_LOG_NOTICE, "- not a box2d world -");
        return;
    }
    
    world = _w;
    alive = true;
    
    body2 = _bod2;
//    b2Vec2 anchor = _a->GetWorldCenter();
    
//    b2Vec2 anchor = b2Vec2(_xOffset / OFX_BOX2D_SCALE + _a->GetWorldCenter().x, _yOffset / OFX_BOX2D_SCALE + _a->GetWorldCenter().y);
    jd = _jd;
    jd.Initialize(_bod1, _bod2, _anchor);
    
    //need to override anchor set in Initialize() if you don't want the anchor to be in b2Body a's center
    //(due to reasons I can't figure out!)
//    jd.localAnchorA.Set(_xOffset / OFX_BOX2D_SCALE, _yOffset / OFX_BOX2D_SCALE);
    
    joint = world->CreateJoint(&jd);
}

void ofxBox2dRevoluteJoint::draw(int alpha) {
    
    if(!alive) return;
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, alpha);
    ofSetLineWidth(4);
    
    b2Vec2 p1 = joint->GetAnchorA();
    b2Vec2 p2 = body2->GetPosition();
    
    p1 *= OFX_BOX2D_SCALE;
    p2 *= OFX_BOX2D_SCALE;
    ofLine(p1.x, p1.y, p2.x, p2.y);
    ofDisableAlphaBlending();
    ofPopStyle();
}

b2Vec2 ofxBox2dRevoluteJoint::getAnchorA() {
    b2Vec2 p1 = joint->GetAnchorA();
    p1 *= OFX_BOX2D_SCALE;
    
    return p1;
}

b2Vec2 ofxBox2dRevoluteJoint::getBodyBPos() {
    b2Vec2 p2 = body2->GetPosition();
    p2 *= OFX_BOX2D_SCALE;
    
    return p2;
}

float ofxBox2dRevoluteJoint::getTheta() {
    b2Vec2 p1 = joint->GetAnchorA();
    b2Vec2 p2 = body2->GetPosition();
    
    p1 *= OFX_BOX2D_SCALE;
    p2 *= OFX_BOX2D_SCALE;
    
    b2Vec2 tempVec = p2 - p1;
    float tempTheta = atan2(tempVec.y, tempVec.x);
    
    return tempTheta;
}







