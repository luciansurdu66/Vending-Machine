

#ifndef LAB09_10_MONEY_H
#define LAB09_10_MONEY_H


#include <ostream>

class Money {
private:
    int id, money, number;
public:
    Money();

    Money(int i, int m, int n);

    ~Money();

    void set_money(int m);

    int get_money();

    void set_number(int n);

    int get_number();

    void set_id(int i);

    int get_id();

    friend std::ostream& operator<<(std::ostream& os, Money& m);

    Money& operator=(const Money& mon);

    bool operator==(const Money& mon);
};


#endif //LAB09_10_MONEY_H
