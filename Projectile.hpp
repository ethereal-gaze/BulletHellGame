#pragma once

#include "GameObject.hpp"

namespace Matm
{
    class Projectile : public GameObject
    {
    public:
        using GameObject::GameObject;
        void Ai(const EnvironmentData& envData);

    };
}
