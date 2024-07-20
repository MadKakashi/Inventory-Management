#include"updateProduct.h"
#include"product.h"
#include"bufferClear.h"
#include<iostream>
#include<vector>

extern vector<Product>productList;

using namespace std;

void updateMenu() {
    cout << '\n';
    cout << "Choose any of the following options: \n";
    cout << "1. Update name\n";
    cout << "2. Update description\n";
    cout << "3. Update price\n";
    cout << "4. Update quantity\n";
    cout << "5. Exit\n";
}

int getProductID() {
    while (1) {
        cout << "Enter the product ID: ";
        int id;
        cin >> id;
        if (cin.fail()) {
            cinClear();
        }
        else {
            ignoreLine();
            return id;
        }
    }
}

void updateProduct() {
    cout << "\n******************Updating Product******************\n";
    int id = getProductID();
    bool flag = false;
    for (auto& it : productList) {
        if (it.m_getID() == id) {
            flag = true;
            updateMenu();
            while (1) {
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
                if (cin.fail()) {
                    cinClear();
                }
                else {
                    switch (choice) {
                        case 1: it.m_setName(); return;
                        case 2: it.m_setDescription(); return;
                        case 3: it.m_setPrice(); return;
                        case 4: it.m_setQuantity(); return;
                        case 5: return;
                        default: cout << "Please choose the correct option. Try again...\n"; break;
                    }
                }
            }
        }
    }
    if (!flag) {
        cout << "Error: Provided product ID does not exist.\n";
    }
}