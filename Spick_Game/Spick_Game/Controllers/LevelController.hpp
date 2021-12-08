#pragma once

#include <any>
#include <filesystem>
#include "API_Headers/Scene.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "API_Headers/Engine.hpp"
#include "../Behaviourscripts/ChangeSceneBehaviour.hpp"
#include "../Behaviourscripts/Player.hpp"

class LevelController {
private:
	std::string bmpFileString;
	std::string pngFileString;
	int xTilesize;
	int yTilesize;
	int level_height;
	int level_width;
	int currentLevel;
public:
	LevelController();
	void BuildLevel(std::shared_ptr<spic::Scene> scene, std::filesystem::path filePath);
	void BuildLevelLayers(std::shared_ptr<spic::Scene> scene, std::pair<int, std::vector<std::vector<int>>> tileset);
	void BuildLevelObjects(std::shared_ptr<spic::Scene> scene, std::vector<std::pair<std::string, std::any>> object);
	void BuildLevelTile(std::shared_ptr<spic::Scene> scene, std::shared_ptr<spic::GameObject> tileObject, std::shared_ptr<spic::Sprite> tileSprite, spic::Transform transform, int x, int y, const std::string& spriteName, const std::string& tag);
	void BuildLevelEnemy(std::shared_ptr<spic::Scene> scene, std::shared_ptr<spic::Sprite> sprite, const std::tuple<int, int> position, const std::string& spriteName, const std::string& colourTag, const std::string& typeTag, int healthPoints, double speed, int damage);
	void BuildLevelObjectPosition(std::shared_ptr<spic::GameObject> object, std::tuple<int, int> position);
	void BuildLevelPlayer(std::shared_ptr<spic::Scene> scene, std::shared_ptr<spic::Sprite> sprite, std::tuple<int, int> position);
	void SetCurrentLevel(int value) { this->currentLevel = value; };
	int GetCurrentLevel() { return this->currentLevel; };

	template<typename T>
	const T get_value(const std::string& valueName, const std::vector<std::pair<std::string, std::any>>& object) {
		for (std::pair<std::string, std::any> value : object) {
			if (value.first == valueName) {
				return std::any_cast<T>(value.second);
			}
		}
	}
};
