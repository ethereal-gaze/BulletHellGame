#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "Projectile.hpp"

namespace Matm
{
	class Game
	{
	private:

		// States the game can be in. For the state machine
		enum GameState
		{
			Pause,
			Menu,
			Playing
		};

		ResourceManager _resourceManager;
		sf::RenderWindow _window;
		GameState _gameState;
		sf::View _mainCamera;
		Projectile proj;
		float _dt;
		float _accumulator;
		EnvironmentData _environmentData;

		void _graphicsRoutine();
		void _inputRoutine();
		void _gameRoutine();

	public:
		Game();
		void run();
	};
}