AI ENGINEERING JOURNAL

Project: Inventory Management System
Language: C++
Repository: InventoryManagement
IDE: Visual Studio Code.

AI assistant: GitHub Copilot
Test framework: doctest
Compiler: MSYS2 UCRT64 GCC (version not recorded)



TASK
----
Create a beginner-friendly C++ console application to add products, list
inventory, and record sales without allowing stock to become negative.

CONTEXT PROVIDED
----------------
I provided the README requirements: use a Product struct with an ID, name,
price, and quantity; provide menu options to add products, list inventory,
record sales, and exit; store products in memory; and prevent sales exceeding
available stock.

AI PROMPTS AND MY DECISIONS
---------------------------

Code generation:
"Based on this README, generate a simple C++ Inventory Management System
using a Product struct. It should let the user add products, view them, and
record sales while preventing stock from becoming negative."

I reviewed Copilot's suggestion against the requirements and kept the simple
struct-and-menu design. I checked that invalid sales do not reduce stock.

Code explanation:
"Explain this C++ inventory code briefly, including how it adds products,
lists them, and prevents selling more stock than is available."

I compared the explanation with the source code to understand the program's
menu, product listing, and sale validation.

Test generation:
"Use doctest to create beginner-friendly automated tests for my C++ Inventory Management System. Read README.md and the existing source code first. Test adding a product, rejecting duplicate IDs, listing products, recording a valid sale, and rejecting a sale that exceeds available stock. Show which files to create or update and how to build and run the tests. Do not change the program’s behavior or claim the tests pass unless they have actually been run."

I reviewed the suggested test inputs and expected results before running them.

Debugging:
"Help me diagnose this CMake/compiler error. Explain the cause and suggest the
smallest correction. Error: [paste the exact error]."

I used the build errors to identify the generator mismatch, old compiler
problems, doctest threading issue, and CMake target-order issue. I used a
separate build folder, switched to MSYS2 UCRT64 GCC, and placed target settings
after creating the test target. CTest could not find the test executable when
the build had failed, so I ran CTest after rebuilding.

BUILD AND TEST

From the project folder, the intended commands are:

  cmake -S . -B build-ucrt -G "MinGW Makefiles" ^
    -DCMAKE_C_COMPILER=C:/msys64/ucrt64/bin/gcc.exe ^
    -DCMAKE_CXX_COMPILER=C:/msys64/ucrt64/bin/g++.exe ^
    -DCMAKE_MAKE_PROGRAM=C:/msys64/ucrt64/bin/mingw32-make.exe
  cmake --build build-ucrt
  ctest --test-dir build-ucrt --output-on-failure

Reported result: all 5 test cases passed. They cover adding a product,
rejecting a duplicate ID, listing products, recording a valid sale, and
rejecting an oversale without changing stock. Add the exact terminal output
and compiler version if required by the instructor.

HUMAN VALIDATION
----------------
I reviewed the code and tests against the README and used the build and test
results to validate behavior. I did not perform a refactoring task.

GIT RECORD
----------
Remote: https://github.com/ommhatre6/InventoryManagement
Commit ID and message: Not recorded; add these from `git log -1 --oneline`.

CONCLUSION
----------
Copilot assisted with code generation, explanation, test generation, and
debugging. I reviewed its suggestions and used automated tests to check the
inventory behavior. Final engineering decisions and validation were mine.
