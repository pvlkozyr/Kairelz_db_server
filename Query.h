#include <string>
#include </home/pavel/Kairelz_db_server/Record.h>

class NumberRange {
private:
    int max;
public:
    bool check(int value);
    NumberRange();
    explicit NumberRange(const std::string&);

    int min;
};

class ItemCheck {
public:
    bool check(Item item);
    ItemCheck();
    explicit ItemCheck(std::string);

    std::string item;
};

class AssemblyRange {
public:
    std::string assembly;
    bool check(Assembly assembly);
    AssemblyRange();
    explicit AssemblyRange(std::string);
};

class Query {
private:
    NumberRange numberRange;
    ItemCheck itemCheck;
    AssemblyRange assemblyRange;
    std::string read_field(std::string field_name, std::string query);
public:
    std::string style;
    Query();
    explicit Query(std::string);
    bool check(Record);
    void write(Record);
};
