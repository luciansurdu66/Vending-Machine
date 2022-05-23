//
// Created by lucia on 4/19/2022.
//

#include <vector>
#include <sstream>
#include "Product.h"

Product::Product() {
    this->code = 0;
    this->price = 0;
}

Product::Product(unsigned int id, unsigned int code, const string &name, unsigned int price) : code(code), name(name), price(price) {
    this->id = id;
    this->code = code;
    this->name = name;
    this->price = price;
}

Product::Product(const Product &product) {
    this->code = product.code;
    this->name = product.name;
    this->price = product.price;
    this->id = product.id;
}

unsigned int Product::getCode() const {
    return code;
}

void Product::setCode(unsigned int code) {
    Product::code = code;
}

bool Product::operator==(const Product &rhs) const {
    return code == rhs.code &&
           name == rhs.name &&
           price == rhs.price;
}

bool Product::operator<(const Product &rhs) const {
    if(this->name == rhs.name) {
        if(this->price < rhs.price) {
            return true;
        }
        if(this->price > rhs.price) {
            return false;
        }
    }
    return false;
}


bool Product::operator>(const Product &rhs) const {
    return rhs < *this;
}

bool Product::operator<=(const Product &rhs) const {
    return !(rhs < *this);
}

bool Product::operator>=(const Product &rhs) const {
    return !(*this < rhs);
}

bool Product::operator!=(const Product &rhs) const {
    return !(rhs == *this);
}

void Product::setName(const string &name) {
    Product::name = name;
}

void Product::setPrice(unsigned int price) {
    Product::price = price;
}

const string &Product::getName() const {
    return name;
}

unsigned int Product::getPrice() const {
    return price;
}

unsigned int Product::getIndex() const {
    return id;
}

void Product::setId(unsigned int id) {
    Product::id = id;
}

std::istream &operator>>(std::istream &is, Product &product) {
    unsigned int code;
    cout << "Enter product code:";
    is >> code;
    product.setCode(code);

    std::string name;
    std::cout << "Enter product name:"; is >> name;
    product.setName(name);

    unsigned int price;
    std::cout << "Enter product price:"; is >> price;
    product.setPrice(price);

    return is;
}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os <<"Product id: " << product.getIndex()<< "| Product code: " << product.getCode() <<
             "| Product name: " << product.getName() << "| Product price: " <<
             product.getPrice() << '\n';

    return os;
}
std::string Product::toStringDelimiter(char sep) {
    return std::to_string(this->id) + sep +std::to_string(this->code) +
           sep + this->name + sep + std::to_string(this->price);
}
void Product::loadFromString(std::string args, char sep) {
    std::vector<std::string> elements;
    std::stringstream ss(args);
    std::string object;
    while (getline (ss, object, sep)) {
        elements.push_back(object);
    }
    if(elements.size() == 4) {
        std::stringstream i(elements[0]);
        i >> this->id;
        std::stringstream c(elements[1]);
        c >> this->code;
        this->name = elements[2];
        std::stringstream p(elements[3]);
        p >> this->price;
    }
}

Product::Product(std::string args, char sep) {
    this->loadFromString(args, sep);
}

Product::~Product() = default;
