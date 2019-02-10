#include <iostream>
#include <SFML/Graphics.hpp>
#include "application.h"

using namespace std;

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1000, 600), "SFML works!");
    Application app(window, 1000, 600);
    app.mainloop();

    return 0;
}
