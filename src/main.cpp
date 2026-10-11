#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    int id;
    string name;
    double price;
    int quantity;
};

int main() {
    vector<Product> products;
    int choice;

    do {
        cout << "\nInventory Management System\n"
             << "1. Add product\n"
             << "2. List products\n"
             << "3. Record sale\n"
             << "4. Exit\n"
             << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Product product;

                cout << "Product ID: ";
                cin >> product.id;

                cout << "Product name: ";
                cin >> product.name;

                cout << "Price: $";
                cin >> product.price;

                cout << "Starting quantity: ";
                cin >> product.quantity;

                bool valid = product.id > 0 &&
                             product.price >= 0 &&
                             product.quantity >= 0;

                for (const Product& existing : products) {
                    if (existing.id == product.id) {
                        valid = false;
                    }
                }

                if (valid) {
                    products.push_back(product);
                    cout << "Product added.\n";
                } else {
                    cout << "Invalid details or product ID already exists.\n";
                }
                break;
            }

            case 2:
                if (products.empty()) {
                    cout << "Inventory is empty.\n";
                } else {
                    cout << "\nID  Name                 Price       Stock\n";

                    for (const Product& product : products) {
                        cout << left << setw(4) << product.id
                             << setw(21) << product.name
                             << "$" << fixed << setprecision(2)
                             << setw(10) << product.price
                             << product.quantity << '\n';
                    }
                }
                break;

            case 3: {
                int id, amount;
                bool saleRecorded = false;

                cout << "Product ID: ";
                cin >> id;

                cout << "Quantity to sell: ";
                cin >> amount;

                for (Product& product : products) {
                    if (product.id == id &&
                        amount > 0 &&
                        amount <= product.quantity) {
                        product.quantity -= amount;
                        saleRecorded = true;
                        break;
                    }
                }

                if (saleRecorded) {
                    cout << "Sale recorded.\n";
                } else {
                    cout << "Sale not recorded. Check the product ID and available stock.\n";
                }
                break;
            }

            case 4:
                cout << "Goodbye.\n";
                break;

            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}