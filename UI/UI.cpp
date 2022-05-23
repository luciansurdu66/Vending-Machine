//
// Created by lucia on 4/19/2022.
//

#include <tuple>
#include "UI.h"
#include "../Domain/Comparari.h"
UI::UI(ProductService &ser, BanknoteService &serM): service(ser), currservice(serM) {}
void UI::showMenu() {
    cout << "1. User Menu. \n";
    cout << "2. Admin Menu. \n";
    cout << "x. Exit. \n";
}

void UI::runMenu() {
    bool ok = true;
    while(ok){
        showMenu();
        char option;
        cin >> option;
        cout << "\n";
        switch (option) {
            case '1':
                runMenuUser();
                break;
            case '2':
                runMenuProducts();
                break;
            case 'x':
                ok = false;
                break;
            default:
                cout << "Invalid option! Please try again! \n";
        }
    }

}
void UI::showMenuAdmin() {
    cout << "1. Add product\n";
    cout << "2. Update product\n";
    cout << "3. Delete product.\n";
    cout << "4. Total price of products. \n";
    cout << "5. Count products. \n";
    cout << "s. Show products.\n";
    cout << "c. Show currency. \n";
    cout << "x. Back.\n";
    cout << "Select option:";
}

void UI::runMenuProducts() {
    char option;
    bool ok = true;
    Product produs;
    while(ok){
        showMenuAdmin();
        cin >> option;
        cout << "\n";
        switch (option) {
            case '1':
                add_product();
                break;
            case '2':
                update_product();
                break;
            case '3':
                delete_product();
                break;
            case '4':
                handle_sum_for_jukebox();
                break;
            case '5':
                handle_count_products();
                break;
            case 's':
                show_all();
                break;
            case 'c':
                for(auto &c: currservice.read()){
                    cout << c  << "\n";
                }
                break;
            case 'x':
                ok = false;
                break;
            default:
                cout << "Invalid option! Please try again! \n";
        }
    }
}
void UI::showMenuUser(){
    cout << "1. Check products. \n";
    cout << "2. Buy product. \n";
    cout << "x. Back. \n";
    cout << "Select option: \n";

}
void UI::runMenuUser(){
    bool ok = true;
    while(ok){
        showMenuUser();
        char option;
        cin >> option;
        cout << "\n";
        switch (option) {
            case '1':
                show_all();
                break;
            case '2':{
                changes();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Invalid option! Please try again! \n";
        }
    }
}

void UI::add_product() {
    try{
        int id, cod, price;
        string name;
        cout << "Give id:";
        cin >> id;
        if(!cin >> id){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
        cout << "Give the code of the product:";
        cin >> cod;
        if(!cin >> cod){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Code must be a positive number.");
        }
        cout << "Give the name of the product:";
        cin >> name;
        cout << "Give the price of the product:";
        cin >> price;
        if(!cin >> price){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Price must be a positive number.");
        }
        Product product(id, cod, name, price);
        service.create(product);
    }
    catch (exception &e){
        cout << e.what() << "\n";
    }
}

void UI::show_all() {
    for (auto &product: service.read()) {
        cout << product;
    }

}

void UI::delete_product() {
    try{
        int id;
        cout << "Give the id of the product you want to delete:";
        cin >> id;
        if(cin >> id){
            for (auto &pr: service.read()) {
                if (id == pr.getIndex()) {
                    service.del(pr.getIndex());
                }
            }
        }else
        {
            cin.clear();
            cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");}
    }catch (exception &e){
        cout << e.what() << "\n";
    }
}

void UI::update_product() {
    try{
        int id;
        cout << "Give the id of the product you want to update:";
        cin >> id;
        if(!cin >> id){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
        int cod, price;
        string name;
        cout << "Give the new code of the product:";
        cin >> cod;
        if(!cin >> cod){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Code must be a positive number.");
        }
        cout << "Give the new name of the product:";
        cin >> name;
        cout << "Give the new price of the product:";
        cin >> price;
        if(!cin >> price){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Price must be a positive number.");
        }
        Product old_prod = service.get_by_code(id);
        Product new_prod(old_prod.getIndex(), cod, name, price);
        for (auto &pr: service.read()) {
            if (id == pr.getIndex()) {
                service.update(pr.getIndex(), new_prod);
            }
        }
    }
    catch (exception &e){
        cout << e.what() << "\n";
    }
}
void UI::add_banknote() {
    try {
        Banknote banknote;
        cin >> banknote;
        currservice.create(banknote);
    }
    catch(std::exception &e) {
        cout << e.what() << '\n';
    }
}

void UI::update_banknote() {
    try {
        unsigned int index;
        cout << "Update banknote with index:";
        if(cin >> index) {
            Banknote newBanknote;
            cin >> newBanknote;
            currservice.update(index, newBanknote);
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}
void UI::delete_banknote() {
    try {
        unsigned int index;
        std::cout << "Delete banknotes with index:";
        if(cin >> index) {
            currservice.del(index);
        }
        else {
            cin.clear();
            cin.ignore(10000, '\n');
            throw MyException("Id must be a positive number.");
        }
    }
    catch(exception &e) {
        cout << e.what() << '\n';
    }
}
UI::~UI() = default;

void UI::handle_sum_for_jukebox() {
    int sum = UI::service.sum_jukebox();
    cout << "The total price of jukebox products is: " << sum << "\n";
}

void UI::handle_count_products(){
    vector<tuple<unsigned int, unsigned int>> result = UI::service.count_products();
    for(auto currTuple: result){
        cout << "There are " << get<1>(currTuple) << " products with the code " << get<0>(currTuple) << "\n";

    }
}
void UI::insertMoney(double &inserted, double credit, Product &product) {
    while(Compares::less(inserted, product.getPrice())) {
        std::cout << "Please insert credit (0.01/0.05/0.1/0.5/1/5/10/50/100/200/500):";
        if(std::cin >> credit) {
            if (Compares::equal(credit, 0.01) ||
                    Compares::equal(credit, 0.05) ||
                    Compares::equal(credit, 0.1) ||
                    Compares::equal(credit, 0.5) ||
                    Compares::equal(credit, 1) ||
                    Compares::equal(credit, 5) ||
                    Compares::equal(credit, 10) ||
                    Compares::equal(credit, 50) ||
                    Compares::equal(credit, 100) ||
                    Compares::equal(credit, 200) ||
                    Compares::equal(credit, 500)) {
                Banknote banknote = (currservice.getBanknoteByValue(
                        credit));
                Banknote newBanknote(banknote.getIndex(), banknote.getValue(),
                                     banknote.getNoOccurrences() + 1);

                currservice.update(banknote.getIndex(), newBanknote);
                inserted += credit;
            } else {
                std::cout << "We don't accept that type of currency." << '\n';
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Credit must be a double type number.");
        }
    }
}


void UI::pickUpChange(double &inserted, Product &product,std::vector<Banknote> copy) {
    std::vector<Banknote> result = currservice.change(product.getPrice(), inserted);

    if(service.numberOfProductsByName(product.getName()) == 0) {
        std::cout << "We don't have this product." << '\n';
    }
    else {
        if (Compares::equal(inserted, product.getPrice())) {
            std::cout << "Thanks for your purchase!" << '\n';
            unsigned int id = service.get_by_code(product.getCode()).getIndex();
            service.del(id);
        } else {
            unsigned int checker = 0;
            for (int i = 0; i < result.size(); i++) {
                checker += result[i].getNoOccurrences();
            }
            if (checker == 0) {
                currservice.updateAll(copy);
                std::cout
                        << "Our vending machine doesn't have money. Pick up your money."
                        << '\n';
            } else {
                double change = 0;
                for (auto & i : result) {
                    change += i.getValue() *
                              i.getNoOccurrences();
                }

                if (Compares::equal(change, inserted - product.getPrice())) {
                    unsigned int id = service.get_by_code(product.getCode()).getIndex();
                    service.del(id);
                    std::cout << "Please pick up your change: " << '\n';
                    for (auto & i : result) {
                        if (i.getNoOccurrences() != 0) {
                            std::cout << i.getNoOccurrences()
                                      << " banknotes of "
                                      << i.getValue() << " RON."
                                      << '\n';
                        }
                    }
                    std::cout << "A total of: " << change << " RON." << '\n'
                              << "Thanks for your purchase!" << '\n';
                } else {
                    currservice.updateAll(copy);
                    std::cout
                            << "Our vending machine doesn't have money. Pick up your money."
                            << '\n';
                }
            }
        }
    }
}
void UI::changes() {
    try {
        unsigned int code;
        std::cout << "Please choose a product:";
        if(std::cin >> code) {
            double inserted = 0;
            double credit = 0;
            Product product = service.get_by_code(code);
            std::vector<Banknote> copy = currservice.read();

            insertMoney(inserted, credit, product);
            pickUpChange(inserted, product, copy);
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Code must be a positive number.");
        }
    }
    catch(std::exception &e) {
        std::cout << e.what() << '\n';
    }
}