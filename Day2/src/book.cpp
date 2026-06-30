#include<book.hpp>
#include<iostream>
#include<algorithm>

int Book::counter = 0;

Book::Book(){
    this->id = ++counter;
    int count = 0;
    this->name = {};
    this->author = {};
}

Book::Book(const Book& other){
    this->name = other.name;
    this->id = ++counter;
    this->author = other.author;
    this->count = other.count;
}

Book::Book(Book&& other){
    if(this == &other) return;
    this->name = std::move(other.name);
    this->author = std::move(other.author);
    this->id = other.id;
    this->count = other.count;
    other.name = "";
    other.author = "";
    other.id = 0;
    other.count = 0;
}


Book& Book::operator=(const Book& other){
    this->author = other.author;
    this->id = other.id;
    this->name = other.name;
    this->count = other.count;        
    return *this;
}

Book& Book::operator=(Book&& other){

    if(this == &other) return *this;

    this->author = std::move(other.author);
    this->name = std::move(other.name);
    this->id = other.id;
    this->count = other.count;  

    return *this;
}

Book::Book(int count, const std::string& name, const std::string& author){
    this->id = ++counter;
    this-> count = count;
    this->name = name;
    this->author = author;
}




void Library::addBook(int count,const std::string& name,const std::string& author){
    auto owned = std::make_unique<Book>(count,name,author);
    lendable.push_back(std::move(owned));
    std::cout << "[Library]: Added book: " << name << std::endl;
}


std::weak_ptr<Book> Library::lendBook(const std::string& name){
    auto it = std::find_if(lendable.begin(),lendable.end(),[&name](const std::shared_ptr<Book>& b){
        return b->name == name;
    });

    if(it != lendable.end()){
        if((*it)->is_borrowed){
            std::cout << "Already borrowed!!! ::: " << (*it)->name << std::endl;
            return {};
        }
        (*it)->is_borrowed = true;
        return std::weak_ptr<Book>(*it);
    }
    return {};
}

void Library::removeBook(const std::string& name){
    auto it = std::find_if(lendable.begin(),lendable.end(),[&name](const std::shared_ptr<Book>& b){
        return b->name == name;
    });

    if(it == lendable.end()){
        std::cout << "[Library] Book not found!! >> " << name << std::endl;
        return;
    }

    std::cout << "[Library]: Removing book: " << name << std::endl;
    lendable.erase(it);

}

void Library::listBook(){
    
    std::cout << "List of books available: \n";
    
    int i = 0;
    for(auto a: lendable){
        if(!a->is_borrowed)
        std::cout << ++i <<"> " << a->name << "\tAuthor:" << a->author << std::endl; 
    }

}

Reader::Reader(const std::string& name): name(name){}

void Reader::borrow(std::weak_ptr<Book> b){
    brwBook = b;
}

void Reader::read() const{
    if(!brwBook.expired()){
        std::cout << "[Meet] started reading " << brwBook.lock()->name << std::endl;
    }else{
        std::cout << "Book << "  <<" >>" <<  " not available" << std::endl;
    }
}

