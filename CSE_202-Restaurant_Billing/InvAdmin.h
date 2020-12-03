#pragma once
#include "Inventory.h"
class InvAdmin : public Inventory {
private:
    string selectedProducts[100];
    string selectedProdCodes[100];
    float billPriceList[100];
    float billAmount;
    int billProdCount;

public:
    void Bill();

    int findBillIndex(string);
    void billAddProduct(string);
    void billDeleteProduct(string);
    void generateBill();

public:
    void addProduct(string, string, float);
    void deleteProduct(string);
    void updateProduct(string, string, float);
};
