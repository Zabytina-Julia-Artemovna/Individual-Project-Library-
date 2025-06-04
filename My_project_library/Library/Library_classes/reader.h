#pragma once
#include "person.h"
#include "reader.h"
#include "reader_ticket.h"
class Reader: public Person {
private:
    Ticket _readers_ticket;
public:
};