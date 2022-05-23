//
// Created by lucia on 4/19/2022.
//

#include "Tests.h"
#include "../Domain/Product.h"
#include "../Domain/Banknote.h"
#include "../Repository/RepoProduct.h"
#include "../Repository/Repository.h"
#include "../Service/ProductService.h"
#include "../Service/BanknoteService.h"
#include <cassert>
#include <iostream>

void Tests::all() {

    domain();
    repository();
    service();
    add_entity_file_test();
    delete_entity_file_test();
    update_entity_file_test();
    sum_jukebox_test();
    test_product_service();
    test_banknote_service();
    std::cout << "All tests passed!" << '\n' << '\n';
}

void Tests::domain() {
    Product product;
    assert(product.getCode() == 0);
    assert(product.getPrice() == 0);

    product.setCode(1);
    product.setName("corn");
    product.setPrice(5);
    assert(product.getCode() == 1);
    assert(product.getName() == "corn");
    assert(product.getPrice() == 5);

    Product product1(1,2, "corn", 6);
    assert(product1.getCode() == 2);
    assert(product1.getName() == "corn");
    assert(product1.getPrice() == 6);

    assert(product == product1 == false);

    product = product1;
    assert(product.getCode() == 2);
    assert(product.getName() == "corn");
    assert(product.getPrice() == 6);
}

void Tests::repository() {
    RepoProduct repository;

    Product p1(1, 1, "croissant", 3);
    Product p2(2,2, "suc", 5);
    Product p3(3,3, "ciocolata", 7);
    Product p4(4,4, "popcorn", 4);
    Product p5(5,5, "apa", 3);

    repository.addEntity(p1);
    repository.addEntity(p2);
    repository.addEntity(p3);
    repository.addEntity(p4);
    repository.addEntity(p5);
    assert(repository.getAll()[0] == p1);
    assert(repository.getAll()[1] == p2);
    assert(repository.getAll()[2] == p3);
    assert(repository.getAll()[3] == p4);
    assert(repository.getAll()[4] == p5);

    repository.deleteEntity(p2);
    repository.deleteEntity(p4);
    repository.deleteEntity(p5);
    assert(repository.getAll().size() == 2);

    repository.updateEntity(p1, Product(1, 1, "suc", 5));
    repository.updateEntity(p3, Product(3, 2, "apa", 3));
    assert(repository.getAll()[0] == Product(1, 1, "suc", 5));
    assert(repository.getAll()[1] == Product(3, 2, "apa", 3));
}

void Tests::service(){
    Repository<Product> repository;
    ProductService service(repository);
    Product p1(1, 1, "croissant", 3);
    Product p2(2,2, "suc", 5);
    Product p3(3,3, "ciocolata", 7);
    Product p4(4,4, "popcorn", 4);
    Product p5(5,5, "apa", 3);
    service.create(p1);
    service.create(p2);
    service.create(p3);
    service.create(p4);
    service.create(p5);
    assert(service.read().size() == 5);
    service.del(p3.getIndex());
    assert(service.read().size() == 4);
    service.update(p1.getIndex(), p4);
    assert(service.get_by_code(4).getPrice() == 4);
    assert(service.get_by_code(4).getCode() == 4);
    assert(service.get_by_code(4).getName() == "popcorn");
    assert(service.sum_jukebox() == 16);
}

void Tests::add_entity_file_test(){
    remove("product.txt");
    fstream file;
    file.open("product.txt", ios::in);
    file.open("product.txt", ios::out);
    RepoFileProduct repository("product.txt");
    Product p(1,1,"Pepsi", 5);
    repository.add_save(p);
    assert(repository.getAll().size() == 1);
}

void Tests::delete_entity_file_test(){
    remove("product.txt");
    fstream file;
    file.open("product.txt", ios::in);
    file.open("product.txt", ios::out);
    RepoFileProduct repository("product.txt");
    Product p(1,1,"Pepsi", 5);
    assert(repository.getAll().size() == 0);
    repository.add_save(p);
    assert(repository.getAll().size() == 1);
    repository.remove_save(p);
    assert(repository.getAll().size() == 0);
}

void Tests::update_entity_file_test(){
    remove("product.txt");
    fstream file;
    file.open("product.txt", ios::in);
    file.open("product.txt", ios::out);
    RepoFileProduct repository("product.txt");
    Product p(1,1,"Pepsi", 5);
    Product p1(2, 2, "Fanta", 6);
    repository.add_save(p);
    repository.add_save(p1);
    repository.update_save(p, p1);
    assert(repository.getAll()[0] == Product(1, 2, "Fanta", 6));
}

