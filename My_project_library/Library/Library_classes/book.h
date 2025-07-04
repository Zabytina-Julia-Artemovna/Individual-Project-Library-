#pragma once
#include <string>
#include <cstddef> 
class Book {
private:
    std::string _book_id;
    size_t _year_of_publication;
    std::string _author;
    std::string _language;
    std::string _publishing_house;
    std::string _book_name;
public:
    Book(size_t year_of_publication,
        const std::string& author, const std::string& language,
        const std::string& publishing_house, const std::string& book_name) :
        _book_id(book_name + "_" + author),
        _year_of_publication(year_of_publication),
        _author(author),
        _language(language),
        _publishing_house(publishing_house),
        _book_name(book_name) {};
    Book() = default;
    Book(const Book& other) = default;
    std::string get_book_id() const {
        return _book_id;
    }
    size_t get_year_of_publication() const {
        return _year_of_publication;
    }
    const std::string& get_author() const {
        return _author;
    }
    const std::string& get_language() const {
        return _language;
    }
    const std::string& get_publishing_house() const {
        return _publishing_house;
    }
    const std::string& get_book_name() const {
        return _book_name;
    }
    void set_year_of_publication(size_t year_of_publication) {
        _year_of_publication = year_of_publication;
    }
    void set_author(const std::string& author) {
        _author = author;
    }
    void set_language(const std::string& language) {
        _language = language;
    }
    void set_publishing_house(const std::string& publishing_house) {
        _publishing_house = publishing_house;
    }
    void set_book_name(const std::string& book_name) {
        _book_name = book_name;
    }
    std::string to_csv_line() const {
        return _book_id + "," +
            std::to_string(_year_of_publication) + "," +
            _author + "," +
            _language + "," +
            _publishing_house + "," +
            _book_name;
    }
};
