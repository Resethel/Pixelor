
#include "Utils.hpp"




bool checkFileName(std::string& filename)
{
    //TODO Make this function validate if the name is valid
    return true;
}



bool sizeIsValid(unsigned sizeX, unsigned sizeY, unsigned pixDiv)
{
    bool isValid = true;

    if (sizeX % pixDiv != 0)
    {
        std::cout << "ERROR: Image width is not divisible by pixel size (" << pixDiv << ").\n";
        std::cout << "Width is size " << sizeX <<'\n';
        std::cout << "Modulo: " << sizeX % pixDiv << "\n";

        isValid = false;
    }

    if (sizeY % pixDiv != 0)
    {
        std::cout << "ERROR: Image height is not divisible by pixel size (" << pixDiv << ").\n";
        std::cout << "Height is size " << sizeY <<'\n';
        std::cout << "Modulo: " << sizeY % pixDiv << "\n";

        isValid = false;
    }

    return isValid;
}
