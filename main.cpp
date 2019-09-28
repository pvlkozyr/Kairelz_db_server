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
    std::string query = "style=select:assemblyCheck=Пистолет_59 Пресс_73 Стамеска_2 ESEM_5 Лупа_26 Рулетка_42 Амплификатор_83 Головка_85 ESEM_91 Напылитель_34";
    Query q(query);
    std::vector<Record> s = db.select_recs(q);
    std::cout << query << " found " << s.size() << "\n";

    return 0;
}