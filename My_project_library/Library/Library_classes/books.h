#pragma once
#include "../Include/tvector.h"
#include "book.h"
#include <utility> 

class Ticket;
class Books {
private:
    Tvector <std::pair<Book, size_t>> _books_list;
public:
    void add_book(const Book& book);
    void delete_book(const std::string& book_id);
    Tvector<Book> find_books(const std::string& book_name);
    size_t get_books_list_size() {
        return _books_list.get_size();
    }
    void get_book(const std::string& book_id, Ticket& ticket);
    void return_book(const std::string& book_id, Ticket& ticket); //надо по ссылке Ticket
};
