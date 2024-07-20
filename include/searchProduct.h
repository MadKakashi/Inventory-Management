#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

class Product;

void searchMenu();
int getSearchMenuChoice();
void searchOnProductID();
void searchOnProductName();

bool priceCmpAsc(Product p1, Product p2);
bool priceCmpDes(Product p1, Product p2);
bool quantityCmpAsc(Product p1, Product p2);
bool quantityCmpDes(Product p1, Product p2);

void searchOnPrice();
void searchOnQuantity();
void searchInventory();

#endif