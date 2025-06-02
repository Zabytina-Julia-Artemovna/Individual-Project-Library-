#pragma once
#include "../Include/tvector.h"
#include "books.h"
#include "book.h"
class Ticket {
private:
    size_t _ticket_id;
    Books _reserved_books_list;
    Books _books_on_hand_list;
public:
    size_t get_id() const {
        return _ticket_id;
    }
    Books& get_reserved_books_list() {
        return _reserved_books_list;
    }
    Books& get_books_on_hand_list() {
        return _books_on_hand_list;
    }
};
