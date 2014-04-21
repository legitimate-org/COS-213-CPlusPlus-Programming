#include "Plot.h"
#include <iostream>

Plot::Plot()
{
    // Defaults length and width ti 7 and 9.
    length = 7;
    width = 9;
}

Plot::Plot(int length, int width)
{
    // Assigns length and width if 2 values are passed in
    this->length = length;
    this->width = width;
}

void Plot::areaAndBoundaryLength()
{
    // Calculates and prints area
    int area = (length * width);
    std::cout << "Area: " << area << std::endl;

    // Calculates and prints boundary
    int boundary = 2 * (length + width);
    std::cout << "Length of boundary of the plot: " << boundary << std::endl;
}
