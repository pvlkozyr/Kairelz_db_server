#include <vector>
#include <string>

struct Item{
    std::string item;
    std::string print()
    {
        return item;
    }
};
struct Number{
    int number;
    std::string print()
    {
        return std::to_string(number);
    }
};
struct Element{
    std::string item;
    std::string number;
    std::string print()
    {
        return item + " " + number;
    }

};
struct Assembly{
    std::vector<Element> assembly;
    std::string print()
    {
        std::string sbprint;
        for (int i = 0; i < assembly.size(); i++) {
            sbprint += assembly[i].print() + ",";
        }
        return sbprint;
    }
};

struct Record {
    Item item;
    Number number;
    Assembly assembly;
    std::string print()
    {
        return item.print() + "\t" + number.print() + "\t" + assembly.print();
    }
};
