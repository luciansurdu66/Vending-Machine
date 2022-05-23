cmake_minimum_required(VERSION 3.21)
project(lab09_10)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab09_10 main.cpp Domain/Product.cpp Domain/Product.h Repository/RepoProduct.cpp Repository/RepoProduct.h Service/ProductService.cpp Service/ProductService.h Tests/Tests.cpp Tests/Tests.h UI/UI.cpp UI/UI.h Repository/RepoFileProduct.cpp Repository/RepoFileProduct.h Repository/IRepository.cpp Repository/IRepository.h Domain/Money.cpp Domain/Money.h Domain/Banknote.cpp Domain/Banknote.h Domain/MyException.h Repository/Repository.h Repository/RepositoryInFile.h Service/BanknoteService.cpp Service/BanknoteService.h Domain/Comparari.h Domain/ProductValidator.h Domain/BanknoteValidator.h)
