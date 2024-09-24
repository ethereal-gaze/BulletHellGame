#include "GameObject.hpp"

namespace Matm
{
    GameObject::GameObject() {}

    void GameObject::setVelocity(const sf::Vector2f& velocity)
    {
        _velocity = velocity;
    }

    const sf::Vector2f& GameObject::getVelocity()
    {
        return _velocity;
    }

    void GameObject::_moveUsingVelocity()
    {
        move(_velocity);
    }
}
