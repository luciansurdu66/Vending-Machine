//
// Created by lucia on 4/19/2022.
//

#include "RepoProduct.h"
/**
     * Constructor
     */
RepoProduct::RepoProduct() = default;

/**
 * Copy-constructor
 * @param repository: Repository object
 */
RepoProduct::RepoProduct(const RepoProduct &repository) {
    this->entities = repository.entities;
}

/**
 * Destructor
 */
RepoProduct::~RepoProduct() = default;

/**
 * Add entity to repository
 * @param entity: T class object
 */
void RepoProduct::addEntity(const Product& entity) {
    this->entities.push_back(entity);
}

/**
 * Update an entity from repository
 * @param index: int - entity location in repository
 * @param newEntity: T class object
 */
void RepoProduct::updateEntity(const Product& old_product, Product newEntity) {
    for(auto & entitie : entities){
        if(entitie.getIndex() == old_product.getIndex()){
            newEntity.setId(old_product.getIndex());
            entitie = newEntity;
        }
    }
}

/**
 * Delete an entity from repository
 * @param index: int - entity location in repository
 */
void RepoProduct::deleteEntity(Product product) {
    Product to = getById(product.getIndex());
    for(int i = 0; i < entities.size(); i++){
        if(entities[i].getIndex() == product.getIndex()){
            entities.erase(entities.begin() + i);
        }
    }
}

/**
 * Get all entities and returns them
 * @return: Vector<class T> - all entities stored in repository
 */
std::vector<Product> RepoProduct::getAll() {
    return this->entities;
}

/**
 * Get product by id
 * @param code: unsigned int - product code
 * @return: int - product position
 */

Product RepoProduct::getById(unsigned int id){
    for(Product &p: entities){
        if(p.getIndex() == id){
            return p;
        }
    }
    throw runtime_error("No entity with such id!");
}