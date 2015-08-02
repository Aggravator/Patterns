#include "strategy.h"
#include "observer.h"
#include <iostream>
using namespace std;
void pseudoMain1(){
    Context<int> context;
    cout <<"Strategy is not selected: " <<context.performStrategy(2, 3) << endl;
    context.setStrategy(new SpecificStrategy1<int>());
    cout << "First strategy is selected: " << context.performStrategy(2, 3) << endl;
    context.setStrategy(new SpecificStrategy2<int>());
    cout << "Second strategy is selected: " << context.performStrategy(2, 3) << endl;
}
void pseudoMain2(){
    Subject subject;
    SpecificObserver observer1("Andrey");
    SpecificObserver observer2("Clara");
    subject.registerObserver(&observer1);
    subject.registerObserver(&observer2);
    subject.notifyObservers();
}

int main(int argc, char ** argv){
    //pseudoMain1();
    pseudoMain2();
    return 0;
}
