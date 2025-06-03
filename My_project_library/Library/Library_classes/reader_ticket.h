#pragma once
#include "../Include/tvector.h"
#include "books.h"
#include "book.h"
class Ticket {
private:
    size_t _ticket_id;
    Books _books_on_hand_list;
public:
    size_t get_id() const {
        return _ticket_id;
    }
    const Books& get_books_on_hand_list() {
        return _books_on_hand_list;
    }
    void add_book(const Book& book) {
        _books_on_hand_list.add_book(book);
    }
    void delete_book(const std::string& book_id) {
        _books_on_hand_list.delete_book(book_id);
    }
    size_t get_books_on_hand_list_size() {
        return _books_on_hand_list.get_books_list_size();
    }
};
