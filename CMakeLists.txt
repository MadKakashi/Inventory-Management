cmake_minimum_required(VERSION 3.10)

project(Inventory-Management VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(InventoryManagement
    main.cpp
    bufferClear.cpp
    io.cpp
    mainMenu.cpp
    product.cpp
    removeProduct.cpp
    product.cpp
    searchProduct.cpp
    showInventory.cpp
    updateProduct.cpp
)