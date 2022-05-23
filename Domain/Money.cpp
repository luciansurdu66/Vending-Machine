//
// Created by lucia on 5/18/2022.
//

#include "Money.h"

Money::Money() {
    this->id = 0;
    this->money = 0;
    this->number = 0;
}

Money::Money(int i, int m, int n) {
    this->id = i;
    this->money = m;
    this->number = n;
}

void Money::set_money(int m) {
    this->money = m;
}

int Money::get_money() {
    return this->money;
}

void Money::set_number(int n) {
    this->number = n;

}

int Money::get_number() {
    return this->number;
}

void Money::set_id(int i) {
    this->id = i;
}

int Money::get_id() {
    return this->id;
}


bool Money::operator==(const Money &mon) {
    return this->money == mon.money && this->id == mon.id && this->number == mon.number;
}

Money &Money::operator=(const Money &mon) {
    this->set_id(mon.id);
    this->set_money(mon.money);
    this->set_number(mon.number);
    return *this;
}

std::ostream &operator<<(std::ostream &os, Money &m) {
    os << m.id << " " << m.money << " " << m.number << std::endl;
    return os;
}

Money::~Money() = default;
