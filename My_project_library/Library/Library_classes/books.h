#pragma once
#include "../Include/tvector.h"
#include "book.h"
#include <utility> 
class Books {
private:
    Tvector <std::pair<Book, size_t>> _books_list;
public:
    void add_book(const Book& book);
    void delete_book(const std::string& book_id);
    Tvector<Book> find_books(const std::string& book_name);
    void get_book();
    void return_book();
    void show_book_info();
};
