#ifndef __book__hpp
    #define __book__hpp

        #include<string>
        #include<memory>
        #include<vector>

        class Library;

            class Book{
                friend class Library;

                private:
                    static int counter;
                    int id; 
                    bool is_borrowed{false};

                public:
                    int count;
                    std::string name;
                    std::string author;

                    Book();

                    Book(const Book& other);

                    Book(Book&& other);

                    Book& operator=(const Book& other);
                    Book& operator=(Book&& other);

                    ~Book(){
                        counter-=1;
                    }

                    Book(int count, const std::string& name, const std::string& author);

                    

            };


            class Library{
                private:
                    std::vector<std::unique_ptr<Book>> books;
                
                public:
                    std::vector<std::shared_ptr<Book>> lendable;
                    std::weak_ptr<Book> lendBook(const std::string& name);
                    void addBook(int count,const std::string& name,const std::string& author);
                    void removeBook(const std::string& name);
                    void listBook();
                    
            };

            class Reader{
                private:
                    std::weak_ptr<Book> brwBook;
                    std::string name;
                public:
                    Reader(const std::string& name);
                    void borrow(std::weak_ptr<Book> b);
                    void read() const;
            };

#endif