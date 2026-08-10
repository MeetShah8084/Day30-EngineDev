#include<iostream>

struct Base{
    int basedata{1};
    Base(){
        basedata = 11;
    }

    virtual void doStuff(){
        std::cout << "Base::doStuff()\t" << basedata << std::endl;
    }

    virtual ~Base(){}
};


struct Derived: Base{
    int derivedData{2};

    Derived(){
        derivedData = 22;
    }

    virtual void doStuff() override{
        std::cout << "Derived::doStuff()\t" << derivedData << '\t' << basedata << std::endl;
    }

    ~Derived() = default;

    virtual void doSomething(){
        std::cout << "Derived::doSomething()" << std::endl;
    }
};

int main(){
    Base* b = new Base{};
    Derived* d = new Derived{};

    // std::cout << sizeof(Base) << '\t' << sizeof(Derived) << std::endl;

    if(dynamic_cast<Derived*>(b)){
        Derived* dd = dynamic_cast<Derived*>(b);
        dd->doStuff();
    }

    static_cast<Derived*>(b)->doSomething();

    delete b; delete d;

    return 0;
}