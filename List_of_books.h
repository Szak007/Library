#pragma once
#include "Book.h"
#include <algorithm>
template<typename T>
class list_of_books {
private:
    std::list<T> books;
    

public:
    std::list<T> get_books() const {
        return books;
    }
    void add_book(const T& book) {
        books.push_back(book);
    }

    void display_books() const {
        std::cout << "\nBooks:\n";
     
        for (const auto& a : books) {
            std::cout << "\nID: " << a.get_id()
                << ", Title: " << a.get_title()
                << ", Author: " << a.get_author()
                << ", Genre: " << a.get_genre()
                << ", Year: " << a.get_year()
                << ", Borrowed: " << (a.get_borrowed() ? "Yes" : "No") << std::endl;
        }
    }

    void load_books_file(const std::string& file_path) {
        std::ifstream file_stream(file_path);
        std::string line;
        std::getline(file_stream, line);
        std::list<T> books;

        if (!file_stream) {
            std::cerr << "Cannot open file: " << file_path << std::endl;
            this->books = books;
        }

        while (getline(file_stream, line)) {
            std::istringstream ss(line);
            std::vector<std::string> book_data;
            std::string data;
            while (getline(ss, data, ';')) {
                book_data.push_back(data);
            }
            if (book_data.size() == 6) {
                int id = stoi(book_data[0]);
                std::string title = book_data[1];
                std::string author = book_data[2];
                std::string genre = book_data[3];
                int year = book_data[4].empty() ? 0 : stoi(book_data[4]);
                bool borrowed = (book_data[5] == "0") ? false : true;
                books.push_back(T{ id, title, author, genre, year, borrowed });

            }
        }
        this->books = books;
    }

    void save_to_file() {
        std::ofstream file_output("file_output.txt");
        for (const auto& i : books) {
            const T& book = i;
            file_output << book.get_id() << ";"
                << book.get_title() << ";"
                << book.get_author() << ";"
                << book.get_genre() << ";"
                << book.get_year() << ";"
                << book.get_borrowed() << "\n";
        }
        file_output.close();
    }


    
    
    
    void save_List_To_Bin_File() {
        std::ofstream outFile("output.bin", std::ios::binary);
        if (!outFile) {
            std::cerr << "Error: Couldn't open file for writing: " << "output.bin" << std::endl;
            return;
        }

        
        size_t numElements = books.size();
        outFile.write(reinterpret_cast<const char*>(&numElements), sizeof(numElements));

        
        for (const auto& element : books) {
            outFile << element; 
        }

        outFile.close();
    }

    void load_books_file_from_bin() {
        std::ifstream fileStream("output.bin", std::ios::binary);
        if (!fileStream) {
            std::cerr << "Cannot open file: " << "output.bin" << std::endl;
            return;
        }

       
        size_t numElements;
        fileStream.read(reinterpret_cast<char*>(&numElements), sizeof(numElements));

        std::list<Book> books;

    
        for (size_t i = 0; i < numElements; ++i) {
            books.push_back(Book::fromBinary(fileStream));
        }

     
        this->books = books;
    }


    


    void sort_books_by(std::string(T::* sth)() const) {
        books.sort([=](const T& a, const T& b) {
            return (a.*sth)() < (b.*sth)();
            
            });
    }


    void sort_books_by_year() {
        books.sort([](const T& a, const T& b) {
            return a.get_year() < b.get_year();
            });
    }

    void sort_books_by_borrowed() {
        books.sort([](const T& a, const T& b) {
            
            if (a.get_borrowed() && !b.get_borrowed())
                return true;
            
            if (!a.get_borrowed() && b.get_borrowed())
                return false;
           
            return a.get_title() < b.get_title();
            });
    }

    std::list<T> find_books_by(std::string(T::* sth)() const, const std::string& value) const {
        std::list<T> result;
    
        
        std::for_each(books.begin(), books.end(), [value, &result, sth](const T& book) {
            if ((book.*sth)() == value) {
                result.push_back(book);
            }
            });

        return result;
    }

    std::list<T> find_books_by_id(int id) const {
        std::list<T> result;
        for (const auto& book : books) {
            if (book.get_id() == id) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::list<T> find_books_by_title(const std::string& title) const {
        std::list<T> result;
        for (const auto& book : books) {
            if (book.get_title() == title) {
                result.push_back(book);
            }
        }
        return result;
    }

    

    std::list<T> find_books_by_year(int year) const {
        std::list<T> result;
        for (const auto& book : books) {
            if (book.get_year() == year) {
                result.push_back(book);
            }
        }
        return result;
    }

    std::list<T> find_borrowed_books() const {
        std::list<T> result;
        for (const auto& book : books) {
            if (book.get_borrowed()) {
                result.push_back(book);
            }
        }
        return result;
    }

};