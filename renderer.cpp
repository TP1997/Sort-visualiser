#include "renderer.h"
#include <iostream>

ArrayRenderer::ArrayRenderer(sf::RenderWindow &window): r_window(window){

}


BarRenderer::BarRenderer(sf::RenderWindow &window, int arrSize): ArrayRenderer(window){
    auto dimensions=window.getSize();
    barWidth=(float)dimensions.x/arrSize;
    barHeight=(float)dimensions.y/(arrSize+1);
    //std::cout << barHeight << std::endl;
}
BarRenderer::~BarRenderer(){

}
void BarRenderer::drawElement(int index, int value, sf::Color &color){
    auto dimensions=r_window.getSize();

    sf::RectangleShape rectShape(sf::Vector2f(barWidth, value*barHeight));
    rectShape.setPosition((index)*barWidth, dimensions.y-value*barHeight);
    rectShape.setFillColor(color);

    r_window.draw(rectShape);
}
