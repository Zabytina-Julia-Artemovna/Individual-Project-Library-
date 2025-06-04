#pragma once
#include "../Include/tvector.h"
#include "book.h"
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
class Ticket;
class Books {
private:
    Tvector <std::pair<Book, size_t>> _books_list;
public:
    void add_book(const Book& book, size_t count = 1);
    void delete_book(const std::string& book_id);
    Tvector<Book> find_books(const std::string& book_name);
    size_t get_books_list_size() {
        return _books_list.get_size();
    }
    void get_book(const std::string& book_id, Ticket& ticket);
    void return_book(const std::string& book_id, Ticket& ticket); //надо по ссылке Ticket
    static Books& Instance() {
        static Books b;
        return b;
    }
    std::string to_csv() const {
        std::string res;
        for (size_t i = 0; i < _books_list.get_size(); ++i) {
            res += std::to_string(_books_list.get_data()[i].second);
            res += ",";
            res += _books_list.get_data()[i].first.to_csv_line();
            res += "\n";
        }
        return res;
    }
    void from_csv(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);

            size_t size;
            std::string book_id;
            size_t year_of_publication;
            std::string author;
            std::string language;
            std::string publishing_house;
            std::string book_name;
            std::string token;

            if (!std::getline(iss, token, ',')) continue;
            size = std::stoul(token);

            if (!std::getline(iss, book_id, ',')) continue;

            if (!std::getline(iss, token, ',')) continue;
            year_of_publication = std::stoul(token);
            // Read author (may contain commas, so we need special handling)
            // This assumes author is in quotes if it contains commas
            if (iss.peek() == '"') {
                iss.get(); // skip opening quote
                std::getline(iss, author, '"');
                iss.get(); // skip comma after closing quote
            }
            else {
                std::getline(iss, author, ',');
            }

            std::getline(iss, language, ',');

            std::getline(iss, publishing_house, ',');

            std::getline(iss, book_name);
            add_book(Book(year_of_publication, author, language, publishing_house, book_name), size);
        }
    }
};
