#include <iostream>

#include "BillDesk.h"
#include "InvAdmin.h"
using namespace std;

InvAdmin Admin;
InvAdmin Bill;

string query = "stay";

// Print Welcome Message No input
void welcomeMessage() {
    cout << "\n\t*** Welcome to Restaurant Booking System ***" << endl;
    cout << "\t\tA restaurant billing application" << endl;
    cout << "\n\t\tAuthor: Tasnim Zotder" << endl;
    cout << "\t\tInst: Lovely Professional University" << endl;
    cout << "\n\t\tCopyright: Tasnim Zotder | 2020" << endl;
    cout << "\n\n"
        << "Please enter 'admin' for Adminstration Access or 'desk' for Billing Access" << endl;
}

// Message for Admin users
void headerAdminMessage() {
    cout << "\t\t\t"
        << "*** Restaurant Booking System - Admin ***\n"
        << endl;
    cout << "\t\t\t\t"
        << "---Commands---" << endl;
    cout << "1. 'add' - To add new product [Product_Code, Product_Name, Price]" << endl;
    cout << "2. 'update' - To update a product [Product_Code, (Product_Name), (Price)]" << endl;
    cout << "3. 'show' - To show all products"
        << "\t";
    cout << "4. 'delete' - To delete a product [Product_Code]"
        << "\n";
    cout << "5. 'search' - To search a product [Product_Code]\t";
    cout << "6. 'exit' - To exit the window"
        << "\n"
        << endl;
}

// Message for Desk users
void headerBillMessage() {
    cout << "\t\t\t"
        << "*** Restaurant Booking System - Bill Desk ***\n"
        << endl;
    cout << "\t\t\t\t"
        << "---Commands---" << endl;
    cout << "1. 'add' - To add new product [Product_Code]" << endl;
    cout << "2. 'bill' - To generate bill" << endl;
    cout << "3. 'show' - To show all products"
        << "\t";
    cout << "4. 'delete' - To delete a product [Product_Code]"
        << "\n";
    cout << "5. 'search' - To search a product [Product_Code]\t";
    cout << "6. 'exit' - To exit the window"
        << "\n"
        << endl;
}

// Commands for Admins
void runAdminCommands(string query) {
    headerAdminMessage();

    if (query != "exit") {
        if (query == "admin") {
            cout << "\t\tWelcome to Admin Panel"
                << "\n"
                << endl;
        }
        else if (query == "show") {
            Admin.showProducts();
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
            Admin.searchOne(productCode);
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

            Admin.searchOne(productCode);
            cout << "\nPlease enter the Product & Price: ";
            cin >> product >> price;

            Admin.updateProduct(productCode, product, price);
            Admin.searchOne(productCode);
        }
        else if (query == "search") {
            string productCode;

            cout << "Please enter the Product_Code ";
            cin >> productCode;

            Admin.searchOne(productCode);
        }
        else {
            cout << "\t"
                << "Please enter a valid command!" << endl;
        }

        cout << "\n\n"
            << "Enter the query:"
            << " ";
        cin >> query;
        system("CLS");
        runAdminCommands(query);
    }
    else {
        system("CLS");
        cout << "See you again!\n"
            << endl;
    }
}

// Commands for Desk
void runBillCommands(string query) {
    headerBillMessage();

    if (query != "exit") {
        if (query == "desk") {
            cout << "\t\tWelcome to Bill Desk"
                << "\n"
                << endl;
        }
        else if (query == "show") {
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

        cout << "\n\n"
            << "Enter the query:"
            << " ";
        cin >> query;
        system("CLS");
        runBillCommands(query);
    }
    else {
        system("CLS");
        cout << "See you again!\n"
            << endl;
    }
}

int main() {
    welcomeMessage();

    cin >> query;
    system("CLS");

    if (query == "admin") {
        runAdminCommands(query);
    }
    else if (query == "desk") {
        runBillCommands(query);
    }
}