#include <iostream>
#include <limits>

#include "BillDesk.h"
#include "InvAdmin.h"
using namespace std;

InvAdmin Admin;
Inventory Invent;

string query = "stay";

// Print Welcome Message No input
void welcomeMessage() {
    cout << "\n\t*** Welcome to Inventory Management System ***" << endl;

    // Need to fix this not sure how can we change it????
    cout << "\t\tA restaurant billing application" << endl;
    cout << "\n\t\tAuthor: Tasnim Zotder" << endl;
    cout << "\t\tInst: Lovely Professional University" << endl;
    cout << "\n\t\tCopyright: Tasnim Zotder | 2020" << endl;
    cout << "\n\n" << endl;
}

// Admin Commands
void headerAdminCommands() {
    cout << "\t\t\t"
        << "*** Restaurant Booking System - Admin ***\n"
        << endl;
    cout << "\t\t\t\t"
        << "---Commands---" << endl;
    cout << "1. 'add' - To add new product [Product_Code, Product_Name, Price]" << endl;
    cout << "2. 'update' - To update a product [Product_Code, (Product_Name), (Price)]" << endl;
    cout << "3. 'show' - To show all products" << endl;
    cout << "4. 'delete' - To delete a product [Product_Code]" << endl;
    cout << "5. 'search' - To search a product [Product_Code]" << endl;
    cout << "6. 'bill' - To generate bill -- Not working" << endl; // still tring to figure out how to implement
    cout << "7. 'exit' - To exit the window" << endl;
}

// Commands for Admins
void runAdminCommands() {
    headerAdminCommands();

    cout << "\n\n"
        << "Enter the query:"
        << " ";
    cin >> query;
    system("CLS");


    if (query != "exit") {
        if (query == "show") {
            cout << "\t\t*** Inventory Product List ***\n\n" << endl;
            Invent.showProducts();
            cout << "Press enter to continue" << endl;
            cin.ignore();
            cin.ignore();
        }
        else if (query == "add") {
            string productCode, product;
            float price = 0;

            cout << "Please Enter Product Code, Product & Price: " << endl;
            cin >> productCode;
            cin >> product;
            cin >> price;

            Admin.addProduct(productCode, product, price);

            cout << "\tProduct Added" << endl;
            Invent.searchOne(productCode);
            cout << "Press enter to continue" << endl;
            cin.ignore();
            cin.ignore();
        }
        else if (query == "delete") {
            string productCode;
            cout << "\tPlease enter the Product_Code: ";
            cin >> productCode;

            Admin.deleteProduct(productCode);
        }
        else if (query == "update") {
            string productCode;
            string product;
            float price;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Invent.searchOne(productCode);
            cout << "\nPlease enter the Product & Price: ";
            cin >> product >> price;

            Admin.updateProduct(productCode, product, price);
            Invent.searchOne(productCode);
        }
        else if (query == "search") {
            string productCode;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Invent.searchOne(productCode);
        }
        else if (query == "bill") {
            
            
        }
        else {
            cout << "\t"
                << "Please enter a valid command!" << endl;
        }
        system("CLS");
        runAdminCommands();
    }
    else {
        system("CLS");
        cout << "See you again!\n"
            << endl;
    }
}

// Billing Commands
void headerBillCommands() {
    cout << "\t\t\t"
        << "*** Restaurant Booking System - Bill Desk ***\n"
        << endl;
    cout << "\t\t\t\t"
        << "---Commands---" << endl;
    cout << "1. 'add' - To add new product [Product_Code]" << endl;
    cout << "2. 'bill' - To generate bill" << endl;
    cout << "4. 'delete' - To delete a product [Product_Code]"
        << "\n";
    cout << "5. 'search' - To search a product [Product_Code]\t";
    cout << "6. 'exit' - To exit the window"
        << "\n"
        << endl;
}

// Commands for generating bill
void runBillCommands() {
    headerBillCommands();

    cout << "\n\n"
        << "Enter the query:"
        << " ";
    cin >> query;
    system("CLS");

    if (query != "exit") {
        if (query == "search") {
            string productCode;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Invent.searchOne(productCode);
        }
        else if (query == "add") {
            string productCode;

            cout << "Please Enter Product Code: " << endl;
            cin >> productCode;

            Admin.billAddProduct(productCode);
        }
        else if (query == "delete") {
            string productCode;

            cout << "Please Enter Product Code: " << endl;
            cin >> productCode;

            Admin.billDeleteProduct(productCode);
        }
        else if (query == "bill") {
            Admin.generateBill();
        }
        else {
            cout << "\t"
                << "Please enter a valid command!" << endl;
        }

        system("CLS");
        runBillCommands();
    }
    else {
        system("CLS");
        cout << "See you again!\n"
            << endl;
    }
}

int main() {
    welcomeMessage();
    runAdminCommands();
}