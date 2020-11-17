#include <iostream>
#include <stdlib.h>

#include "BillDesk.h"
#include "InvAdmin.h"
using namespace std;

InvAdmin Admin;
InvAdmin Bill;

string query = "stay";

// Print Welcome Message No input
void welcomeMessage() {
    cout << "\n\t*** Welcome to Inventory Management System ***" << endl;
    cout << "\t\tA inventory keeping and billing application" << endl;
    cout << "\n\t\tAuthor: Tasnim Zotder" << endl;
    cout << "\t\tInst: Lovely Professional University" << endl;
    cout << "\n\t\tCopyright: Tasnim Zotder | 2020" << endl;
}

// Message for Admin users
void headerAdminMessage() {
    cout << "\n\t\t\t"
        << "*** Inventory Management System - Admin ***\n"
        << endl;
    cout << "\t\t\t\t---Commands---" << endl;
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
    cout << "\t\t\t\t---Commands---" << endl;
    cout << "1. 'add' - To add existing product [Product_Code] to billing list" << endl;
    cout << "2. 'generate' - To generate bill" << endl;
    cout << "3. 'show' - To show all products in billing list" << endl;
    cout << "4. 'delete' - To delete a product [Product_Code] from bill" << endl;
    cout << "5. 'search' - To search a product [Product_Code] in inventory" << endl;
    cout << "6. 'exit' - To exit the billing menu" << endl;
}

// Commands for Admins
void runAdminCommands(string query) {
    headerAdminMessage();

    cout << "\n\n"
        << "Enter the query:"
        << " ";
    cin >> query;
    system("CLS");

    if (query != "exit") {
        if (query == "show") {
            cout << "\t Inventory List" << endl;
            Admin.showProducts();

            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");
        }
        else if (query == "add") {
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
        else if (query == "delete") {
            string productCode;
            cout << "\tPlease enter the Product_Code: ";
            cin >> productCode;

            Admin.deleteProduct(productCode);
            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");
        }
        else if (query == "update") {
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
        else if (query == "search") {
            string productCode;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Admin.searchOne(productCode);

            cout << "\nPress Enter to Continue: ";
            cin.ignore();
            cin.ignore();
            system("CLS");
        }
        // Billing System
        else if (query == "bill") {
            headerBillMessage();

            cout << "\n\n"
                << "Enter the query:"
                << " ";
            cin >> query;
            system("CLS");

            while (query != "exit") {
                if (query == "show") {
                    Admin.showProducts();
                }
                else if (query == "search") {
                    string productCode;

                    cout << "Please enter the Product_Code ";
                    cin >> productCode;

                    Admin.searchOne(productCode);
                }
                else if (query == "add") {
                    string productCode;

                    cout << "Please Enter Product Code: " << endl;
                    cin >> productCode;

                    Bill.billAddProduct(productCode);
                }
                else if (query == "delete") {
                    string productCode;

                    cout << "Please Enter Product Code: " << endl;
                    cin >> productCode;

                    Bill.billDeleteProduct(productCode);
                }
                else if (query == "bill") {
                    Bill.generateBill();
                }
                else {
                    cout << "\t"
                        << "Please enter a valid command!" << endl;
                }
                headerAdminMessage();
                cout << "\n\n"
                    << "Enter the query:"
                    << " ";
                cin >> query;
                system("CLS");
            }
            system("CLS");
        }
        // Bad query
        else {
            system("CLS");
            cout << "\t"
                << "Please enter a valid command!" << endl;
            runAdminCommands(query);
        }
        runAdminCommands(query);
    }
    else {
        system("CLS");
        cout << "See you again!\n"
            << endl;
    }
}

int main() {
    welcomeMessage();
    cout << "\nPress Enter to Continue: ";
    cin.ignore();
    system("CLS");
    runAdminCommands(query);
}