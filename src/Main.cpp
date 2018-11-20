#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#include "Utils.hpp"
#include "Quantization.hpp"

int main(int argc, char** argv)
{

    std::string fileName = argv[1];
    unsigned pixelSize = atoi(argv[2]);


    sf::Image rawImage;
    sf::Image output;


    if(!rawImage.loadFromFile(fileName))
        return -1;

    unsigned width  = rawImage.getSize().x;
    unsigned height = rawImage.getSize().y;



    if(!sizeIsValid(width, height, pixelSize))
        return -1;

    output.create(width, height, sf::Color::Transparent);


    // Quantizing ...
    sf::Image image = randomQuantize(rawImage, 64);


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
