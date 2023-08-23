#include<iostream>

#include "../include/print.h"
#include "../include/WriteInfile.h"

int main(int argc, char* argv[]) {
    if (argc == 2) {
        if (std::string(argv[1]) == "-c") {
            PrintHello();
        } else if (std::string(argv[1]) == "-f") {
            WriteToFile();
        }
    }
    return 0;
}
