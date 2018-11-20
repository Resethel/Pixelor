/*
 * Quantization.hpp
 * Methods for changing the number of color in an image
 */
#include <algorithm>
#include <random>

#include <SFML/Graphics.hpp>

#include "Utils.hpp"




sf::Image randomQuantize(sf::Image image, unsigned nColors);
