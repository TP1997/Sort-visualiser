#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "sortArray.h"

class Application{
    sf::RenderWindow &m_window;
    int scrW, scrH;
    sortArray m_Array;

public:
    Application(sf::RenderWindow &, int, int);
    ~Application();
    void mainloop();
    int castInteger(std::string value);
    int readInteger()throw(const char*);
    int readCommand();
    void runVisualization();
};

#endif // APPLICATION_H_INCLUDED
