#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "/home/pavel/Kairelz_db_server/Database.h"
#include <cstring>

Database::Database() {
    std::cout << "no database file specified" << std::endl;
}


Database::Database(std::string fname) {
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cout << "file doesn't exist" << std::endl;
        return;
    }
    int c = 0;
    std::string tmp = "";
    while (!file.eof()) {
        Record t;
        std::getline(file, tmp, '\t');
        if (tmp == "") break;
        t.item.item = tmp;
        std::getline(file, tmp, '\t');
        t.number.number = std::stoi(tmp);
        Element a;
        for (int i = 0;i<10;i++)
        {
            std::getline(file, tmp, ' ');
            a.item = tmp;
            std::getline(file, tmp, ',');
            a.number = tmp;
            t.assembly.assembly.push_back(a);
        }
//        std::cout << "Added: " <<  t.print() << std::endl;
        std::getline(file, tmp, '\n');
        db.push_back(t);
    }
    std::cout << "added: " << db.size() << std::endl;
    file.close();

}


void Database::print()
{
    std::ofstream file();
    for (int i = 0; i < db.size();i++)
    {
        std::cout<<db[i].print()<<std::endl;
    }
}

void Database::add_rec(Record t) {
    std::cout << "Record added successfully" << std::endl;
    db.push_back(t);
}

void Database::add_rec(Query q) {
    Record t;
    q.write(t);
    std::cout << "Record added successfully" << std::endl;
    db.push_back(t);
}

std::vector<Record> Database::select_recs(Query q)
{
    std::vector<Record> s;
    for (size_t i = 0; i < db.size(); i++) {
        if (q.check(db[i])) {
//           std::cout<<db[i].item.print()<<std::endl;
            s.push_back(db[i]);
        }
    }
    return s;
}

void Database::delete_recs(Query q) {
    for (size_t i = 0;i < db.size();i++)
    {
        if (q.check(db[i])) db.erase(db.begin() + i);
    }
    std::cout << "current size is : " << db.size() << std::endl;
}

