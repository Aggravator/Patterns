#include "strategy.h"
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
int main(int argc, char ** argv){
    pseudoMain1();
    return 0;
}
