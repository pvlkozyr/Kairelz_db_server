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
    std::string query = "style=select:assemblyCheck=Труборез 30 Съемник 90 Посуда 18 Халат 28 Труборез 77 Точило 60 Аптечка 8 Очки 33 Полуавтомат 89 Метчик 5";
    Query q(query);
    std::vector<Record> s = db.select_recs(q);
    std::cout << query << " found " << s.size() << "\n";

    return 0;
}