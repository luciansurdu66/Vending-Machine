//
// Created by lucia on 5/2/2022.
//

#ifndef LAB09_10_REPOFILEPRODUCT_H
#define LAB09_10_REPOFILEPRODUCT_H
#include <string>
#include <fstream>
#include "RepoProduct.h"
#include "../Domain/Product.h"
using namespace std;

class RepoFileProduct : public RepoProduct {
private:
    string filename;
public:
    RepoFileProduct();
    RepoFileProduct(const string& file_name);
    ~RepoFileProduct();
    void add_save(const Product& product);
    void remove_save(const Product& product);
    void update_save(const Product& old, const Product& newp);

    void save();
};



#endif //LAB09_10_REPOFILEPRODUCT_H
