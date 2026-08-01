#include <iostream>

class A {
public:
    virtual void a() { std::cout << "A::a\n"; }
    int x = 1;
    virtual ~A() {}
};

class B {
public:
    virtual void b() { std::cout << "B::b\n"; }
    int y = 2;
    virtual ~B() {}
};

class C : public A, public B {
public:
    void a() override { std::cout << "C::a\n"; }
    void b() override { std::cout << "C::b\n"; }
};

int main() {
    C c;

    A* a_ptr = &c;
    B* b_ptr = &c;

    std::cout << "Address of complete object c : " << (void*)&c   << "\n";
    std::cout << "A* a_ptr (same address)       : " << (void*)a_ptr << "\n";
    std::cout << "B* b_ptr (offset into c)      : " << (void*)b_ptr << "\n";

    void* recovered = dynamic_cast<void*>(b_ptr);
    std::cout << "dynamic_cast<void*>(b_ptr)    : " << recovered << "  (should equal &c)\n";

    std::cout << "Byte offset B* had from &c    : "
              << ((char*)b_ptr - (char*)&c) << " bytes\n";

}