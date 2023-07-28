#ifndef FOOD_HPP
#define FOOD_HPP

#include<cstdlib>
#include<cstdio>
#include<windows.h>

#define HEIGHT 25
#define WIDTH 50

class Food{
    private:
       COORD pos;
    public:
        Food();
        void genFood(); 
        COORD getPos();
};

#endif