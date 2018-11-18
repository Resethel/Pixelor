#include <iostream>
#include <SFML/Graphics.hpp>

#include "Utils.hpp"

int main(int argc, char** argv)
{

    std::string fileName = argv[1];


    sf::Image image;
    sf::Image output;


    if(!image.loadFromFile(fileName))
        return -1;

    unsigned width  = image.getSize().x;
    unsigned height = image.getSize().y;

    output.create(width, height, sf::Color::Transparent);

    unsigned pixelSize = 15; // Fixed for now


    std::vector<sf::Vector2u> pos;

    for(int x(0) ; x < width/pixelSize ; x++)
    for(int y(0) ; y < height/pixelSize ; y++)
    {
        pos.emplace_back(x,y);
    }


    // Determining the colors that the pixel should take
    std::vector<sf::Color> colors;
    for(auto& pix : pos)
    {
        unsigned X = pix.x;
        unsigned Y = pix.y;

        colors.clear();


        for(int dx(0) ; dx < pixelSize ; dx++)
        for(int dy(0) ; dy < pixelSize ; dy++)
        {
            colors.push_back(image.getPixel( X * pixelSize + dx,
                                              Y * pixelSize + dy));
        }

        unsigned r(0);
        unsigned g(0);
        unsigned b(0);
        for(auto& c : colors)
        {
            r += c.r;
            g += c.g;
            b += c.b;
        }

        auto tot = colors.size();

        sf::Color newColor( uint8_t(r / tot),
                            uint8_t(g / tot),
                            uint8_t(b / tot));

        // Sets the pixelColor
        for (int dx(0) ; dx < pixelSize ; dx++)
        for (int dy(0) ; dy < pixelSize ; dy++)
        {
            output.setPixel( X * pixelSize + dx,
                             Y * pixelSize + dy,
                             newColor);
        }
    }


    if (!output.saveToFile("result.png"))
        return -1;

    return 0;
}
