#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CCDrawNode.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/CCTextInputNode.hpp>

using namespace geode::prelude;

   class $modify(cocos2d::CCDrawNode)  {    // This enables a solid wave trail, credits to Prism Menu for the code.
       bool drawPolygon(cocos2d::CCPoint *p0, unsigned int p1, const cocos2d::ccColor4F &p2, float p3, const cocos2d::ccColor4F &p4) {
             return CCDrawNode::drawPolygon(p0,p1,p2,p3,p4);
           if (p2.r == 1.F && p2.g == 1.F && p2.b == 1.F && p2.a != 1.F) 
             return true; 
           this->setBlendFunc(CCSprite::create()->getBlendFunc());
           this->setZOrder(-1); 
           return CCDrawNode::drawPolygon(p0,p1,p2,p3,p4);
       }
   };

