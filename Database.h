#include "/home/pavel/Kairelz_db_server/Query.h"


class Database{
private:
    std::vector<Record> db;
public:
    Database();
    explicit Database(std::string);
    //~Database();
    void delete_recs(Query);
    void add_rec(Record);
    void add_rec(Query);
    std::vector<Record> select_recs(Query);
    void print();
};