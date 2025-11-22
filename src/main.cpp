using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		if (Mod::get()->getSettingValue<bool>("enabled")) {
			if (!this->getChildByID("geode.loader/download-mods-here")) {
				if (auto bottomMenu = this->getChildByID("bottom-menu")) {
					auto geodeBtn = bottomMenu->getChildByID("geode.loader/geode-button");

					if (auto downloadModsHereSpr = CCSprite::createWithSpriteFrameName("geode.loader/download-mods-here.png")) {
						if (Mod::get()->getSettingValue<std::string>("id") == "geode.loader") {
							downloadModsHereSpr->setID("geode.loader/download-mods-here");
						}

						else if (Mod::get()->getSettingValue<std::string>("id") == "cmds.download-mods-here-forever") {
							downloadModsHereSpr->setID("download-mods-here"_spr);
						}
						
						if (!Mod::get()->getSettingValue<bool>("fix")) {
							downloadModsHereSpr->setPosition(this->convertToNodeSpace(geodeBtn->convertToWorldSpace(CCPointZero) + CCPoint(75.f, 55.f)));
						}

						if (Mod::get()->getSettingValue<bool>("fix")) {
							downloadModsHereSpr->setPosition(this->convertToNodeSpace(geodeBtn->convertToWorldSpace(CCPointZero) + CCPoint(std::max(10.f, 75.f - bottomMenu->getChildrenCount() * 8.f), 55.f)));
						}
						downloadModsHereSpr->setScale(0.8f);
						this->addChild(downloadModsHereSpr);
					}
				}
			}
		}

		return true;
	}
};