#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_NO_MULTITHREADING
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <sstream>
#include <string>

#define main inventory_application_main
#include "../src/main.cpp"
#undef main

namespace {

class ConsoleCapture {
public:
    explicit ConsoleCapture(std::istream& input)
        : originalInputBuffer_(std::cin.rdbuf()),
          originalOutputBuffer_(std::cout.rdbuf()),
          originalOutputFlags_(std::cout.flags()),
          originalOutputPrecision_(std::cout.precision()) {
        std::cin.clear();
        std::cin.rdbuf(input.rdbuf());
        std::cout.rdbuf(output_.rdbuf());
    }

    ~ConsoleCapture() {
        std::cin.rdbuf(originalInputBuffer_);
        std::cin.clear();
        std::cout.rdbuf(originalOutputBuffer_);
        std::cout.flags(originalOutputFlags_);
        std::cout.precision(originalOutputPrecision_);
    }

    std::string output() const {
        return output_.str();
    }

private:
    std::streambuf* originalInputBuffer_;
    std::streambuf* originalOutputBuffer_;
    std::ios::fmtflags originalOutputFlags_;
    std::streamsize originalOutputPrecision_;
    std::ostringstream output_;
};

std::string runProgram(const std::string& inputText) {
    std::istringstream input(inputText);
    ConsoleCapture capture(input);
    inventory_application_main();
    return capture.output();
}

}  // namespace

TEST_CASE("a product can be added") {
    const std::string output = runProgram(
        "1\n101\nNotebook\n4.50\n12\n4\n");

    CHECK(output.find("Product added.") != std::string::npos);
}

TEST_CASE("a duplicate product ID is rejected") {
    const std::string output = runProgram(
        "1\n101\nNotebook\n4.50\n12\n"
        "1\n101\nPen\n1.25\n20\n4\n");

    CHECK(output.find("Product added.") != std::string::npos);
    CHECK(output.find("Invalid details or product ID already exists.") !=
          std::string::npos);
}

TEST_CASE("products can be listed") {
    const std::string output = runProgram(
        "1\n101\nNotebook\n4.50\n12\n"
        "2\n4\n");

    CHECK(output.find("ID  Name") != std::string::npos);
    CHECK(output.find("101") != std::string::npos);
    CHECK(output.find("Notebook") != std::string::npos);
    CHECK(output.find("$4.50") != std::string::npos);
    CHECK(output.find("12") != std::string::npos);
}

TEST_CASE("a valid sale reduces the product stock") {
    const std::string output = runProgram(
        "1\n101\nNotebook\n4.50\n12\n"
        "3\n101\n5\n"
        "2\n4\n");

    CHECK(output.find("Sale recorded.") != std::string::npos);
    CHECK(output.find("Notebook") != std::string::npos);
    CHECK(output.find("7") != std::string::npos);
}

TEST_CASE("a sale larger than available stock is rejected") {
    const std::string output = runProgram(
        "1\n101\nNotebook\n4.50\n12\n"
        "3\n101\n13\n"
        "2\n4\n");

    CHECK(output.find("Sale not recorded.") != std::string::npos);
    CHECK(output.find("Notebook") != std::string::npos);
    CHECK(output.find("12") != std::string::npos);
}