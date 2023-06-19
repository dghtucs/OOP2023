#pragma once
#include<string>
using namespace std;


class Widget {
    string _name;
    Window* _parent;

public:
    Widget(string name) :_name(name),_parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window* parent) { _parent = parent; } // 将 Widget对象 与 Window对象 绑定
    virtual ~Widget() {}
};
