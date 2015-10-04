#include "strategy.h"
#include "observer.h"
#include "decorator.h"
#include "factorymethod.h"
#include "abstractfactory.h"
#include "singleton.h"
#include "command.h"
#include <iostream>
using namespace std;

//Strategy pattern
void pseudoMain1(){
    Context<int> context;
    cout <<"Strategy is not selected: " <<context.performStrategy(2, 3) << endl;
    context.setStrategy(new SpecificStrategy1<int>());
    cout << "First strategy is selected: " << context.performStrategy(2, 3) << endl;
    context.setStrategy(new SpecificStrategy2<int>());
    cout << "Second strategy is selected: " << context.performStrategy(2, 3) << endl;
}
//Observer pattern
void pseudoMain2(){
    Subject subject;
    SpecificObserver observer1("Andrey");
    SpecificObserver observer2("Clara");
    subject.registerObserver(&observer1);
    subject.registerObserver(&observer2);
    subject.notifyObservers();
}
//Decorator pattern
void pseudoMain3(){
    shared_ptr<ConcreteComponent> cnComponent(new ConcreteComponent());
    shared_ptr<Decorator> decarator1(new Decorator(string("apple"),cnComponent));
    shared_ptr<Decorator> decarator2(new Decorator(string("banana"),decarator1));
    decarator2->operation();
    cout<<endl;
}
//Factory Method and Abstract Factory
void pseudoMain4(){
    //Non classic Factory Method
    cout<<"Non Classic Factory Method"<<endl;
    shared_ptr<Product> product1(Product::createProduct(1));
    shared_ptr<Product> product2(Product::createProduct(2));
    cout<<product1->getType()<<endl;
    cout<<product2->getType()<<endl;
    //Classic Factory Method
    cout<<"\nClassic Factory Method"<<endl;
    shared_ptr<ClassicFactory> factory(new SpecificClassicFactory1());
    product1.reset(factory->createProduct());
    cout<<product1->getType()<<endl;
    factory.reset(new SpecificClassicFactory2());
    product2.reset(factory->createProduct());
    cout<<product2->getType()<<endl;
    //Abstract Factory
    cout<<"\nAbstract Factory\n"<<endl;
    shared_ptr<PizzaFactory> pf(new MargaretFactory());
    shared_ptr<Pizza> pizza( new Pizza(pf.get()) );
    pizza->components();
    cout<<endl;
    pf.reset(new BonanzaFactory());
    pizza.reset( new Pizza( pf.get()) );
    pizza->components();
}
//Singleton pattern
void pseudoMain5(){
    std::shared_ptr<Singleton>  singleton1(Singleton::getInstance());
    cout<<"Singelton1 id:"<<singleton1->getId()<<endl;
    std::shared_ptr<Singleton> singleton2(Singleton::getInstance());
    cout<<"Singelton2 id:"<<singleton2->getId()<<endl;
}
//Command pattern
void pseudoMain6(){
    std::shared_ptr<Reciever> recv(new Reciever);
    std::shared_ptr<ACommand> command(new Command1(recv.get()));
    command->exec();
    command.reset(new Command2(recv.get()));
    command->exec();
}

int main(int argc, char ** argv){
    //pseudoMain1();
    //pseudoMain2();
    //pseudoMain3();
    //pseudoMain4();
    //pseudoMain5();
    pseudoMain6();
    return 0;
}
