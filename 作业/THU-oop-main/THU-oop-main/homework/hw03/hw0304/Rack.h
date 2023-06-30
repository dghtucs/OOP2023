#pragma once
#include<iostream>
#include<vector>

class Rack {
    private:
        std::vector<int>goods;
        int size;
    public:
        Rack(); 
        Rack(const Rack&);
        ~Rack(); // 析构
        Rack& operator+= (int number);
        Rack& operator+= (const Rack &r);
        friend bool operator< (const Rack &left, const Rack &right);
        friend bool operator> (const Rack &left, const Rack &right);
        friend bool operator== (const Rack &left, const Rack &right);
        friend Rack& operator, (const int &aGoods, const Rack& shelf); 
        friend Rack& operator, (const Rack& shelf1, const Rack& shelf2); 
        friend Rack& operator, (const Rack& shelf, const int &aGoods); 
        Rack& operator-- (int);
        Rack& operator-- (); 
        Rack& operator~ (); 
        int operator()(const int &i); 
        Rack& operator& (const Rack &r); 
        friend std::ostream& operator<<(std::ostream&out, const Rack &r);

};