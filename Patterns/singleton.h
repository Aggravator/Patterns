#ifndef SINGLETON
#define SINGLETON
#include <iostream>
#include <memory>

class Singleton;
std::shared_ptr<Singleton> tempSingleton;
class Singleton{
private:
    static int count;
    int id;
    Singleton(){
        ++count;
        id=count;
    }
public:
    static std::shared_ptr<Singleton> getInstance(){
        if(!tempSingleton){
            tempSingleton.reset(new Singleton());
        }
        return tempSingleton;
    }
    static bool destroy(){
        if(tempSingleton.use_count()==1)tempSingleton.reset();
    }
    int getId(){
        return id;
    }
};

int Singleton::count=0;

#endif // SINGLETON

