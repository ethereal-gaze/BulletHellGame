#pragma once

#include <filesystem>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define RESOURCES_PATH "./Resources"

namespace Matm
{
	// Manages the loading of textures, sounds etc
	class ResourceManager
	{
	public:
		ResourceManager(std::string texturesPath);
		// Loads textures from the Resources path (From Sprites folder) and sets their IDs
		void loadTextures();
		// Loads sounds from the Resources path (From Sounds folder) and sets their IDs
		void loadSounds();
		// Retreive a loaded sound. ID = File Name
		sf::Sound& getSound(int soundID);
		// Retreive a loaded texture. ID = File Name
		sf::Texture& getTexture(int textureID);
	private:
		std::string _texturesPath;
		std::vector<sf::Texture> _textures;
		bool _texturesAreLoaded;
		bool _soundsAreLoaded;
		std::string _resourcePath;

		std::vector<std::string> _listFiles();
		bool _isDigit(const std::string& str);
		void _registerTexture(const std::string& name, const int& id);

		std::vector<sf::Sound> _sounds;
	};
}