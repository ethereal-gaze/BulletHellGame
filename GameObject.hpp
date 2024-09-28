#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "EnvironmentData.hpp"

namespace Matm
{
	class GameObject : public sf::Sprite
	{
	public:
		// Inherit constructor from Sprite class
		using sf::Sprite::Sprite;

		const sf::Vector2f& getVelocity();
		void setVelocity(const sf::Vector2f& velocity);
		sf::Vector2f getCentre();

		GameObject();
		virtual void Ai(const EnvironmentData& envData) = 0;
	private:
		sf::Vector2f _velocity;

	protected:

		void _moveUsingVelocity();
	};
}
