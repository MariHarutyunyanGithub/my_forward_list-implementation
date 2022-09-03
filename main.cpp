#include <iostream>
#include "forward_list.h"


int main() {
    
    FList<int> obj1(10);//10
    obj1.insert(1,11);//11 10
    obj1.insert(2,12);//11 10 12
    obj1.insert(3,13);//11 10 12 13
    obj1.insert(2,5);//11 10 5 12 13
    obj1.insert(0,4);//
    obj1.push_front(8);//8 11 10 5 12 13
    obj1.remove_at(3);//8 11 10 12 13
    obj1.remove_at(3);//8 11 10 13
    obj1.setEntry(2,90);//8 11 90 13
    std::cout << "my list : " << obj1 << std::endl;
    //std::cout << obj1.getEntry(2) << std::endl;//10
    //obj1.clear();
    //FList<int> obj(5);
    // obj.insert(1,4);
    // obj.insert(1,8);
    // obj1 = obj;
    
    //std::cout << obj1.isEmpty() <<std::endl;
    return 0;
}