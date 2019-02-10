#ifndef RENDERER_H_INCLUDED
#define RENDERER_H_INCLUDED
#include <SFML/Graphics.hpp>

class ArrayRenderer{
protected:
    sf::RenderWindow &r_window;
    ArrayRenderer(sf::RenderWindow&);
public:
    virtual ~ArrayRenderer(){};
    virtual void drawElement(int, int, sf::Color &)=0;
};

class BarRenderer : public ArrayRenderer{
    float barWidth;
    float barHeight;
public:
    BarRenderer(sf::RenderWindow&, int);
    ~BarRenderer();
    void drawElement(int, int, sf::Color&);
};

#endif // RENDERER_H_INCLUDED
