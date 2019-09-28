
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include "gen.h"
#include "cstdlib"


void gen(const std::string& izd, const std::string& out, int SIZE) {
    std::srand(unsigned(std::time(0)));
    std::string item, assembly;
    std::ifstream file(izd);
    std::vector<std::string> items;
    int i,j;
    while (!file.eof())
    {
        file >> item;
        items.push_back(item);
    }
    std::ofstream file1(out);
    for (i = 0; i< SIZE;i++)
    {
        file1 << items[rand() % items.size()] + " ";
        file1 << std::to_string(rand() % 1000) + " ";
        for (j = 0; j < 10;j++)
        {
            assembly = "";
            assembly +=  items[rand() % items.size()];
            assembly += "_";
            assembly += std::to_string(rand() % 100);
            file1 << assembly + " ";
        }
    }
    file1.close();
    file.close();
}