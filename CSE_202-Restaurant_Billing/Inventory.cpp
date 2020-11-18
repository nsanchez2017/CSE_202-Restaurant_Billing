#include "Inventory.h"

/**
* Get index of product
* productCode: String of the code the user entered
* returns: int Index
*/
int Inventory::findIndex(string productCode) {
    int index = -1;

    for (int i = 0; i < productCount; i++) {
        if (productCodes[i] == productCode) {
            index = i;
            break;
        }
    }

    return index;
}

// print table of products
void Inventory::showProducts() {
    cout << "\t\t"
        << "Code\t"
        << "Product\t\t"
        << "Price" << endl;
    cout << "\t\t"
        << "------|---------------|------" << endl;

    for (int i = 0; i < productCount; i++) {
        cout << "\t\t" << productCodes[i] << "\t";
        cout << productList[i] << "\t";
        cout << priceList[i] << endl;
    }
}

// print user selected product given the product code
void Inventory::searchOne(string productCode) {
    int index = findIndex(productCode);

    if (index == -1) {
        cout << "Product not in inventory" << endl;
    } else {
        cout << "\t\t"
        << "Code\t"
        << "Product\t\t"
        << "Price" << endl;
        cout << "\t\t"
        << "------|---------------|------" << endl;

        cout << "\t\t" << productCodes[index] << "\t";
        cout << productList[index] << "\t";
        cout << priceList[index] << endl;
    }
}