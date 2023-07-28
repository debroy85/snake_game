#ifndef SNAKEFUNCTIONS_HPP
#define SNAKEFUNCTIONS_HPP
#include "Snake.hpp"


Snake::Snake(COORD pos, int vel){
    this->pos = pos;
    this->vel = vel;
    len = 1;
    dir = 'n';

    body.push_back(pos);//position of head of the snake
}

void Snake::changeDir(char dir){
    this->dir = dir;
}

void Snake::moveSnake(){
    switch(dir){
        case 'w': pos.Y -= vel;break;
        case 'a': pos.X -= vel;break;
        case 's': pos.Y += vel;break;
        case 'd': pos.X += vel;break;
    }

    body.push_back(pos);
    if(body.size()>len){
        body.erase(body.begin());
    }
}

COORD Snake::getPos(){
    return pos;
}

bool Snake::eaten(COORD foodPos){
    if(foodPos.X == pos.X && foodPos.Y == pos.Y){
        return true;
    }

    return false;
}

void Snake::grow(){
    len++;
}

bool Snake::hit(){
    if(pos.X<1 || pos.X>=WIDTH-2 || pos.Y<1 || pos.Y>=HEIGHT-2){
        return true;
    }
    return false;
}

vector<COORD> Snake::getBody(){
    return body;
}


#endif

