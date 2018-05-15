#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"

#include <map>
#include <iostream>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    //init game world
    _game.initWorld("");//TODO 应该是输入有效的地图文件
}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();
    //pa->drawPixmap(0,0,QPixmap("C:\\Users\\Apple\\Desktop\\Cplus\\game\\example\\TileA.png"));
    //这种设置背景的方法现在不用了
    pa->begin(this);
    this->_game.show(pa);
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }

    //handlePlayerMove函数改完坐标以后再repaint画一遍
    this->repaint();
}
