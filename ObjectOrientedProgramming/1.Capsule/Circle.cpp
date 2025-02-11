#include "Circle.h"

Circle::Circle(float radius)
    : radius(radius)
{
}

Circle::~Circle()
{
}

float Circle::GetArea()
{
    return PI * radius * radius;
}

float Circle::GetSize()
{
    return 2.f * PI * radius;
}
