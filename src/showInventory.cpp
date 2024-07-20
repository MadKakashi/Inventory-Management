#include"showInventory.h"
#include"product.h"

#include<iostream>
#include<iomanip>
#include<vector>

extern vector<Product>productList;

using namespace std;

void showInventory(vector<Product>& productList) {
    cout << "\n";
    cout << "********************************************Products******************************************\n";
    cout << setw(15) << "Product ID" << setw(15) << "Name" << setw(15) << "Description" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Cost" << '\n';
    for (auto it : productList) {
        cout << setw(15) << it.m_getID() << setw(15) << it.m_getName() << setw(15) << it.m_getDescription() << setw(15) << it.m_getPrice() << setw(15) << it.m_getQuantity() << setw(15) << it.m_getPrice() * it.m_getQuantity() << '\n';
    }
    cout << "***********************************************************************************************\n";
    cout << "\n";
}