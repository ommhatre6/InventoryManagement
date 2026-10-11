Inventory Management System
A beginner friendly C++ console application for managing small list of products. This program support adding products, viewing inventory and recording sales.

Features
-Add a product with an ID, name, price, and starting quantity.
-List all products and their current stock.
-Record a sale when the product exists and enough stock is available.
-Prevent a sale from Reducing stock below zero.

Requirements
-A C++ compiler
-Git for version Control.
-VS code for editing and debugging support.

Functions
1.Add product-enter a unique positive ID, a one-word name, a non-negative price, and a non-negative quantity.
2.List products-Display all products currently held in memory.
3.Sell products-Enter the product id and a quantity greater than zero that does not exceed available stock.
4.Exit-close the program.


Automated tests use doctest, a lightweight C++ testing framework. The
doctest header is included in `tests/doctest.h`, so configuring the project
does not download test dependencies.

The tests exercise the existing console program with scripted input and check
its output. They cover adding a product, rejecting a duplicate ID, listing
products, recording a valid sale, and rejecting a sale larger than available
stock.

Building and running the tests with CMake
1. Install CMake and a C++ compiler. On Windows, the MinGW-w64 compiler and
   `mingw32-make` can be used.
2. Open PowerShell in the repository folder.
3. Configure the project for MinGW:

   ```powershell
   cmake -S . -B build -G "MinGW Makefiles"
   ```

   For Visual Studio, omit `-G "MinGW Makefiles"`.
4. Build the application and test runner:

   ```powershell
   cmake --build build
   ```
5. Run the automated tests:

   ```powershell
   ctest --test-dir build --output-on-failure
   ```

CMake builds the console program as `inventory_app` and the doctest runner as
`inventory_tests`. To build only the tests, use
`cmake --build build --target inventory_tests`.
