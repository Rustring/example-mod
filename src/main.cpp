#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/CCDrawNode.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/CCTextInputNode.hpp>

using namespace geode::prelude;

   class $modify(MyMenuLayer, MenuLayer) {    // This right here creates a button on the main menu, showing the mod is active
	bool init() 
		if (!MenuLayer::init()) {
			return false;
		}

		log::debug("Hello from my MenuLayer::init hook! This layer has {} children.", this->getChildrenCount());
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);
		myButton->setID("my-button"_spr);
		menu->updateLayout();
		return true;
	}

	void onMyButton(CCObject*) {
		FLAlertLayer::create("Geode", "Rustring Example Mod is active.", "Ok")->show();
	}
    };


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


    class $modify(GameManager) {    // Icon Hack
        static void onModify(auto& self) {
            GameManager::isColorUnlocked;
            GameManager::isIconUnlocked;
        }

        bool isColorUnlocked(int key, UnlockType type) {
            if (GameManager::isColorUnlocked(key, type))
                return true;
        }

        bool isIconUnlocked(int key, IconType type) {
            if (GameManager::isIconUnlocked(key, type))
                return true;

            return config::get<bool>("bypass.unlockicons", false);
        }
    };
