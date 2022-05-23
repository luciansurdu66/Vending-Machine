//
// Created by lucia on 4/19/2022.
//

#ifndef LAB09_10_REPOPRODUCT_H
#define LAB09_10_REPOPRODUCT_H


#include <ostream>
#include <cstring>
#include <vector>
#include "../Domain/Product.h"
#include "IRepository.h"
class RepoProduct{
private:
protected:
    std::vector<Product> entities;
public:

    /**
     * Constructor
     */
    RepoProduct();

    /**
     * Copy-constructor
     * @param repository: Repository object
     */
    RepoProduct(const RepoProduct &repository);


    /**
     * Destructor
     */
    ~RepoProduct();

    /**
     * Add entity to repository
     * @param entity: T class object
     */
    void addEntity(const Product& p);

    /**
     * Update an entity from repository
     * @param index: int - entity location in repository
     * @param newEntity: T class object
     */
    void updateEntity(const Product& old_prod, Product product);

    /**
     * Delete an entity from repository
     * @param index: int - entity location in repository
     */
    void deleteEntity(Product product);

    /**
     * Get all entities and returns them
     * @return: Vector<class T> - all entities stored in repository
     */
    std::vector<Product> getAll();

    Product getById(unsigned int id);
};



#endif //LAB09_10_REPOPRODUCT_H
