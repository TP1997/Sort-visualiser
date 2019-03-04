#include "application.h"
#include "algorithms.h"
#include <iostream>

Application::Application(sf::RenderWindow &window, int w, int h):
                        m_window(window),
                        scrW(w), scrH(h),
                        m_Array(window){

}
Application::~Application(){

}
void Application::mainloop(){
    m_window.setFramerateLimit(60);
    m_window.clear();
    m_window.setVisible(false);
    bool exit=false;
    while(!exit){
        std::cout << "Commands:" << std::endl;
        std::cout << "1 -> [exit]" << std::endl;
        std::cout << "2 -> [run]" << std::endl;

        std::string command;
        std::cin >> command;
        switch(castInteger(command)){
            case(1):
                exit=true;
                break;
            case(2):
                runVisualization();
                break;
            default:
                std::cout << "Invalid input!" << std::endl;
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
        }
    }
}
int Application::castInteger(std::string value){
    return atoi(value.c_str());
}
int Application::readInteger()throw(const char*){
    int command;
    if(!(std::cin >> command)){
        std::cin.clear();
        std::cin.ignore();
        throw "Invalid command!";
    }
    return command;
}
int Application::readCommand(){
    try{
        int value=readInteger();
        return value;
    }
    catch(const char* msg){
        std::cout << msg << std::endl;
        return 0;
    }
}
void Application::runVisualization(){
    std::cout << "Select algorithm:" << std::endl;
    std::cout << "1 -> [bubble sort]" << std::endl;
    std::cout << "2 -> [insertion sort]" << std::endl;
    std::cout << "3 -> [selection sort]" << std::endl;
    std::cout << "4 -> [merge sort]" << std::endl;
    std::cout << "5 -> [shell sort]" << std::endl;
    std::cout << "6 -> [cocktail sort]" << std::endl;
    std::cout << "7 -> [heap sort]" << std::endl;
    std::cout << "8 -> [quick sort]" << std::endl;
    m_Array.shuffle();
    bool noAction=false;

    std::string command;
    std::cin >> command;
    switch(castInteger(command)){
        case(1):
            m_window.setVisible(true);
            Algorihms::bubbleSort(m_Array);
            break;
        case(2):
            m_window.setVisible(true);
            Algorihms::insertionSort(m_Array);
            break;
        case(3):
            m_window.setVisible(true);
            Algorihms::selectionSort(m_Array);
            break;
        case(4):
            m_window.setVisible(true);
            Algorihms::mergeSort(m_Array);
            break;
        case(5):
            m_window.setVisible(true);
            Algorihms::shellSort(m_Array);
            break;
        case(6):
            m_window.setVisible(true);
            Algorihms::cocktailSort(m_Array);
            break;
        case(7):
            m_window.setVisible(true);
            Algorihms::heapSort(m_Array);
            break;
        case(8):
            m_window.setVisible(true);
            Algorihms::quickSort(m_Array);
            break;
        default:
            noAction=true;
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
    }
    if(!noAction){
        m_Array.paint();
    }

    m_window.setVisible(false);
}
