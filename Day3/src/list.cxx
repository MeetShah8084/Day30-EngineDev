#include<list.hpp>
#include<memory>
#include<iostream>

Node::Node(){}

Node::Node(const int& _data){
    this->data = _data;
}

Node::Node(const Node& obj){
    this->data = obj.data;
}

Node::~Node(){
    prev = nullptr;
}


void Node::pushBack(int _data){
    if(this->next == nullptr){
        this->next = std::unique_ptr<Node>(new Node(_data));
        this->next->prev = this; 
        return;
    }
    
    Node* obj = this;
    while(obj->next != nullptr){
        obj = obj->next.get();
    }

    obj->next = std::unique_ptr<Node>(new Node(_data));
    obj->next->prev = obj;
    
}

void Node::pushBack(Node& obj){
    if(this->next == nullptr){
        this->next = std::unique_ptr<Node>(new Node(obj));
        this->next->next->prev = this->next.get();
        return;   
    }

    Node* _obj = this;
    while(_obj->next != nullptr){
        _obj = _obj->next.get();
    }

    _obj->next = std::unique_ptr<Node>(new Node(obj));
    _obj->next->prev = _obj;
}


void Node::printForward(){
    if(this->next == nullptr) {
        std::cout << this->data << std::endl;
        return;
    }
    Node* obj = this;
    int counter = 0;
    while(obj != nullptr){
        std::cout << counter++  << "> " << obj->data <<std::endl;
        obj = obj->next.get();
    }
}

void Node::popBack(){
    if(this->next == nullptr){
        std::cout << data << std::endl;
        return;
    }

    Node* obj = this;
    while(obj->next != nullptr){
        obj = obj->next.get();
    }

    while(obj->prev != nullptr){
        std::cout << obj->data << std::endl;
        obj = &(*(obj->prev)) ;
    }

}


