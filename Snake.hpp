#ifndef SNAKE_HPP
#define SNAKE_HPP

#include<vector>
#include<windows.h>


using namespace std;

#define HEIGHT 25
#define WIDTH 50

class Snake{
    private:
        COORD pos;
        int len;
        int vel;
        char dir;
        vector<COORD> body;

    public:
        Snake(COORD pos, int vel);
        void changeDir(char dir);
        void moveSnake();
        COORD getPos();
        bool eaten(COORD foodPos);
        void grow();
        bool hit();
        vector<COORD> getBody();
};





#endif

