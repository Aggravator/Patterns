#ifndef FACTORYMETHOD
#define FACTORYMETHOD
#include <string>

class ConcreteProduct1;
class ConcreteProduct2;
class Product{
public:
    virtual std::string getType()=0;
    static Product* createProduct(int type);
};

class ConcreteProduct1:public Product{
public:
    virtual std::string getType(){
        return "Product1";
    }
};

class ConcreteProduct2:public Product{
public:
    virtual std::string getType(){
        return "Product2";
    }
};

class ClassicFactory{
public:
    virtual Product* createProduct()=0;
};
class SpecificClassicFactory1:public ClassicFactory{
public:
    virtual Product* createProduct(){
        return new ConcreteProduct1();
    }
};
class SpecificClassicFactory2:public ClassicFactory{
public:
    virtual Product* createProduct(){
        return new ConcreteProduct2();
    }
};
Product* Product::createProduct(int type){
    switch(type){
    case 1:
        return new ConcreteProduct1();
    case 2:
        return new ConcreteProduct2();
    }
    return nullptr;
}
#endif // FACTORYMETHOD

