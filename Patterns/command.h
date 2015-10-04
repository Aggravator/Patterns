#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
class ACommand{
public:
    virtual void exec()=0;
    virtual ~ACommand(){};
};
class Reciever{
public:
    void action1(){
        std::cout<<"Reciever action1!"<<"\n";
    }
    void action2(){
        std::cout<<"Reciever action2!"<<"\n";
    }
};

class Command1:public ACommand{
private:
    Reciever *recv;
public:
    Command1(Reciever* recv):recv(recv){
    }
    ~Command1(){}
    virtual void exec(){
        recv->action1();
    }
};

class Command2:public ACommand{
private:
    Reciever *recv;
public:
    Command2(Reciever* recv):recv(recv){
    }
    ~Command2(){}
    virtual void exec(){
        recv->action2();
    }
};

#endif // COMMAND_H

