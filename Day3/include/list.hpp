#ifndef LIST_HPP

    #define LIST_HPP

    #include<memory>

    class Node{
        private:
            Node* prev;
            std::unique_ptr<Node> next{nullptr};
        public:
            int data{};
            Node();
            Node(const int& data);
            ~Node();
            
            void pushBack(int _data);
            void pushBack(Node& obj);

            void popBack();

            void printForward();
            void printBackward();


            Node(const Node& obj);
            Node& operator=(const Node& obj) = delete;
            

    };


#endif