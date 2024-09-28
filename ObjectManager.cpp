#pragma once
#include "ObjectManager.hpp"

using namespace Matm;

ObjectManager::ObjectManager() : _loadedProjectiles()
{}

std::vector<GameObject*> ObjectManager::getObjectList()
{
    // Create list of pointers to all loaded objects.
    std::vector<GameObject*> gameObjectsPointers;

    for (auto& element : _loadedProjectiles)
    {
        gameObjectsPointers.push_back(&element);
    }

    return gameObjectsPointers;
}

int Matm::ObjectManager::createProjectile(Projectile object)
{
    _loadedProjectiles.push_back(object);

    return (_loadedProjectiles.size() - 1);
}


const Projectile& ObjectManager::getProjectile(int id)
{
    if (id > (_loadedProjectiles.size() - 1))
        throw std::invalid_argument("Tried to access invalid projectile.\nID: " + std::to_string(id) +
        "\nLoaded Projectiles: " +
        std::to_string(_loadedProjectiles.size()));
    else
        return _loadedProjectiles[id];
}

