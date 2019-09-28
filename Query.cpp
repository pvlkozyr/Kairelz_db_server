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
    if (item.item == "")
        return true;
    else return item.item == this->item;
}

ItemCheck::ItemCheck(std::string Name)
{
    this->item = Name;
}


AssemblyRange::AssemblyRange()
{

}

bool AssemblyRange::check(Assembly assembly)
{
    int flag = 1;
    for (int i = 0; i< assembly.assembly.size();i++)
    {
        for (int j = 0;j < this->assembly.size();j++)
        {
            if (assembly.assembly[i].item == this->assembly[j].item && assembly.assembly[i].number == this->assembly[j].number) {
                flag = 0;
                break;
            }
            flag = 1;
        }
        if (flag == 1) return false;
    }
    return true;
}

AssemblyRange::AssemblyRange(std::string str_range)
{
    int pos=0;
    int pos1;
    while (pos !=std::string::npos)
    {
    pos = str_range.find('_',pos);
    Element element;
    for (int i = 0;i < 10;i++)
    {
    if (pos != std::string::npos)
    {
        element.item = str_range.substr(0,pos);
        pos1 = str_range.find(pos,' ');
        element.number = str_range.substr(pos+1,pos1);
        this->assembly.push_back(element);
    }
    }
    }
}

std::string Query::read_field(std::string field_name, std::string query) {
    int pos = query.find(field_name);
//    std::cout << "pos: " <<pos;
    if(pos != std::string::npos) {
        int pos1 = query.find(':', pos+ 1);
        unsigned int value_index = pos + field_name.length();
        if(pos1 != std::string::npos) {
           //std::cout << query.substr(value_index, pos1 - value_index ) << ":" << field_name << "\n" ;
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
    this->assemblyRange = AssemblyRange(read_field("assemblyRange=", query));
}
bool Query::check(Record record) {
//    std::cout << "check"<< std::endl;
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
    record.assembly.assembly = this->assemblyRange.assembly;
}