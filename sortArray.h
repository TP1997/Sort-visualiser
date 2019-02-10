#ifndef SORTARRAY_H_INCLUDED
#define SORTARRAY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include <stdarg.h>
#include "renderer.h"

class sortArray{
    sf::RenderWindow &m_window;
    ArrayRenderer *renderer;
    std::vector<int> array;
    void delay();
    void handleWinEvents();
public:
    bool sorted;
    unsigned int delayTime;
    sortArray(sf::RenderWindow &);
    ~sortArray();
    void shuffle();
    void resize(unsigned int);
    void swap(int, int);
    int size();
    void draw(int, ...);
    void draw(std::vector<int> &);
    void paint();
    sf::Color calculateColor(int value);
    int &operator[](unsigned int);
};

#endif // SORTARRAY_H_INCLUDED
