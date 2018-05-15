#include "world.h"
#include "icon.h"
#include"iostream"
using namespace std;
void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(5);
    this->_player.setPosY(5);

    //_background.load("C:\\Users\\Apple\\Desktop\\Cplus\\game\\example\\test.png");
    _background.load("C:\\Users\\Apple\\Desktop\\Cplus\\game\\example\\b2.jpg");
    //if(_background.isNull())
     //       cout<<"1"<<endl;
    //stone 4 5
    RPGObj obj1, obj2, obj3,obj4,obj5,obj6,obj7,obj8;
    obj1.initObj("stone");
    obj1.setPosX(4);
    obj1.setPosY(3);

    obj2.initObj("stone");
    obj2.setPosX(6);
    obj2.setPosY(5);

    obj3.initObj("fruit");
    obj3.setPosX(6);
    obj3.setPosY(8);

    obj4.initObj("fruit");
    obj4.setPosX(10);
    obj4.setPosY(10);

    obj5.initObj("fruit");
    obj5.setPosX(8);
    obj5.setPosY(12);

    obj6.initObj("fruit");
    obj6.setPosX(15);
    obj6.setPosY(13);

    obj7.initObj("fruit");
    obj7.setPosX(18);
    obj7.setPosY(15);

    obj8.initObj("cactus");
    obj8.setPosX(17);
    obj8.setPosY(5);

    this->_objs.push_back(obj1);//在vector尾部加入一个数据
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);
    this->_objs.push_back(obj6);
    this->_objs.push_back(obj7);
    this->_objs.push_back(obj8);

}

void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;//vector容器中存放RPGObj类（图片类）的对象
    painter->drawImage(0,0,this->_background);
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((this->_player.getPosY()+1==(*it).getPosY()&&this->_player.getPosX()==(*it).getPosX())&&(*it).canEat()){
            continue;
        }
        else{
            (*it).show(painter);
        }
    }
    //_player是rpgobj的继承类

   int found = 0;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        if((this->_player.getPosY()+1==(*it).getPosY()&&this->_player.getPosX()==(*it).getPosX())&&(*it).canCover()){
             this->_player.setPosX(this->_player.getPreX());
             this->_player.setPosY(this->_player.getPreY());
             this->_player.show(painter);
            found = 1;
        }
        else if((this->_player.getPosY()+1==(*it).getPosY()&&this->_player.getPosX()==(*it).getPosX())&&(*it).canKill())
        {
            this->_player.show(painter);
            this->_player.~Player();
            found = 1;
            break;
        }
    }
    if(found==0){
        this->_player.show(painter);
        this->_player.setPreX(this->_player.getPosX());
        this->_player.setPreY(this->_player.getPosY());


    }




}

void World::handlePlayerMove(int direction, int steps){

    this->_player.move(direction, steps);
}

