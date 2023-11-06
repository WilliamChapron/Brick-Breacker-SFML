#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureManager {
public:
    // Constructeur
    TextureManager();

    // Charger une texture � partir d'un fichier avec une cl� num�rique
    void LoadTexture(int id, const std::string& filename);


    sf::Texture& GetTexture(int id);

    bool HasTexture(int id);

    void RemoveTexture(int id);


    void ClearTextures();

private:
    std::map<int, sf::Texture> kvmap_textures; // map key value
};