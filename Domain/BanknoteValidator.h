//
// Created by lucia on 5/18/2022.
//

#ifndef LAB09_10_BANKNOTEVALIDATOR_H
#define LAB09_10_BANKNOTEVALIDATOR_H
#include "Banknote.h"
class BanknoteValidator {
public:
    void validate(Banknote banknote){
        if(banknote.getIndex() <= 0 || banknote.getIndex() > INT_MAX) {
            throw MyException("Banknote ID must be positive.");
        }
        else if(banknote.getValue() != 0.01 && banknote.getValue() != 0.05 && banknote.getValue() != 0.10 && banknote.getValue() != 0.50 && banknote.getValue() != 1 && banknote.getValue() != 5 &&
                banknote.getValue() != 10 && banknote.getValue() != 50 && banknote.getValue() != 100 && banknote.getValue() != 200 && banknote.getValue() != 500) {
            throw MyException("This vending machine only accepts banknotes with a value of 0.01, 0.05, 0.10, 0.5, 1, 5, 10, 50 or 100 RON.");
        }
        else if(banknote.getNoOccurrences() < 0 || banknote.getNoOccurrences() > INT_MAX) {
            throw MyException("The number of occurrences of a banknote must be positive!");
        }
    }
};
#endif //LAB09_10_BANKNOTEVALIDATOR_H
