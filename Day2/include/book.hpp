#ifndef __book__hpp
    #define __book__hpp

#ifdef _WIN32
    #ifdef librarySystem_EXPORTS
        #define LIBRARY_EXPORT __declspec(dllexport)
    #else
        #define LIBRARY_EXPORT __declspec(dllimport)   
    #endif
#else
    #define LIBRARY_EXPORT
#endif

        #include<string>
        #include<memory>
        #include<vector>

        class LIBRARY_EXPORT Library;

            class LIBRARY_EXPORT Book{
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

                    Book(Book&& other) noexcept;

                    Book& operator=(const Book& other);
                    Book& operator=(Book&& other) noexcept;

                    ~Book(){
                        counter-=1;
                    }

                    Book(int count, const std::string& name, const std::string& author);

                    

            };


            class LIBRARY_EXPORT Library{               
                public:
                    std::vector<std::shared_ptr<Book>> lendable;
                    std::weak_ptr<Book> lendBook(const std::string& name);
                    void addBook(int count,const std::string& name,const std::string& author);
                    void removeBook(const std::string& name);
                    void listBook();
                    
            };

            class LIBRARY_EXPORT Reader{
                private:
                    std::weak_ptr<Book> brwBook;
                    std::string name;
                public:
                    Reader(const std::string& name);
                    void borrow(std::weak_ptr<Book> b);
                    void read() const;
            };

#endif