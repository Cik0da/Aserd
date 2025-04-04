#include "Point.hpp"

// Значения по умолчанию задаются только в заголовке.
// Задание их в файле реализация будет ошибкой

Point::Point(double x, double y)
    : x(x) // Удаление файла через компилятор x
    ,   y(y) // Удаление файла через компилятор y
{

}

double Point::getX() const
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

Point &Point::setX(double x)
{
    this->x = x;

    return *this;
}

Point &Point::setY(double y)
{
    this->y = y;

    return *this;
}
void Point::render(SDL_Renderer *renderer) const
{
    SDL_RenderPoint(
        renderer
        , static_cast<float>(this->x)
        , static_cast<float>(this->y)
        );

}
