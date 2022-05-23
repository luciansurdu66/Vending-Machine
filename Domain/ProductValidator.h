//
// Created by lucia on 5/18/2022.
//

#ifndef LAB09_10_PRODUCTVALIDATOR_H
#define LAB09_10_PRODUCTVALIDATOR_H
#include "Product.h"
#include "MyException.h"

class ProductValidator {
public:
    void validate(Product product){
        if(product.getIndex() <= 0 || product.getIndex() > INT_MAX) {
            throw MyException("Product ID must be positive.");
        }
        else if(product.getCode() < 0 || product.getIndex() > INT_MAX) {
            throw MyException("Product code must be positive.");
        }
        else if(product.getName().size() == 0) {
            throw MyException("Product name size must be greater than 0.");
        }
        else if(product.getPrice() <= 0) {
            throw MyException("Product price must be positive.");
        }
    }
};
#endif //LAB09_10_PRODUCTVALIDATOR_H
