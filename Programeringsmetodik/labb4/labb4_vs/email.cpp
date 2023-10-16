#include "email.h"
#include "mailbox.h"
#include <algorithm>


Email::Email(std::string name, std::string date, std::string subject) :
    who(name), date(date), subject(subject) {}


Email::~Email() {}


std::ostream& operator<< (std::ostream& os, const Email& obj) {

    os << obj.who << " " << obj.date << " " << obj.subject;
    return os;
}

struct CompWhoDateSubject {
    bool operator () (const Email& lhs, const Email& rhs) {

        if (lhs.who == rhs.who) {
            if (lhs.date == rhs.date) {
                return lhs.subject < rhs.subject;
            }
            return lhs.date < rhs.date;
        }
        return lhs.who < rhs.who;
    }
};

struct CompDateWhoSubject {
    bool operator () (const Email& lhs, const Email& rhs) {
        if (lhs.date == rhs.date) {
            if (lhs.who == rhs.who) {
                return lhs.subject < rhs.subject;
            }
            return lhs.who < rhs.who;
        }
        return lhs.date < rhs.date;
    }
};
struct CompSubjectWhoDate {
    bool operator () (const Email& lhs, const Email& rhs) {
        if (lhs.subject == rhs.subject) {
            if (lhs.who == rhs.who) {
                return lhs.date < rhs.date;
            }
            return lhs.who < rhs.who;
        }
        return lhs.subject < rhs.subject;
    }
};


//mailbox

mailBox::mailBox(std::vector<Email> emailContainer) :
    emailContainer(emailContainer) {}

mailBox::~mailBox() {}

std::vector<Email>& mailBox::SortWho() {
    std::sort(emailContainer.begin(), emailContainer.end(), CompWhoDateSubject());
    return emailContainer;
}

std::vector<Email>& mailBox::SortDate() {
    std::sort(emailContainer.begin(), emailContainer.end(), CompDateWhoSubject());
    return emailContainer;
}
std::vector<Email>& mailBox::SortSubject() {
    std::sort(emailContainer.begin(), emailContainer.end(), CompSubjectWhoDate());
    return emailContainer;
}

void mailBox::write(Email msg) {
    emailContainer.push_back(msg);
}

std::vector<Email> mailBox::read() {
    return emailContainer;
}
