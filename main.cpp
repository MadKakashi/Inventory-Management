#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<climits>
#include<iomanip>
#include<algorithm>
#include<fstream>

#include"io.h"
#include"product.h"
#include"bufferClear.h"
#include"updateProduct.h"
#include"mainMenu.h"
#include"showInventory.h"
#include"removeProduct.h"
#include"searchProduct.h"

using namespace std;

class Product;
vector<Product>productList;

int Product::m_product_id = 0;

void addProduct() {
    Product p{};
    productList.push_back(p);
}

int main() {
    startingMessage();
    while (1) {
        bool exitflag = false;
        mainMenu();
        cout << "\nEnter your choice: ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cinClear();
        }
        else {
            ignoreLine();
            switch (choice) {
                case 1: addProduct(); break;
                case 2: updateProduct(); break;
                case 3: searchInventory(); break;
                case 4: removeProduct(); break;
                case 5: showInventory(productList); break;
                case 6: outputToFile(); break;
                case 7: inputFromFile(); break;
                case 8: exitflag = true; break;
                default: cout << "Please choose the correct option. Try again...\n"; break;
            }
        }
        if (exitflag) {
            while (1) {
                cout << "Do you wish to save the data in \"output.txt\" file[Y/N] : ";
                char ch;
                cin >> ch;
                switch (ch) {
                    case 'Y': outputToFile(); return 0;
                    case 'N': cout << "Exiting.......\n"; return 0;
                    default: cout << "Please choose the options correctly. Try again..\n";
                }
            }
        }
    }
    return 0;
}
