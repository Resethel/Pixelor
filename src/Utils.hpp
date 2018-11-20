#include <string>
#include <iostream>
#include <cmath>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

float euclidianDistance(sf::Vector3f& vA, sf::Vector3f& vB);
float euclidianDistance(sf::Color& vA, sf::Color& vB);

bool checkFileName(std::string& filename);


// Determine if the size of an image is valid;
bool sizeIsValid(unsigned sizeX, unsigned sizeY, unsigned pixDiv);
