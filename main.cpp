// Copyright 2025 Danny Nguyen
#include <iostream>
#include "AniPlayer.hpp"
#include <SFML/Graphics.hpp>
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: Incorrect Pathway";
        return 1;
    }

    std::string path = argv[1];
    std::string filename = std::filesystem::path(path).filename().string();

    try {
        if (path.ends_with(".json")) {
            AP::AniPlayer player(path);
            sf::RenderWindow window(sf::VideoMode(player.pixelWidth(),
            player.pixelHeight()), filename);

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear(sf::Color::White);
                window.draw(player);
                window.display();
            }

        } else if (path.ends_with(".png")) {
            sf::Texture texture;
            if (!texture.loadFromFile(path)) {
                throw std::runtime_error("Failed to load image: " + path);
            }

            sf::Sprite sprite(texture);
            sf::RenderWindow window(sf::VideoMode(texture.getSize().x,
            texture.getSize().y), filename);

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear(sf::Color::White);
                window.draw(sprite);
                window.display();
            }

        } else {
            std::cerr << "Unsupported file type: " << path << "\n";
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error loading file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

