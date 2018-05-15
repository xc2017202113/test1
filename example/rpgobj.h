#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
using namespace std;
class RPGObj
{
public:
    RPGObj(){}

    void initObj(string type);
    void show(QPainter * painter);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}
    void setPreX(int x){this->_pre_x=x;}
    void setPreY(int y){this->_pre_y=y;}
    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}
    int getPreX() const{return this->_pre_x;}
    int getPreY() const{return this->_pre_y;}
    bool canCover() const{return this->_coverable;}
    bool canEat() const{return this->_eatable;}
    bool canKill() const{return this->_killable;}

    string getObjType() const{return this->_icon.getTypeName();}//返回类名

protected:
    //所有坐标，单位均为游戏中的格

    QImage _pic;
    int _pos_x, _pos_y;//该物体在游戏中当前位置（左上角坐标）
    int _pre_x,_pre_y;
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
    bool _coverable;
    bool _eatable;
    bool _killable;
};

#endif // RPGOBJ_H
