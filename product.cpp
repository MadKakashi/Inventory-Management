#include <iomanip>

#include"product.h"
#include"bufferClear.h"

extern vector<Product>productList;

using namespace std;
Product::Product(string name, string description, double price, int quantity) {
    m_unique_product_id = ++m_product_id;
    m_name = name;
    m_description = description;
    m_price = price;
    m_quantity = quantity;
}

Product::Product() {
    cout << "\n****************Creating new product****************\n";

    while (1) {
        cout << "Enter product name: ";
        getline(cin >> ws, m_name);
        bool flag = true;
        for (auto it : productList) {
            if (it.m_getName() == m_name) flag = false;
        }
        if (!flag) cout << "There already exists a product with the same name. Try again.....\n";
        else break;
    }

    cout << "Enter product description: ";
    getline(cin >> ws, m_description);

    while (1) {
        cout << "Enter product price: ";
        cin >> m_price;
        if (cin.fail()) {
            cinClear();
        }
        else if (m_price < 0) cout << "Product price can't be negative. Try again....\n";
        else break;
    }

    ignoreLine();

    while (1) {
        cout << "Enter product quantity: ";
        cin >> m_quantity;
        if (cin.fail()) {
            cinClear();
        }
        else if (m_quantity < 0) cout << "Product quantity can't be negative. Try again....\n";
        else {
            ignoreLine();
            break;
        }
    }
    m_unique_product_id = ++m_product_id;
}

int Product::m_getID() { return m_unique_product_id; }
string Product::m_getName() { return m_name; }
string Product::m_getDescription() { return m_description; }
double Product::m_getPrice() { return m_price; }
int Product::m_getQuantity() { return m_quantity; }

void Product::m_setName() {
    while (1) {
        cout << "Enter new product name: ";
        string newName;
        getline(cin >> ws, newName);
        bool flag = true;
        for (auto it : productList) {
            if (it.m_getID() != m_unique_product_id && newName == it.m_getName()) flag = false;
        }
        if (flag) {
            cout << "Name changed from " << "\"" << m_name << "\"" << " to " << "\"" << newName << "\"" << '\n';
            m_name = newName;
            return;
        }
        else {
            cout << "Error: There already exits a product with the same name. Try again....\n";
        }
    }
}

void Product::m_setDescription() {
    cout << "Enter new product description: ";
    string newDescription;
    getline(cin >> ws, newDescription);
    cout << "Description changed from " << "\"" << m_description << "\"" << " to " << "\"" << newDescription << "\"" << '\n';
    m_description = newDescription;
}

void Product::m_setPrice() {
    while (1) {
        cout << "Enter new product price: ";
        int newPrice;
        cin >> newPrice;
        if (cin.fail()) {
            cinClear();
        }
        else if (newPrice < 0) cout << "Product price can't be negative. Try again....\n";
        else {
            if (newPrice > m_price)
                cout << "Price increased from " << "\"" << m_price << "\"" << " to " << "\"" << newPrice << "\"" << '\n';
            else if (newPrice < m_price)
                cout << "Price decreased from " << "\"" << m_price << "\"" << " to " << "\"" << newPrice << "\"" << '\n';
            else
                cout << "Price changed from " << "\"" << m_price << "\"" << " to " << "\"" << newPrice << "\"" << '\n';

            m_price = newPrice;
            ignoreLine();
            break;
        }
    }
}
void Product::m_setQuantity() {
    cout << "Choose any of the following:\n";
    cout << "1.Increase the quantity\n";
    cout << "2.Decrease the quantity\n";
    while (1) {
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cinClear();
        }
        else {
            if (choice == 1) {
                while (1) {
                    int addQuantity;
                    cout << "Enter the quantity you wish to add: ";
                    cin >> addQuantity;
                    if (cin.fail()) {
                        cinClear();
                    }
                    else {
                        cout << "Quantity increased from " << "\"" << m_quantity << "\"" << " to " << "\"" << addQuantity + m_quantity << "\"" << '\n';
                        m_quantity += addQuantity;
                        ignoreLine();
                        return;
                    }
                }
            }

            else if (choice == 2) {
                while (1) {
                    int subQuantity;
                    cout << "Enter the quantity you wish to subtract: ";
                    cin >> subQuantity;
                    if (cin.fail()) {
                        cinClear();
                    }
                    else {
                        if (m_quantity - subQuantity < 0) {
                            cout << "Error: The current product quantity is " << m_getQuantity() << " you can't subtract more than that. Try again....\n";
                        }
                        else {
                            cout << "Quantity decreased from " << "\"" << m_quantity << "\"" << " to " << "\"" << m_quantity - subQuantity << "\"" << '\n';
                            m_quantity -= subQuantity;
                            ignoreLine();
                            return;
                        }
                    }
                }
            }
        }
    }
}

void Product::m_printDetails() {
    cout << "\n";
    cout << setw(15) << "Product ID" << setw(15) << "Name" << setw(15) << "Description" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Cost" << '\n';
    cout << setw(15) << m_getID() << setw(15) << m_getName() << setw(15) << m_getDescription() << setw(15) << m_getPrice() << setw(15) << m_getQuantity() << setw(15) << m_getPrice() * m_getQuantity() << '\n';
    cout << "\n";
}