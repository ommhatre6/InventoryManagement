Project Name: Inventory Management System.
Language: C++.
Repository:InventoryManagement.git
IDE: VS code
AI assistant: Github Copilot.

Task: To create and Validate AI-Augmented Software development .
Software: Inventory Management System.

Prompt For code generation: Based on this README, Generate a simple C++ Inventory Management System using a Product struct. It should let the user add products, view them, and record sales while preventing stock from becoming negative.

Prompt for code explanation: Explain this C++ inventory code briefly, including how it adds products, lists them, and prevents selling more stock than is available.



Context Provided: I provided the project README describing a beginner-friendly C++ console Inventory Management System. It specifies a Product struct with an ID, one-word name, price, and starting quantity; a menu to add products, list inventory, record sales, and exit; and a rule that sales must not reduce stock below zero. Products are stored in memory while the program runs.

Test execution: I built and ran the automated tests for the inventory application.

Test coverage: The tests check that a valid product can be added, duplicate product IDs are rejected, products are listed with their details, a valid sale reduces stock, and a sale exceeding available stock is rejected without changing inventory.

Result: All 5 test cases passed.

Build note: The default MinGW compiler failed to build the tests without useful diagnostics. I used the MSYS2 UCRT64 compiler to build and run them successfully.
