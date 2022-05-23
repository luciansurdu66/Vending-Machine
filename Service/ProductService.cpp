//
// Created by lucia on 4/19/2022.
//

#include <tuple>
#include <algorithm>
#include "ProductService.h"
ProductService::ProductService(IRepository<Product>& iRepository) : repository(iRepository) {}
void ProductService::create(Product entity) {
    if(doesExist(entity.getIndex())) {
        throw MyException("There already exist a product with this id.");
    }
    validator.validate(entity);
    repository.addEntity(entity);
}

Product ProductService::read(unsigned int index) {
    if(!doesExist(index)) {
        throw MyException("Product with given id doesn't exist.");
    }
    return repository.getAll()[repository.getPosByIndex(index)];
}

std::vector<Product> ProductService::read() {
    if(repository.getAll().size() == 0) {
        throw MyException("There are no products to show.");
    }
    return repository.getAll();
}

void ProductService::update(unsigned int index, Product newEntity) {
    if(!doesExist(index)) {
        throw MyException("The product that was going to be updated wasn't found.");
    }
    validator.validate(newEntity);
    repository.updateEntity(index, newEntity);
}

void ProductService::del(unsigned int index) {
    if(!doesExist(index)) {
        throw MyException("Product with given id doesn't exist.");
    }
    repository.deleteEntity(index);
}

Product ProductService::get_by_code(unsigned int code) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(repository.getAll()[i].getCode() == code) {
            return repository.getAll()[i];
        }
    }
    return Product(0, 0, "", 0);
}

unsigned int ProductService::numberOfProductsByName(std::string productName) {
    unsigned int numberOfProducts = 0;
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(repository.getAll()[i].getName() == productName) {
            numberOfProducts++;
        }
    }
    return numberOfProducts;
}

std::vector<Product> ProductService::showUniqueProducts() {
    std::vector<Product> result;
    for(int i = 0; i < repository.getAll().size(); i++) {
        bool found = false;
        for(auto & j : result) {
            if(repository.getAll()[i] == j) {
                found = true;
            }
        }
        if(!found) {
            result.push_back(repository.getAll()[i]);
        }
    }
    return result;
}

bool ProductService::doesExist(unsigned int index) {
    for(int i = 0; i < repository.getAll().size(); i++) {
        if(index == repository.getAll()[i].getIndex()) {
            return true;
        }
    }
    return false;
}

int ProductService::sum_jukebox(){
    int sum = 0;
    vector<Product> produse = repository.getAll();
    for(auto product: produse){
        sum += product.getPrice();
    }
    return sum;
}

//int Service::sum_code(unsigned int code) {
//    int sum = 0;
//    vector<Product> produse = repository.getAll();
//    for(int i = 0; i< produse.size();i++){
//        if(produse[i].getCode() == code){
//            sum+=produse[i].getPrice();
//        }
//    }
//    return sum;
//}

vector<tuple<unsigned int, unsigned int>> ProductService::count_products() {
    vector<tuple<unsigned int, unsigned int>> result;
    vector<Product> all = repository.getAll();
    for(int i = 0;i< all.size();i++){
        bool ok = true;
        for(auto currTuple : result){
            if(get<0>(currTuple) == all[i].getCode()){
                ok = false;
            }
        }
        if(ok){
            result.emplace_back(all[i].getCode(), count(all.begin(), all.end(), all[i]));
        }
    }
    return result;
}

ProductService::~ProductService() = default;