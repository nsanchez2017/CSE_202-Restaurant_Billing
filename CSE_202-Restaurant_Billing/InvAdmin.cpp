#include "InvAdmin.h"

/**
* add product to list of products
* productcode: Product code
* product: Name of product
* price: Product price
*/
void InvAdmin::addProduct(string productCode, string product, float price) {
    productCodes[productCount] = productCode;
    productList[productCount] = product;
    priceList[productCount] = price;
    productCount++;
}

/**
* deletes a product from list of products
* productCode: product code
*/
void InvAdmin::deleteProduct(string productCode) {
    int index = findIndex(productCode);

    for (int i = index; i < productCount - 1; i++) {
        productCodes[i] = productCodes[i + 1];
        productList[i] = productList[i + 1];
        priceList[i] = priceList[i + 1];
    }

    productCount--;
    cout << "\tProduct " << productCode << " deleted!" << endl;
}

/**
* edits existing product
* productCode: product code
* product: users New/Old product name
* price users New/Old product price
*/
void InvAdmin::updateProduct(string productCode, string product, float price) {
    int index = 0;

    for (int i = 0; i < productCount; i++) {
        if (productCodes[i] == productCode) {
            index = i;
            break;
        }
    }

    productList[index] = product;
    priceList[index] = price;
}

//
// Functions under here are the once moved from BillDesk.cpp
//

// initilize bill desk
void InvAdmin::Bill()
{
    billAmount = 0;
    billProdCount = 0;
}

/**
* Get index of product
* productCode: String of the code the user entered
* returns: int Index
*/
int InvAdmin::findBillIndex(string productCode) {
    int index = 0;

    for (int i = 0; i < billProdCount; i++) {
        if (selectedProducts[i] == productCode) {
            index = i;
            break;
        }
    }

    return index;
}

/**
* add product to bill
* productCode: code of product
*/
void InvAdmin::billAddProduct(string productCode) {
    int index = findIndex(productCode);

    selectedProducts[billProdCount] = productList[index];
    selectedProdCodes[billProdCount] = productCodes[index];
    billPriceList[billProdCount] = priceList[index];
    billAmount += priceList[index];
    billProdCount++;

    cout << "\tProduct added!" << endl;
    cout << "\tItem: " << billProdCount << "\tAmount: " << billAmount << endl;
}

/**
* delete item from bill list
* productCode: code of product
*/
void InvAdmin::billDeleteProduct(string productCode) {
    //int index = findIndex(productCode);
    int billIndex = findBillIndex(productCode);

    for (int i = billIndex; i < billProdCount - 1; i++) {
        selectedProducts[i] = selectedProducts[i + 1];
        selectedProdCodes[i] = selectedProdCodes[i + 1];
        billPriceList[i] = priceList[i + 1];
    }

    billAmount -= billPriceList[billIndex];
    billProdCount--;

    cout << "\tProduct removed!" << endl;
    cout << "\tItem: " << billProdCount << "\tAmount: " << billAmount << endl;
}

/**
* prints bill to console
*/
void InvAdmin::generateBill() {
    cout << "\n\t\t\tYour Product Bill" << endl;
    cout << "\t\t\t_________________\n\n"
        << endl;

    cout << "\t\tSl\t"
        << "Product\t\t"
        << "Price" << endl;
    cout << "\t\t"
        << "----|---------------|--------" << endl;

    for (int i = 0; i < billProdCount; i++) {
        cout << "\t\t" << i + 1 << "."
            << "\t";
        cout << selectedProducts[i] << "\t";
        cout << billPriceList[i] << endl;
    }

    cout << "\t\t"
        << "______________________________" << endl;
    cout << "\t\t\t\t"
        << "Total:\t" << billAmount << endl;

    cout << "\n\t\t\t\t\t"
        << "THANKS" << endl;
}