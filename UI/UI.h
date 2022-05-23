//
// Created by lucia on 4/19/2022.
//

#ifndef LAB09_10_UI_H
#define LAB09_10_UI_H
#include "../Domain/Product.h"
#include "../Repository/RepoProduct.h"
#include "../Service/ProductService.h"
#include "../Service/BanknoteService.h"
using namespace std;
class UI {
    ProductService service;
    BanknoteService currservice;
public:
    static void showMenu();
    void runMenu();
    UI(ProductService &serviceProduct, BanknoteService &serviceBanknote);
    ~UI();

    void add_product();

    void delete_product();

    void show_all();

    void handle_sum_for_jukebox();

    void handle_count_products();

    static void showMenuAdmin();

    void runMenuProducts();

    static void showMenuUser();

    void runMenuUser();

    void update_product();

    void add_banknote();

    void update_banknote();

    void delete_banknote();

    void insertMoney(double &inserted, double credit, Product &product);

    void pickUpChange(double &inserted, Product &product, vector<Banknote> copy);

    void changes();
};


#endif //LAB09_10_UI_H
