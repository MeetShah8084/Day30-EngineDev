#include<iostream>
#include<new>

class Array{
    private:
        int* ptr{nullptr};
        int size=0;
    public:
        Array(){
            ptr = new(std::nothrow) int[5];
            size = 5;
            std::cout << "Array(); size=5" << std::endl;
        }

        Array(int _size){
            this->ptr = new(std::nothrow) int[_size];
            if(this->ptr == nullptr){
                std::cerr << "Not enough memory!" << std::endl;
                return;
            }

            this->size =_size;
            std::cout << "Array(int); size=" << size << std::endl;
        }

        ~Array(){
            std::cout << "~Array()" << std::endl;
            delete[] ptr;
        }

        Array(Array&& other) noexcept{
            if(this == &other){
                return;
            }

            if(other.ptr == nullptr) return;

            delete[] ptr;
            
            this->ptr = other.ptr;
            this->size = other.size;

            other.ptr = nullptr;
            other.size = 0;

        }

        Array& operator=(Array&& other) noexcept{
            if(this == &other) return *this;

            if(other.ptr == nullptr) return *this;

            delete[] ptr;

            this->size = other.size;
            this->ptr = other.ptr;

            other.ptr = nullptr;
            other.size = 0;

            return *this;
        }

        Array(const Array& other){
            std::cout << "Array(const Array&)" << std::endl;
            if(this == &other || other.ptr == nullptr) return;

            delete[] ptr;

            this->ptr = new(std::nothrow) int[other.size];
            if(!this->ptr){
                std::cout << "Error! Not enough memory" << std::endl;
                return;
            }

            this->size = other.size;
            
            for(int i = 0;i < size;i++)
                this->ptr[i] = other.ptr[i];           
        }

        Array& operator=(const Array& other) noexcept{
            std::cout << "Array& operator=(const Array&)" << std::endl;
            if(this == &other || other.ptr == nullptr) return *this;

            delete[] ptr;

            this->ptr = new(std::nothrow) int[other.size];
            if(!this->ptr){
                std::cout << "Error! Not enough memory" << std::endl;
                return *this;
            }

            this->size = other.size;
            
            for(int i = 0;i < size;i++)
                this->ptr[i] = other.ptr[i];     

            return *this;
        }


        int getSize(){
            return size;
        }

        const int* data() const{
            return ptr;
        }

        int* data(){
            return ptr;
        }

        
};

int main(){
    Array arr0{5};
    Array arr1 = std::move(arr0);
    return 0;
}
