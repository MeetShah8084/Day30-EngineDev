#include<list.hpp>
// #include<iostream>


int main(){
    
    Node head{10};
    head.pushBack(11);
    head.pushBack(12);

    Node obj{13};
    head.pushBack(obj);


    head.printForward();
    // head.printBackward();


    return 0;
}