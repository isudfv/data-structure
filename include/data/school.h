#pragma once
#include "header.h"
#include "place.h"

struct school
{
    std::vector<size_t> dormitory;     //0
    std::vector<size_t> teaching_area; //1
    std::vector<size_t> canteen;       //2
    std::vector<size_t> recreation;    //3
    std::map<size_t,std::vector<size_t>*> v{{0,&dormitory}, {1,&teaching_area}, {2,&canteen}, {3,&recreation}};

    size_t RandomDormitory(){
        return uid(0,dormitory.size())(e);
    }
    size_t RandomClassroom(){
        return uid(0,teaching_area.size())(e);
    }
    size_t RandomCanteen(){
        return uid(0,canteen.size())(e);
    }
    size_t RandomRecreation(){
        return uid(0,recreation.size())(e);
    }
};

// enum SchoolName{scut, sysu, gut, gufs, gmu, gucm, xcm, scnu, gpu}; 
inline school schools[10];
inline std::map<std::string,size_t> SchoolName{{"SCUT",0}, {"SYSU",1}, {"GUT",2}, {"GUFS",3}, {"GMU",4}, {"GUCM",5}, {"XCM",6}, {"GPU",7}, {"SCNU",8}, {"GAFA",9}};

inline std::string RandomSchool(){
    size_t get = uid(0,9)(e);
    return find_if(begin(SchoolName), end(SchoolName), [&get](auto &p){return p.second == get;}) -> first;
}
