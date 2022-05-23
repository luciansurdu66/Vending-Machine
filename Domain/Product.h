//
// Created by lucia on 4/19/2022.
//

#ifndef LAB09_10_PRODUCT_H
#define LAB09_10_PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    unsigned int id;
    unsigned int code;
    string name;
    unsigned int price;
public:
    ~Product();

    Product(const Product& product);

    Product(unsigned int id, unsigned int code, const string &name, unsigned int price);

    Product(std::string args, char sep);

    unsigned int getIndex() const;

    Product();

    unsigned int getCode() const;

    const string &getName() const;

    unsigned int getPrice() const;

    void setCode(unsigned int code);

    void setName(const string &name);

    void setPrice(unsigned int price);

    bool operator==(const Product &rhs) const;

    bool operator!=(const Product &rhs) const;

    bool operator<(const Product &rhs) const;

    bool operator>(const Product &rhs) const;

    bool operator<=(const Product &rhs) const;

    bool operator>=(const Product &rhs) const;

    friend ostream &operator<<(std::ostream &os, const Product &product);

    void setId(unsigned int id);

    void loadFromString(string args, char sep);

    string toStringDelimiter(char sep);
};


#endif //LAB09_10_PRODUCT_H
