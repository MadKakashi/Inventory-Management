#include"mainMenu.h"
#include<iostream>
#include"bufferClear.h"

using namespace std;

void startingMessage() {
    cout << "\n";
    cout << "************************************************\n";
    cout << "*                                              *\n";
    cout << "*            WELCOME TO INVENTORY              *\n";
    cout << "*                                              *\n";
    cout << "************************************************\n\n";
}

void mainMenu() {
    cout << "\n****************************************************\n";
    cout << "*\tChoose any of the following options-       *\n";
    cout << "*\t1. Add a product                           *\n";
    cout << "*\t2. Update product                          *\n";
    cout << "*\t3. Search inventory                        *\n";
    cout << "*\t4. Remove product                          *\n";
    cout << "*\t5. Show inventory                          *\n";
    cout << "*\t6. Output to a file                        *\n";
    cout << "*\t7. Input from a file                       *\n";
    cout << "*\t8. Exit                                    *";
    cout << "\n****************************************************\n";
}