#include "/home/pavel/Kairelz_db_server/Query.h"
#include<iostream>
NumberRange::NumberRange()
{
    max = -1;
    min = -1;
}

NumberRange::NumberRange(const std::string& field)
{
    int pos = field.find(' ');
    if (pos != std::string::npos)
    {
        this->min = std::stoi(field.substr(0,pos));
        this->max = std::stoi(field.substr(pos+1));
    }
}

bool NumberRange::check(int value) {
    return true;
//    if (max == -1 && min == -1)
//        return true;
//    else if (max == -1)
//        return value == min;
//    else
//        return value >= min && value <= max;
}


ItemCheck::ItemCheck()
{
    item = "";
}

bool ItemCheck::check(Item item)
{
//    std::cout << "Itemcheck : " << item.item << ":" << this->item <<std::endl;
    if (this->item == "")
        return true;
    else return item.item == this->item;
}

ItemCheck::ItemCheck(std::string Name)
{
    this->item = Name;
}


AssemblyRange::AssemblyRange()
{
    assembly = "";
}

bool AssemblyRange::check(Assembly assembly)
{
    // std::cout << assembly.print()<<std::endl;
    return assembly.print() == this->assembly;
}

AssemblyRange::AssemblyRange(std::string str_range)
{
    this->assembly = str_range + " ";
}

std::string Query::read_field(std::string field_name, std::string query) {
    int pos = query.find(field_name);
//    std::cout << "pos: " <<pos;
    if(pos != std::string::npos) {
        int pos1 = query.find(':', pos+ 1);
        unsigned int value_index = pos + field_name.length();
        if(pos1 != std::string::npos) {
//           std::cout << query.substr(value_index, pos1 - value_index ) << ":" << field_name << "\n" ;
            return query.substr(value_index, pos1 - value_index );
        } else {
//            std::cout << query.substr(value_index) << ":npos :" << field_name << "\n" ;
            return query.substr(value_index);
        }
    } else {
        return "";
    }
}

Query::Query(std::string query) {
    this->style = read_field("style=", query);
    this->itemCheck = ItemCheck(read_field("itemCheck=", query));
    this->numberRange = NumberRange(read_field("numberRange=", query));
    this->assemblyRange = AssemblyRange(read_field("assemblyCheck=", query));
}
bool Query::check(Record record) {
//    std::cout << "check ";
//    std::cout << this->numberRange.check(record.number.number) << " ";
//    std::cout << this->itemCheck.check(record.item) << " ";
//    std::cout << this->assemblyRange.check(record.assembly)  << "\n";
    return this->numberRange.check(record.number.number)
           &&
           this->itemCheck.check(record.item)
           &&
           this->assemblyRange.check(record.assembly);
}

void Query::write(Record record)
{
    record.item.item = this->itemCheck.item;
    record.number.number = this->numberRange.min;
}