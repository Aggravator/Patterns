#ifndef STRATEGY_H
#define STRATEGY_H
#include <memory>
#include <iostream>

template <class T>
class Strategy{
public:
    virtual T algorithm(T a, T b)=0;
};
template <class T>
class SpecificStrategy1 :public Strategy<T>{
    virtual T algorithm(T a, T b){
        return a + b;
    }
};
template <class T>
class SpecificStrategy2 :public Strategy<T>{
    virtual T algorithm(T a, T b){
        return a - b;
    }
};
template <class T>
class Context{
private:
    std::shared_ptr< Strategy<T> > strategy_;
public:
    Context(Strategy<T> *strategy=nullptr){
        strategy_.reset(strategy);
    }
    void setStrategy(Strategy<T> *strategy = nullptr){
        strategy_.reset(strategy);
    }
    T performStrategy(T a, T b){
        if (!strategy_) return T();
        return strategy_->algorithm(a, b);
    }
};
#endif // STRATEGY_H

