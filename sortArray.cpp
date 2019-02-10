#include "sortArray.h"
#include <ctime>
#include<algorithm>
#include <chrono>
#include <thread>
#include <iostream>

sortArray::sortArray(sf::RenderWindow &window): m_window(window){
    for(int n=1; n<=100; n++){
        array.push_back(n);
    }
    renderer=new BarRenderer(window, array.size());
    sorted=false;
    delayTime=0;
    srand(time(NULL));
}
sortArray::~sortArray(){
    delete renderer;
}
void sortArray::shuffle(){
    for(unsigned int n=0; n<array.size(); n++){
        int m=rand()%array.size();
        swap(n, m);
    }
    sorted=false;
}
void sortArray::resize(unsigned int m){
    int oldsize=array.size();
    int lastElem=array.back();
    array.resize(m);
    if(m>array.size()){
        for(unsigned int n=oldsize; n<m; n++){
            array.push_back(++lastElem);
        }
    }
}
void sortArray::swap(int n, int m){
    int temp=array[n];
    array[n]=array[m];
    array[m]=temp;
}
int sortArray::size(){
    return array.size();
}
void sortArray::draw(int count, ...){
    std::vector<int> specials;
    if(count>0){
        va_list pl;
        va_start(pl, count);
        while(count-- > 0){
            specials.push_back(va_arg(pl, int));
        }
        va_end(pl);
    }
    draw(specials);
}
void sortArray::draw(std::vector<int> &vec){
    //if(m_window.isOpen()){
    delay();
    m_window.clear();
    for(unsigned int n=0; n<array.size(); n++){
        sf::Color color=calculateColor(array[n]);
        if(vec.size()>0 &&
           std::find(vec.begin(), vec.end(), array[n]) != vec.end()){
           color=sf::Color::White;
        }
        renderer->drawElement(n, array[n], color);
    }
    m_window.display();
    handleWinEvents();
//}
}
void sortArray::paint(){
    unsigned int count=0;
    for(unsigned int m=0; m<array.size(); m++){
        m_window.clear();
        for(unsigned int n=0; n<array.size(); n++){
            sf::Color color=(count>=n)?sf::Color::Green : calculateColor(array[n]);;
            renderer->drawElement(n, array[n], color);
        }
        m_window.display();
        count++;
    }
    delayTime=1000;
    delay();
}

sf::Color sortArray::calculateColor(int value){
    int amp=255/2;
    float freq=0.05;

    int r=amp*sin(freq*value)+amp;
    int g=amp*sin(freq*value+2)+amp;
    int b=amp*sin(freq*value+4)+amp;
    sf::Color color(r,g,b);
    return color;
}
void sortArray::handleWinEvents(){
    sf::Event event;
    if(m_window.pollEvent(event)){
        if(event.type==sf::Event::Closed){
            m_window.close();
            exit(0);
        }
    }
}
void sortArray::delay(){
    if(delayTime>0)
        std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));
}
int &sortArray::operator[](unsigned int n){
    return array[n];
}


