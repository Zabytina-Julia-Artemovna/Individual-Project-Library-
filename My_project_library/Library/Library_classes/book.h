#pragma once
#include <iostream>
class Book {
private:
    enum State{ on_hands, reserved, free};
    size_t year_of_publication;
    size_t count_books;
    size_t _id;
    std::string author;
    std::string book_name;
    std::string publishing_house;
    std::string _language;
public:
   
};
