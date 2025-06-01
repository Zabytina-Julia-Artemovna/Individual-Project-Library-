#pragma once
#include "../Include/tvector.h"
#include "book.h"
class Books {
private:
    Tvector<Book> _books_list;
    size_t _books_list_size;
public:
    void add_book();
    void delete_book(const std::string& book_id);
    const Books& find_book(const std::string& book_name);
};
