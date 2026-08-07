#include<iostream>

class Base;

void print(Base b);

class Base{

    friend void print(Base b);

    private:
        int m_data;
    public:
        Base():m_data{0}{}
        // Given are example constructors of type "conversion constructors" which the C++ uses for implicit conversion.
        explicit Base(int _data) : m_data{_data}{}
        explicit Base(const std::string& str) : m_data(str.length()){}
};



void print(Base b){
    std::cout << b.m_data << std::endl;
}

int main(){
    
    // Base b = 10; No viable conversion from int to base
    // Base c = std::string("Wow"); Same error 
    
    /* 
    Even though I have passed down integer. C++ implicily converts it into Base object via the Base(int _data) ctor
     Hence to avoid such conversions we use "explicit" keyword.
     By using it, we ensure no implicit conversion is done and the programmer using it would have to explicitly convert it using
     static_cast or
     (Type) expression or
     Type(expression)
    */
    
    // print(10);

    /*
        Also the implicit conversions can only go by once. 
        i.e, for the normal (const std::string& str) if I tried

        Base b = "Wow";

        It would give me an error since the C++ compiler would have to go from:
            const char[] -> string -> Base
    */
    
    return 0;
}