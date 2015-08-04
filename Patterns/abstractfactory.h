#ifndef ABSTRACTFACTORY
#define ABSTRACTFACTORY
#include <iostream>
#include <string>
class Ingredient{
public:
    virtual std::string getName()=0;
};

class Sauce:public Ingredient{

};
class BarbecueSauce:public Sauce{
    virtual std::string getName(){
        return "Barbecue";
    }
};
class CheeseSauce:public Sauce{
    virtual std::string getName(){
        return "Cheese";
    }
};

class Cheese:public Ingredient{

};
class GaudaCheese:public Cheese{
    virtual std::string getName(){
        return "Gauda";
    }
};
class GorgonzolaCheese:public Cheese{
    virtual std::string getName(){
        return "Gorgonzola";
    }
};

class MeetFlavoring:public Ingredient{

};
class Bacon:public MeetFlavoring{
    virtual std::string getName(){
        return "Bacon";
    }
};
class Chicken:public MeetFlavoring{
    virtual std::string getName(){
        return "Chicken";
    }
};

class PizzaFactory{
public:
    virtual Sauce *createSauce()=0;
    virtual Cheese *createCheese()=0;
    virtual MeetFlavoring *createMeet()=0;
};
class MargaretFactory:public PizzaFactory{
public:
    virtual Sauce *createSauce(){
        return new BarbecueSauce();
    }
    virtual Cheese *createCheese(){
        return new GaudaCheese();
    }
    virtual MeetFlavoring *createMeet(){
        return new Bacon();
    }
};
class BonanzaFactory:public PizzaFactory{
public:
    virtual Sauce *createSauce(){
        return new CheeseSauce();
    }
    virtual Cheese *createCheese(){
        return new GorgonzolaCheese();
    }
    virtual MeetFlavoring *createMeet(){
        return new Chicken();
    }
};

class Pizza{
    Sauce *sauce_;
    Cheese *cheese_;
    MeetFlavoring *meet_;
public:
    Pizza(PizzaFactory *factory){
        sauce_=factory->createSauce();
        cheese_=factory->createCheese();
        meet_=factory->createMeet();
    }
    void components(){
        std::cout<<"Sauce:"<<sauce_->getName()<<"\n"<<"Cheese:"<<cheese_->getName()<<"\n"<<"Flavoring:"<<meet_->getName()<<std::endl;
    }
};


#endif // ABSTRACTFACTORY

