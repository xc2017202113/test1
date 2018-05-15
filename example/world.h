#ifndef WORLD_H
#define WORLD_H
#include<iostream>
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
//#include<QImage>
using namespace std;

class World
{
public:
    World(){}
    ~World(){}
    void initWorld(string mapFile);
        //输入的文件中定义了初始状态下游戏世界有哪些对象，出生点在哪
        /*e.g.
           player 5 5
           stone 3 3
           fruit 7 8
         */
    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家

private:
    vector<RPGObj> _objs;//用于装RPGObj对象的容器
    Player _player;
    QImage _background;
};

#endif // WORLD_H
