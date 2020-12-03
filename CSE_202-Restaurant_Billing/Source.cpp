#include <iostream>
#include <stdlib.h>
#include "BillDesk.h"
#include "InvAdmin.h"
using namespace std;

InvAdmin Admin;
InvAdmin Bill;
string query = "stay";

void welcomeMessage();
void headerAdminMessage();
void headerBillMessage();
void runAdminCommands();
void runBillCommands();
void adminAdd();
void adminUpdate();
void adminShow();
void adminDelete();
void adminSearch();
void billAdd();
void billDelete();
void billSearch();


int main() {
    system("title Inventory Management System");
    system("cls");

    welcomeMessage();
    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    system("CLS");
    runAdminCommands();
}

// Print Welcome Message No input
void welcomeMessage() {
    cout << "\n\t*** Welcome to Inventory Management System ***" << endl;
    cout << "\tA inventory keeping and billing application" << endl;
    cout << "\n\t\tAuthor: Tasnim Zotder" << endl;
    cout << "\t\tInst: Lovely Professional University" << endl;
    cout << "\n\t\tCopyright: Tasnim Zotder | 2020" << endl;
}

// Message for Admin users
void headerAdminMessage() {
    cout << "\n\t\t\t"
        << "*** Inventory Management System - Admin ***\n"
        << endl;
    cout << "\t\t\t\t---Admin Commands---" << endl;
    cout << "1. 'add' - To add new product [Product_Code, Product_Name, Price]" << endl;
    cout << "2. 'update' - To update a product [Product_Code, (Product_Name), (Price)]" << endl;
    cout << "3. 'show' - To show all products in inventory" << endl;
    cout << "4. 'delete' - To delete a product [Product_Code]" << endl;
    cout << "5. 'search' - To search a product [Product_Code]" << endl;
    cout << "6. 'bill' - To enter Billing System" << endl;
    cout << "7. 'exit' - To exit the window" << endl;
}

// Message for Desk users
void headerBillMessage() {
    cout << "\n\t\t\t"
        << "*** Product Billing System - Admin ***\n"
        << endl;
    cout << "\t\t\t\t---Billing Commands---" << endl;
    cout << "1. 'add' - To add existing product [Product_Code] to billing list" << endl;
    cout << "2. 'generate' - To generate bill" << endl;
    cout << "3. 'show' - To show all products in inventory" << endl;
    cout << "4. 'delete' - To delete a product [Product_Code] from bill" << endl;
    cout << "5. 'search' - To search a product [Product_Code] in inventory" << endl;
    cout << "6. 'exit' - To exit the billing menu" << endl;
}

// Commands for Admins
void runAdminCommands() {
    headerAdminMessage();

    cout << "\n\n"
        << "Enter the query:"
        << " ";
    cin >> query;
    system("CLS");

    if (query != "exit") {
        if (query == "show") {
            adminShow();
            /*cout << "\t Inventory List" << endl;
            Admin.showProducts();

            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");*/
        }
        else if (query == "add") {
            adminAdd();
            /*string productCode, product;
            float price = 0;

            cout << "Please Enter Product Code, Product & Price: ";
            cin >> productCode;
            cin >> product;
            cin >> price;

            Admin.addProduct(productCode, product, price);

            cout << "\tProduct Added" << endl;
            Admin.searchOne(productCode);

            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");*/
        }
        else if (query == "delete") {
            adminDelete();
            /*string productCode;
            cout << "\tPlease enter the Product_Code: ";
            cin >> productCode;

            Admin.deleteProduct(productCode);
            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");*/
        }
        else if (query == "update") {
            adminUpdate();
            /*string productCode;
            string product;
            float price;

            cout << "Please enter the Product_Code: ";
            cin >> productCode;

            Admin.searchOne(productCode);
            cout << "\nPlease enter the new Product & Price: ";
            cin >> product >> price;

            Admin.updateProduct(productCode, product, price);
            Admin.searchOne(productCode);

            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");*/
        }
        else if (query == "search") {
            adminSearch();
            /*string productCode;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Admin.searchOne(productCode);

            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");*/
        }
        // Billing System
        else if (query == "bill") {
            runBillCommands();
        }
        // Bad query
        else {
            system("CLS");
            cout << "\t"
                << "Please enter a valid command!\n" << endl;
            runAdminCommands();
        }
        runAdminCommands();
    }
    else {
        system("CLS");
        cout << "See you again!\n"
            << endl;
    }
}

// Commands for billing
void runBillCommands() {
    headerBillMessage();

    cout << "\n\n"
        << "Enter the query:"
        << " ";
    cin >> query;
    system("CLS");

    if (query != "exit") {
        if (query == "show") {
            Admin.showProducts();
        }
        else if (query == "search") {
            billSearch();
            /*string productCode;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Admin.searchOne(productCode);*/
        }
        else if (query == "add") {
            billAdd();
            /*string productCode;

            cout << "Please Enter Product Code: " << endl;
            cin >> productCode;

            Bill.billAddProduct(productCode);*/
        }
        else if (query == "delete") {
            billDelete();
            /*string productCode;

            cout << "Please Enter Product Code: " << endl;
            cin >> productCode;

            Bill.billDeleteProduct(productCode);*/
        }
        else if (query == "generate") {
            Bill.generateBill();
        }
        else {
            cout << "\t"
                << "Please enter a valid command!\n" << endl;
        }
        runBillCommands();
    }
    else {
        system("CLS");
        runAdminCommands();
    }
}

void adminAdd() {
    string productCode, product;
    float price = 0;

    cout << "Please Enter Product Code, Product & Price: ";
    cin >> productCode;
    cin >> product;
    cin >> price;

    Admin.addProduct(productCode, product, price);

    cout << "\tProduct Added" << endl;
    Admin.searchOne(productCode);

    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    cin.ignore();
    system("CLS");
}

void adminUpdate() {
    string productCode;
    string product;
    float price;

    cout << "Please enter the Product_Code: ";
    cin >> productCode;

    Admin.searchOne(productCode);
    cout << "\nPlease enter the new Product & Price: ";
    cin >> product >> price;

    Admin.updateProduct(productCode, product, price);
    Admin.searchOne(productCode);

    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    cin.ignore();
    system("CLS");
}

void adminShow() {
    cout << "\t Inventory List" << endl;
    Admin.showProducts();

    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    cin.ignore();
    system("CLS");
}

void adminDelete() {
    string productCode;
    cout << "\tPlease enter the Product_Code: ";
    cin >> productCode;

    Admin.deleteProduct(productCode);
    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    cin.ignore();
    system("CLS");
}

void adminSearch() {
    string productCode;

    cout << "Please enter the Product_Code ";
    cin >> productCode;

    Admin.searchOne(productCode);

    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    cin.ignore();
    system("CLS");
}

void billAdd() {
    string productCode;

    cout << "Please Enter Product Code: " << endl;
    cin >> productCode;

    Bill.billAddProduct(productCode);
}

void billDelete() {
    string productCode;

    cout << "Please Enter Product Code: " << endl;
    cin >> productCode;

    Bill.billDeleteProduct(productCode);
}

void billSearch() {
    string productCode;

    cout << "Please enter the Product_Code ";
    cin >> productCode;

    Admin.searchOne(productCode);
}