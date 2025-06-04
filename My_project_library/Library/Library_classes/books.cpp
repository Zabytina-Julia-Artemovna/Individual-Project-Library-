#include "books.h"
#include "reader_ticket.h"
#include "book.h"
#include "reader_ticket.h"

void Books::add_book(const Book& book, size_t count) {
    bool bookFound = false;
    for (size_t i = 0; i < _books_list.get_size(); ++i) {
        if (_books_list.get_data()[i].first.get_book_id() == book.get_book_id()) {
            _books_list.get_data()[i].second += count;
            bookFound = true;
            break;
        }
    }
    if (!bookFound) {
        std::pair<Book, size_t> new_pair;
        new_pair.first = book;
        new_pair.second = count;
        _books_list.push_back(new_pair);
    }
}
void Books::delete_book(const std::string& book_id) {
    for (size_t i = 0; i < _books_list.get_size(); ++i) {
        if (_books_list.get_data()[i].first.get_book_id() == book_id) {
            if (_books_list.get_data()[i].second != 0) {
                _books_list.get_data()[i].second--;
            }
            else {
                _books_list.erase(i);
            }
            break;
        }
    }
}
Tvector<Book> Books::find_books(const std::string& book_name) {
    Tvector<Book> list_of_find_books;
    for (size_t i = 0; i < _books_list.get_size(); ++i) {
        if (_books_list.get_data()[i].first.get_book_name().find(book_name) != std::string::npos) {
            list_of_find_books.push_back(_books_list.get_data()[i].first);
        }
    }
    return list_of_find_books;
}
void Books::get_book(const std::string& book_id, Ticket& ticket) {
    for (size_t i = 0; i < _books_list.get_size(); ++i) {
        if (_books_list.get_data()[i].first.get_book_id() == book_id) {
            if (_books_list.get_data()[i].second != 0) {
                ticket.add_book(_books_list.get_data()[i].first);
                _books_list.get_data()[i].second--;
            }
        }
    }
}
void Books::return_book(const std::string& book_id, Ticket& ticket) {
    for (size_t i = 0; i < ticket.get_books_on_hand_list_size(); ++i) {
        if (_books_list.get_data()[i].first.get_book_id() == book_id) {
            ticket.delete_book(_books_list.get_data()[i].first.get_book_id());
            _books_list.get_data()[i].second++;
        }
    }
}
