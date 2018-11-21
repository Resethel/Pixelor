/*
 *
 *
 */
 #include <algorithm>
 #include <cstdlib>
 #include <limits>
 #include <random>
 #include <vector>

#include <SFMl/System.hpp>

#include "Utils.hpp"

using Frame = std::vector<sf::Color>;
Frame KMeans(Frame& data, size_t K, size_t numberOfIterations);
