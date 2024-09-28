#pragma once

#include <vector>
#include "GameObject.hpp"
#include "Projectile.hpp"

namespace Matm
{
	class ObjectManager
	{
	public:
		ObjectManager();

		std::vector<GameObject*> getObjectList();
		int createProjectile(Projectile object);
		const Projectile& getProjectile(int id);

	private:
		std::vector<Projectile> _loadedProjectiles;
	};
}


