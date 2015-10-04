#ifndef ADAPTER
#define ADAPTER
#include <iostream>
class Target{
public:
    virtual void request()=0;
};
class Adaptee{
public:
    void specificRequest(){
        std::cout<<"Specific request called"<<"\n";
    }
};
class Adapter:public Target{
private:
    Adaptee *adaptee;
public:
    Adapter(Adaptee *ada):adaptee(ada){}
    void request(){
        adaptee->specificRequest();
    }
};

#endif // ADAPTER

