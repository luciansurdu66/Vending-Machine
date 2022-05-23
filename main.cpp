#include <iostream>
#include "Tests/Tests.h"
#include "UI/UI.h"
#include "Repository/RepoFileProduct.h"
#include "Repository/RepositoryInFile.h"
int main() {
    Tests tests;
    tests.all();

    RepositoryInFile<Product> repoFileProduct("products.txt");
    RepositoryInFile<Banknote> repoFileCurrency("banutsi.txt");

    ProductService service(repoFileProduct);
    BanknoteService cservice(repoFileCurrency);

    UI UI(service, cservice);
    UI.runMenu();

    return 0;
}
