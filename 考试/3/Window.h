#pragma once
#include"Widget.h"
#include<list>

class Window
{
private:
    /* data */
public:
    list<shared_ptr<Widget>> w;
    Window(/* args */);
    ~Window();
};

Window::Window(/* args */)
{
}

Window::~Window()
{
}
