#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

class Observer{
public:
    virtual void notify()=0;
};
class SpecificObserver:public Observer{
private:
    std::string name_;
public:
    SpecificObserver(const std::string & name){
        name_=name;
    }
    void notify(){
        std::cout<<name_<<": Oo, I am coming!"<<std::endl;
    }
};

class Subject{
private:
    std::vector<Observer*> observers_;
public:
    void registerObserver(Observer* observer){
        if(std::find(observers_.begin(),observers_.end(),observer)==observers_.end())
            observers_.push_back(observer);
    }
    void unregisterObserver(Observer* observer){
        auto iter=std::find(observers_.begin(),observers_.end(),observer);
        if(iter!=observers_.end())
            observers_.erase(iter);
    }
    void notifyObservers(){
        for (auto i:observers_)
            i->notify();
    }
};

#endif // OBSERVER_H

