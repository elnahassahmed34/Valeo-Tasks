#include "../include/WriteInfile.h"
#include <fstream>

void WriteToFile() {
    std::ofstream file("helloWorld.txt");
    if (file.is_open()) {
        file << "helloWorld" << std::endl;
        file.close();
    }
}
