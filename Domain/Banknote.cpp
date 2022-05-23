//
// Created by lucia on 5/18/2022.
//
#include <iostream>
#include <vector>
#include <sstream>
#include "Banknote.h"
Banknote::Banknote() {
    this->index = 0;
    this->value = 0;
    this->noOccurrences = 0;
}

Banknote::Banknote(std::string args, char sep) {
    this->loadFromString(args, sep);
}

Banknote::Banknote(unsigned int index, double value, unsigned int noOccurrences) {
    this->index = index;
    this->value = value;
    this->noOccurrences = noOccurrences;
}

Banknote::Banknote(const Banknote &banknote) {
    this->index = banknote.index;
    this->value = banknote.value;
    this->noOccurrences = banknote.noOccurrences;
}

Banknote::~Banknote() = default;

unsigned int Banknote::getIndex() {
    return this->index;
}

void Banknote::setIndex(unsigned int index) {
    this->index = index;
}

double Banknote::getValue() {
    return this->value;
}

void Banknote::setValue(double value) {
    this->value = value;
}

unsigned int Banknote::getNoOccurrences() {
    return this->noOccurrences;
}

void Banknote::setNoOccurrences(unsigned int noOccurrences) {
    this->noOccurrences = noOccurrences;
}

std::string Banknote::toStringDelimiter(char sep) {
    return std::to_string(this->index) + sep + std::to_string(this->value) + sep + std::to_string(this->noOccurrences);
}

void Banknote::loadFromString(std::string args, char sep) {
    std::vector<std::string> elements;
    std::stringstream ss(args);
    std::string object;
    while (getline(ss, object, sep)) {
        elements.push_back(object);
    }
    if(elements.size() == 3) {
        std::stringstream i(elements[0]);
        i >> this->index;
        std::stringstream v(elements[1]);
        v >> this->value;
        std::stringstream o(elements[2]);
        o >> this->noOccurrences;
    }
}

Banknote &Banknote::operator=(const Banknote &banknote) {
    this->index = banknote.index;
    this->value = banknote.value;
    this->noOccurrences = banknote.noOccurrences;
    return *this;
}

std::istream &operator>>(std::istream &is, Banknote &banknote) {
    unsigned int index;
    std::cout << "Enter banknote index:";
    if(is >> index) {
        banknote.index = index;
    }
    else {
        is.clear();
        is.ignore(10000, '\n');
        throw MyException("Id must be a positive number.");
    }

    double value;
    std::cout << "Banknote value:"; is >> value;
    banknote.value = value;

    unsigned int noOccurrences;
    std::cout << "Number of banknotes:";
    if(is >> noOccurrences) {
        banknote.noOccurrences = noOccurrences;
    }
    else {
        is.clear();
        is.ignore(10000, '\n');
        throw MyException("Number of occurrences must be a positive number.");
    }

    return is;
}

bool Banknote::operator==(const Banknote &banknote) const {
    return index == banknote.index &&
           value == banknote.value &&
           noOccurrences == banknote.noOccurrences;
}

bool Banknote::operator!=(const Banknote &banknote) const {
    return !(banknote == *this);
}

std::ostream &operator<<(std::ostream &os, const Banknote &banknote) {
    std::cout << "Banknote index: " << banknote.index << " Banknote value: " << banknote.value
              << " Number of occurrences: " << banknote.noOccurrences << '\n';
    return os;
}