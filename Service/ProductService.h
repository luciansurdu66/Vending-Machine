//
// Created by lucia on 4/19/2022.
//

#ifndef LAB09_10_PRODUCTSERVICE_H
#define LAB09_10_PRODUCTSERVICE_H
#include "../Repository/RepoProduct.h"
#include "../Repository/RepoFileProduct.h"
#include "../Repository/RepositoryInFile.h"
#include "../Domain/ProductValidator.h"
class ProductService {
private:
    ProductValidator validator;
    IRepository<Product> &repository;
public:
    ProductService(IRepository<Product> &iRepository);
    ~ProductService();
    void create(Product product) ;

    vector<tuple<unsigned int, unsigned int>> count_products();
    int sum_jukebox();

    Product get_by_code(unsigned int code);

    vector<Product> showUniqueProducts();

    bool doesExist(unsigned int index);

    unsigned int numberOfProductsByName(string productName);

    void del(unsigned int index);

    void update(unsigned int index, Product newEntity);

    Product read(unsigned int index);

    vector<Product> read();
};


#endif //LAB09_10_PRODUCTSERVICE_H
