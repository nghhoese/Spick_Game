#pragma once
#include "API_Headers/Scene.hpp"
#include "API_Headers/GameObject.hpp"
#include "API_Headers/Sprite.hpp"
#include "API_Headers/Transform.hpp"
#include "Facade_Headers/TiledFacade.hpp"

namespace fs = std::filesystem;

class Level : public spic::TiledFacade {
private:
	int xTilesize;
	int yTilesize;
	int level_height;
	int level_width;

public:
	void BuildLevel(std::shared_ptr<spic::Scene> scene, fs::path filePath);

	void BuildLevelLayers(std::shared_ptr<spic::Scene> scene, std::pair<int, std::vector<std::vector<int>>> tileset);

	void BuildLevelObjects(std::shared_ptr<spic::Scene> scene, std::vector<std::pair<std::string, std::any>> object);

};
