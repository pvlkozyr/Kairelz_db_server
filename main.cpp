#include <iostream>
#include <vector>
#include <fstream>
#include "/home/pavel/Kairelz_db_server/Database.h"
#include "/home/pavel/Kairelz_db_server/gen.h"
#include <string>

int main() {
//    gen("/home/pavel/Kairelz_db_server/in.txt",
//        "/home/pavel/Kairelz_db_server/db.txt",5);

    Database db("/home/pavel/Kairelz_db_server/db.txt");
//    db.print();
    std::string query = "style=select:assemblyCheck=Блок 16,Станция 16,Принтер 23,Съемник 89,Мини-фен 68,Ножовка 0,Мини-фен 61,Наковальня 18,Торцеватель 95,Лом 94,";
    Query q(query);
    std::vector<Record> s = db.select_recs(q);
    std::cout << query << " found " << s.size() << "\n";

    return 0;
}