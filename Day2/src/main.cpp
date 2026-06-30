// #include<iostream>
#include<book.hpp>
#include<iostream>
#include<memory>


int main(){

    Library clgLib{};
    clgLib.addBook(3, "Mambo", "hachimi");
    clgLib.addBook(2, "Ada", "Wong");
    clgLib.addBook(1, "Ashley", "Graham");

    Reader rd{"Meet"};

    rd.borrow(clgLib.lendBook("Mambo"));
    
    clgLib.removeBook("Mambo");

    rd.read();


    clgLib.listBook();

    std::cout << sizeof(clgLib) << std::endl;

    return 0;
}