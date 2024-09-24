#pragma once

#include "Projectile.hpp"

using namespace Matm;

void Projectile::Ai(const EnvironmentData& envData)
{
    _moveUsingVelocity();
}
