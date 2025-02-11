#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
    : width(width), height(height)
{
}

Rectangle::~Rectangle()
{
}

float Rectangle::GetArea()
{
    return width * height;
}

float Rectangle::GetSize()
{
    return 2.f * (width + height);
}
