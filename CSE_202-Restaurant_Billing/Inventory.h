#pragma once
#include <iostream>
using namespace std;

class Inventory {
protected:
    string productCodes[100] = { "ICCRM", "RCBWL", "CKNRL" };
    string productList[100] = { "Ice_Cream", "Rice_Bowl", "Chicken_Roll" };
    float priceList[100] = { 65, 50, 70 };
    int productCount = 3;

public:
    int findIndex(string);
    void showProducts();
    void searchOne(string);
};
