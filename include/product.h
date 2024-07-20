#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class Product {
private:
    static int m_product_id;
    int m_unique_product_id{};
    string m_name{};
    string m_description{};
    double m_price{};
    int m_quantity{};

public:
    Product(string name, string description, double price, int quantity);
    Product();
    //getters
    int m_getID();
    string m_getName();
    string m_getDescription();
    double m_getPrice();
    int m_getQuantity();

    //setters
    void m_setName();
    void m_setDescription();
    void m_setPrice();
    void m_setQuantity();

    void m_printDetails();
};