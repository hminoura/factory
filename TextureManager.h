#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class TextureManager {
  TextureManager();
  ~TextureManager();
  std::unordered_map<std::string, sf::Texture> textures;

public:
  TextureManager(const TextureManager&) = delete;
  TextureManager& operator=(const TextureManager&) = delete;
  TextureManager(const TextureManager&&) = delete;
  TextureManager& operator=(const TextureManager&&) = delete;

  static TextureManager* getInstance();

  sf::Texture* get(const std::string& filename);
};
