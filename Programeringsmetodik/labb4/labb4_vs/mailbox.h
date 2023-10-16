#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
#include "email.h"
class mailBox {
private:
    std::vector<Email> emailContainer;

public:
    mailBox(std::vector<Email> emailContainer);
    ~mailBox();

    std::vector<Email>& SortWho();
    std::vector<Email>& SortDate();
    std::vector<Email>& SortSubject();

    void write(Email msg);
    std::vector<Email> read();
};



#endif