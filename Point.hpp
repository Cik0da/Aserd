#pragma once
#include <SDL3/SDL_render.h>
class Point

{

    double x;
    double y;

public:
    //Конструктор с параметрами
    Point(double x = 0.0, double y = 0.0);
    //Методы получения значений
    //Эти методы не изменяют объект
    //объявлены константами

    double getX() const;
    double getY() const;

    //Методы задания значений
    //Эти методы изменяют объект
    //возвращают ссылку на объект для которого
    //бы вызваны - возможна цепочка вызовов
    Point& setX(double x = 0.0);
    Point& setY(double y = 0.0);


    void render(SDL_Renderer *renderer) const;
};

