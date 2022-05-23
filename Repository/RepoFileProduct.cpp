//
// Created by lucia on 5/2/2022.
//

#include "RepoFileProduct.h"
RepoFileProduct::RepoFileProduct() = default;
RepoFileProduct::RepoFileProduct(const string& file_name){
    this->filename = file_name;
    ifstream f(file_name);
    while(!f.eof()){
        unsigned int id, pret, cod;
        string name;
        f >> id >> cod >> name >> pret;
        if(!name.empty()){
            Product p(id, cod, name, pret);
            this->entities.push_back(p);
        }
    }
}

RepoFileProduct::~RepoFileProduct() = default;

void RepoFileProduct::save() {
    ofstream g(this->filename);
    for(const Product& p: entities){
        g <<' '<< p.getIndex()<<' '<<p.getCode() <<' '<<p.getName() <<' '<< p.getPrice();
        g<<"\n";
    }
    g.close();
}

void RepoFileProduct::add_save(const Product &product) {
    this->addEntity(product);
    this->save();
}

void RepoFileProduct::remove_save(const Product &product) {
    this->deleteEntity(product);
    this->save();
}

void RepoFileProduct::update_save(const Product &old, const Product &newp) {
    this->updateEntity(old, newp);
    this->save();
}

