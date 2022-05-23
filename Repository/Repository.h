//
// Created by lucia on 5/18/2022.
//

#ifndef LAB09_10_REPOSITORY_H
#define LAB09_10_REPOSITORY_H
#include <vector>
#include "IRepository.h"

template<class T> class Repository : public IRepository<T> {
private:
    std::vector<T> entities;
public:
    /**
     * Constructor
     */
    Repository() = default;

    /**
     * Copy-constructor
     * @param repository: Repository object
     */
    Repository(const Repository<T> &repository) {
        this->entities = repository.entities;
    }

    /**
     * Destructor
     */
    ~Repository() = default;

    /**
     * Add entity to repository
     * @param entity: T class object
     */
    void addEntity(T entity) override {
        this->entities.push_back(entity);
    }

    /**
     * Update an entity from repository
     * @param index: int - entity location in repository
     * @param newEntity: T class object - updated entity
     */
    void updateEntity(unsigned int index, T newEntity) override {
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getIndex() == index) {
                entities[i] = newEntity;
            }
        }
    }

    /**
     * Delete an entity from repository
     * @param index: int - entity location in repository
     */
    void deleteEntity(unsigned int index) override {
        int position;
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getIndex() == index) {
                position = i;
            }
        }
        entities.erase(entities.begin() + position);
    }

    /**
     * Get all entities and returns them
     * @return: Vector<class T> - all entities stored in repository
     */
    std::vector<T> getAll() override {
        return this->entities;
    }

    /**
     * Get position by object index
     * @param index: unsigned int - object index
     * @return: int - object position
     */
    int getPosByIndex(unsigned int index) override {
        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].getIndex() == index) {
                return i;
            }
        }
        return -1;
    }
};
#endif //LAB09_10_REPOSITORY_H