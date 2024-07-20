#include"searchProduct.h"
#include"bufferClear.h"
#include"product.h"
#include"showInventory.h"

#include<iostream>
#include<vector>
#include<algorithm>

extern vector<Product>productList;

using namespace std;

void searchMenu() {
    cout << "\n*****************Search Product******************\n";
    cout << "Choose any of the following: \n";
    cout << "1. Search on the basis of product id.\n";
    cout << "2. Search on the basis of product name\n";
    cout << "3. Search on the basis of product price\n";
    cout << "4. Search on the basis of the product quantity\n";
    cout << '\n';
}

int getSearchMenuChoice() {
    while (1) {
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cinClear();
        }
        else {
            ignoreLine();
            return choice;
        }
    }
}

void searchOnProductID() {
    while (1) {
        cout << "\nEnter the product id: ";
        int id;
        cin >> id;
        if (cin.fail()) {
            cinClear();
        }
        else {
            for (auto& it : productList) {
                if (it.m_getID() == id) {
                    it.m_printDetails();
                    return;
                }
            }
            cout << "Error: Provided ID does not exist. Try again.......\n";
        }
    }
}

void searchOnProductName() {
    cout << "\nEnter the product name: ";
    string name;
    getline(cin >> ws, name);
    for (auto& it : productList) {
        if (it.m_getName() == name) {
            it.m_printDetails();
            return;
        }
    }
    cout << "Error: Provided product name does not exist. Try again.......\n";
}

bool priceCmpAsc(Product p1, Product p2) {
    return p1.m_getPrice() < p2.m_getPrice();
}

bool priceCmpDes(Product p1, Product p2) {
    return p1.m_getPrice() > p2.m_getPrice();
}

bool quantityCmpAsc(Product p1, Product p2) {
    return p1.m_getQuantity() < p2.m_getQuantity();
}

bool quantityCmpDes(Product p1, Product p2) {
    return p1.m_getQuantity() > p2.m_getQuantity();
}

void searchOnPrice() {
    while (1) {
        int mn{};
        int mx{};
        while (1) {
            cout << "Enter the min price of product: ";
            cin >> mn;
            if (cin.fail()) {
                cinClear();
            }
            else {
                ignoreLine(); break;
            }
        }
        while (1) {
            cout << "Enter the max price of product: ";
            cin >> mx;
            if (cin.fail()) {
                cinClear();
            }
            else {
                ignoreLine(); break;
            }
        }
        vector<Product>priceVec;
        for (auto& it : productList) {
            if (it.m_getPrice() >= mn && it.m_getPrice() <= mx) priceVec.push_back(it);
        }

        cout << "\nChoose the following options: \n";
        cout << "1. Show products in ascending order\n";
        cout << "2. Show products in decending order\n";

        while (1) {
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (cin.fail()) {
                cinClear();
            }
            else {
                if (choice == 1) {
                    sort(priceVec.begin(), priceVec.end(), priceCmpAsc);
                    showInventory(priceVec); return;
                }
                else if (choice == 2) {
                    sort(priceVec.begin(), priceVec.end(), priceCmpDes);
                    showInventory(priceVec); return;
                }
                else {
                    cout << "Please choose the correct option. Try again...\n";
                }
            }
        }
    }
}

void searchOnQuantity() {
    while (1) {
        int mn{};
        int mx{};
        while (1) {
            cout << "Enter the min quantity of product: ";
            cin >> mn;
            if (cin.fail()) {
                cinClear();
            }
            else {
                ignoreLine(); break;
            }
        }
        while (1) {
            cout << "Enter the max quantity of product: ";
            cin >> mx;
            if (cin.fail()) {
                cinClear();
            }
            else {
                ignoreLine(); break;
            }
        }
        vector<Product>quantityVec;
        for (auto& it : productList) {
            if (it.m_getQuantity() >= mn && it.m_getQuantity() <= mx) quantityVec.push_back(it);
        }

        cout << "\nChoose the following options: \n";
        cout << "1. Show products in ascending order\n";
        cout << "2. Show products in decending order\n";

        while (1) {
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (cin.fail()) {
                cinClear();
            }
            else {
                if (choice == 1) {
                    sort(quantityVec.begin(), quantityVec.end(), quantityCmpAsc);
                    showInventory(quantityVec);
                    return;
                }
                else if (choice == 2) {
                    sort(quantityVec.begin(), quantityVec.end(), quantityCmpDes);
                    showInventory(quantityVec);
                    return;
                }
                else {
                    cout << "Please choose the correct option. Try again...\n";
                }
            }
        }
    }
}

void searchInventory() {
    while (1) {
        searchMenu();
        int choice = getSearchMenuChoice();
        switch (choice) {
            case 1: searchOnProductID(); return;
            case 2: searchOnProductName(); return;
            case 3: searchOnPrice(); return;
            case 4: searchOnQuantity(); return;
            default: cout << "Please choose the correct option. Try again...\n"; break;
        }
    }
}
