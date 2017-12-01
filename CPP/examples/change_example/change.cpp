#include <iostream>
#include <cassert>

double make_change(double dollars){
    std::cout << "dollars: " << dollars << std::endl;
    double pennies = 100 * dollars;
    std::cout << "pennies: " << pennies << std::endl;
    int denoms[4] = {25,10,5,1};
    double counts[4] = {0};
    for (int i=0; i <4; ++i){
        std::cout << "pennies: " << pennies << "/demons: " << denoms[i] << std::endl; 
        counts[i] = pennies / denoms[i];
        std::cout << "count value: " << counts[i] << " num: " << i << std::endl;
        pennies -= counts[i] * denoms[i];
    }
        
    //assert(pennies == 0);
    return pennies;
}


int main(){
    double money = 2.50;
    double change{0};
    change = make_change(money);
    std::cout << "change: " << change << std::endl;
}
