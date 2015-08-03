#ifndef DECORATOR_H
#define DECORATOR_H

#include <memory>
#include <iostream>
#include <string>

class Component{
public:
    virtual void operation()=0;
};
class ConcreteComponent:public Component{
public:
    virtual void operation(){
        std::cout<<"Component";
    }
};

class Decorator:public Component{
private:
    std::shared_ptr<Component> component_;
    std::string name_;
public:
    Decorator(std::string name,std::shared_ptr<Component> component):name_(name){
        component_=component;
    }
    virtual void operation(){
        std::cout<<"("<<name_<<" ";
        component_->operation();
        std::cout<<")";
    }
};

#endif // DECORATOR_H

