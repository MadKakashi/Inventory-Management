#include"removeProduct.h"
#include"product.h"
#include"bufferClear.h"

#include<iostream>
#include<vector>

extern vector<Product>productList;

using namespace std;

void removeProduct() {
    cout << "\n******************Removing Product******************\n";
    while (1) {
        cout << "Enter the product ID of the product that you wish to delete: ";
        int id;
        cin >> id;
        if (cin.fail()) {
            cinClear();
        }
        else {
            for (auto it = productList.begin(); it != productList.end(); it++) {
                if (it->m_getID() == id) {
                    productList.erase(it);
                    cout << "Product erased.\n";
                    return;
                }
            }
            cout << "Error: Provided ID does not exist. Try again.......\n";
        }
    }
}