void Tests::sum_jukebox_test(){
    remove("product.txt");
    fstream file;
    file.open("product.txt", ios::in);
    file.open("product.txt", ios::out);
    RepositoryInFile<Product> repository("product.txt");
    ProductService service(repository);
    Product p1(1, 1, "croissant", 3);
    Product p2(2,2, "suc", 5);
    Product p3(3,3, "ciocolata", 7);
    Product p4(4,4, "popcorn", 4);
    Product p5(5,5, "apa", 3);
    service.create(p1);
    service.create(p2);
    service.create(p3);
    service.create(p4);
    service.create(p5);
    assert(service.sum_jukebox() == 22);
}
void Tests::test_product_service() {
    Repository<Product> repository;
    ProductService service(repository);

    Product p1(1, 1, "croissant", 3);
    Product p2(2, 2, "suc", 5);
    Product p3(3, 3, "ciocolata", 7);
    Product p4(4, 4, "popcorn", 4);
    Product p5(5, 5, "apa", 3);

    service.create(p1);
    service.create(p2);
    service.create(p3);
    service.create(p4);
    service.create(p5);
    assert(service.read()[0] == p1);
    assert(service.read()[1] == p2);
    assert(service.read()[2] == p3);
    assert(service.read()[3] == p4);
    assert(service.read()[4] == p5);

    service.del(1);
    service.del(3);
    service.del(4);
    assert(service.read().size() == 2);

    service.update(2, Product(1, 1, "suc", 5));
    service.update(5, Product(2, 2, "apa", 3));
    assert(service.read()[0] == Product(1, 1, "suc", 5));
    assert(service.read()[1] == Product(2, 2, "apa", 3));
}

void Tests::test_banknote_service(){
    Repository<Banknote> repository;
    BanknoteService service(repository);

    Banknote b1(1, 500, 10);
    Banknote b2(2, 200, 10);
    Banknote b3(3, 100, 10);
    Banknote b4(4, 50, 10);
    Banknote b5(5, 10, 10);
    Banknote b6(6, 5, 10);
    Banknote b7(7, 1, 10);
    Banknote b8(8, 0.5, 10);
    Banknote b9(9, 0.1, 10);
    Banknote b10(10, 0.05, 10);
    Banknote b11(11, 0.01, 10);

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    service.create(b6);
    service.create(b7);
    service.create(b8);
    service.create(b9);
    service.create(b10);
    service.create(b11);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);
    assert(service.read()[5] == b6);
    assert(service.read()[6] == b7);
    assert(service.read()[7] == b8);
    assert(service.read()[8] == b9);
    assert(service.read()[9] == b10);
    assert(service.read()[10] == b11);

    service.del(1);
    service.del(3);
    service.del(4);
    assert(service.read().size() == 8);

    service.update(2, Banknote(2, 50, 20));
    service.update(5, Banknote(5, 1, 20));
    assert(service.read()[0] == Banknote(2, 50, 20));
    assert(service.read()[1] == Banknote(5, 1, 20));

    service.del(2);
    service.del(5);
    service.del(6);
    service.del(7);
    service.del(8);
    service.del(9);
    service.del(10);
    service.del(11);
    assert(service.read().empty());

    service.create(b1);
    service.create(b2);
    service.create(b3);
    service.create(b4);
    service.create(b5);
    service.create(b6);
    service.create(b7);
    service.create(b8);
    service.create(b9);
    service.create(b10);
    service.create(b11);
    assert(service.read()[0] == b1);
    assert(service.read()[1] == b2);
    assert(service.read()[2] == b3);
    assert(service.read()[3] == b4);
    assert(service.read()[4] == b5);
    assert(service.read()[5] == b6);
    assert(service.read()[6] == b7);
    assert(service.read()[7] == b8);
    assert(service.read()[8] == b9);
    assert(service.read()[9] == b10);
    assert(service.read()[10] == b11);

    std::vector<Banknote> result = service.change(23, 100);
    assert(result[0] == Banknote(1, 500, 0));
    assert(result[1] == Banknote(2, 200, 0));
    assert(result[2] == Banknote(3, 100, 0));
    assert(result[3] == Banknote(4, 50, 1));
    assert(result[4] == Banknote(5, 10, 2));
    assert(result[5] == Banknote(6, 5, 1));
    assert(result[6] == Banknote(7, 1, 2));
    assert(result[7] == Banknote(8, 0.5, 0));
    assert(result[8] == Banknote(9, 0.1, 0));
    assert(result[9] == Banknote(10, 0.05, 0));
    assert(result[10] == Banknote(11, 0.01, 0));

    assert(service.read()[0] == Banknote(1, 500, 10));
    assert(service.read()[1] == Banknote(2, 200, 10));
    assert(service.read()[2] == Banknote(3, 100, 10));
    assert(service.read()[3] == Banknote(4, 50, 9));
    assert(service.read()[4] == Banknote(5, 10, 8));
    assert(service.read()[5] == Banknote(6, 5, 9));
    assert(service.read()[6] == Banknote(7, 1, 8));
    assert(service.read()[7] == Banknote(8, 0.5, 10));
    assert(service.read()[8] == Banknote(9, 0.1, 10));
    assert(service.read()[9] == Banknote(10, 0.05, 10));
    assert(service.read()[10] == Banknote(11, 0.01, 10));
}