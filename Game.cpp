#include <filesystem>
#include "Game.hpp"
#include "Projectile.hpp"


using namespace Matm;

Game::Game() : _resourceManager(std::filesystem::current_path().string() + "/Resources/Textures"), _window(
	sf::VideoMode(1280, 720), "yes"), _gameState(Playing), _mainCamera(), proj(), _dt(1.0f / 60.0f), _accumulator(0.0f),
	_environmentData() {}

	void Game::run()
	{
		_resourceManager.loadTextures();
		proj = Projectile(_resourceManager.getTexture(0));

		sf::Clock clock;

		proj.setVelocity(sf::Vector2f(1, 1));

		while (_window.isOpen())
		{
			float frameTime = clock.restart().asSeconds();
			_accumulator += frameTime;

			_inputRoutine();

			while(_accumulator >= _dt)
			{
				EnvironmentData newEnv;
				newEnv.cursorPosition = sf::Mouse::getPosition();
				newEnv.playerPosition = { 0, 0 };
				_environmentData = newEnv;

				_gameRoutine();
				_accumulator -= _dt;
			}

			_graphicsRoutine();
		}
	}

	void Game::_inputRoutine()
	{
		sf::Event wevent;
		while (_window.pollEvent(wevent))
		{
			switch (wevent.type)
			{
				case(sf::Event::Closed):
					_window.close();
			}
		}
	}

	void Game::_graphicsRoutine()
	{


		_window.setView(_mainCamera);

		_window.clear(sf::Color(0,0,0,0));

		_window.draw(proj);

		_window.display();
	}

	void Game::_gameRoutine()
	{
		proj.Ai(_environmentData);
	}