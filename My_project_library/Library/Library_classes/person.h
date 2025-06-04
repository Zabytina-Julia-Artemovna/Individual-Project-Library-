#pragma once
#include <iostream>
#include "fio.h"
#include "passport_data.h"
class Person {
private:
    std::string _phone_number;
    std::string _date_of_birth;
    FIO _fio;
    Passport _passport_data;
public:
    const std::string get_phone_number() {
        return _phone_number;
    }
    const std::string get_date_of_birth() {
        return _date_of_birth;
    }
    const FIO& get_fio() {
        return _fio;
    }
    const Passport& get_passport_data() {
        return _passport_data;
    }
};