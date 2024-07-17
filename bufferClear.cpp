#include<iostream>
#include"bufferClear.h"
#include<limits>

using namespace std;

void ignoreLine() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cinClear() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Incorrect input type. Try again....\n";
}