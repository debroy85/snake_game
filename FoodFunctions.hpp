#ifndef FOODFUNCTIONS_HPP
#define FOODFUNCTIONS_HPP
#include "Food.hpp"

void Food::genFood(){
    pos.X = (rand() % WIDTH-4) + 1;//get random nos [1,Width-2] formula -> (rand % (u-l))+l
    pos.Y = (rand() % HEIGHT-4) + 1;
}

Food::Food(){
    genFood();
}//to generate the first food at random place

COORD Food::getPos(){
    return pos;
}

#endif