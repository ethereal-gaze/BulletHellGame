#pragma once

#include <vector>
#include "GameObject.hpp"

namespace Matm
{
	class ObjectManager
	{
	public:
		std::vector<sf::Sprite>& RetrieveRenderQueue();
		GameObject& GetObject(int id);
		int Register(GameObject object);

	private:
		std::vector<GameObject> _loadedObjects;
	};
}


