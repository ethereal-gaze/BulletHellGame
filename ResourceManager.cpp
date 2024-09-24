#include "ResourceManager.hpp"

#include <iostream>
#include <sys/stat.h>

using namespace Matm;

ResourceManager::ResourceManager(std::string texturesPath) : _texturesPath(texturesPath), _textures(),
_texturesAreLoaded(false), _soundsAreLoaded(false), _sounds()
{}

std::vector<std::string> ResourceManager::_listFiles()
{
	std::vector<std::string> files;

	try
	{
		if (std::filesystem::exists(_texturesPath) && std::filesystem::is_directory(_texturesPath))
		{
			

			struct stat sb;

			for (const auto& entry : std::filesystem::directory_iterator(_texturesPath))
			{
				std::filesystem::path filename = entry.path();

				// Put non-directories on the file list
				if (stat(filename.string().c_str(), &sb) == 0 && !(sb.st_mode & S_IFDIR))
					files.push_back(entry.path().string());
			}
		}
		else
		{
			std::cerr << "Provided path: " << _texturesPath << " isn't a directory!\n";
		}

	}
	catch (std::system_error& error)
	{
		std::cerr << "Caught exception: " << error.what() << "\n";
	}

	return files;
}


bool ResourceManager::_isDigit(const std::string& str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

void ResourceManager::loadTextures()
{
	// Get all files in the directory
	std::vector<std::string> textureFilesList = this->_listFiles();
	std::vector<int> ids;

	for (auto& element : textureFilesList)
	{
		// Remove the rest of the path and get the file name itself
		std::filesystem::path pathobj = std::filesystem::path(element);
		std::string filename = pathobj.stem().string();

		if (this->_isDigit(filename))
		{
			// If it is then it's safe to register
			ids.push_back(std::stoi(filename));
		}
	}

	if (ids.size() == 0)
	{
		std::cerr << "Unable to find any textures!\n";
		return;
	}

	// Sort the ids list
	std::sort(ids.begin(), ids.end());

	// Create a vector big enough for all the textures (So they can be placed in memory according to their id)
	_textures = std::vector<sf::Texture>(ids.size());

	// Load each texture and place it at its offset according to its id
	int id = 0; // Increase each iteration to get id

	for (auto& element : textureFilesList)
	{
		_registerTexture(element, id);
		id++;
	}
}

void ResourceManager::_registerTexture(const std::string& name, const int& id)
{
	// Try to load the texture

	if (not _textures[id].loadFromFile(name))
		std::cerr << "There was an issue loading the texture \"" << name << "\"\n";
	else
#ifdef _DEBUG
		std::cout << "Loaded texture: \"" << name << "\" at id " << id << "\n";
#endif
	return;
}

sf::Texture& ResourceManager::getTexture(int textureID)
{
	if (textureID > _textures.size())
	{
		std::cerr << "Tried to access a texture id that does not exist\n";
		return _textures[0];
	}
	else
		return _textures[textureID];
}