#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

#include"io.h"
#include"product.h"

extern vector<Product>productList;

void outputToFile() {
    ofstream fout{ "output.txt" };
    for (auto it : productList) {
        fout << it.m_getID() << ' ' << it.m_getName() << ' ' << it.m_getDescription() << ' ' << it.m_getPrice() << ' ' << it.m_getQuantity() << '\n';
    }
    cout << "Output to file \"output.txt\" done\n";
}

void inputFromFile() {
    ifstream fin{ "input.txt" };

    if (!fin) {
        cout << "Error: \"input.txt\" could not open for reading.\n";
        return;
    }

    string str;
    string name, description;
    double price;
    int quantity;
    while (fin >> name >> description >> price >> quantity) {
        Product p{ name, description, price, quantity };
        productList.push_back(p);
    }
    cout << "Input from file \"input.txt\" done\n";
}