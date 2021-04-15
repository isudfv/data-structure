#pragma once
#include "header.h"
#include "place.h"

struct school
{
    std::vector<place*> dormitory;     //0 宿舍
    std::vector<place*> teaching_area; //1 教学
    std::vector<place*> canteen;       //2 餐饮
    std::vector<place*> recreation;    //3 娱乐
    std::map<size_t,std::vector<place*>*> v{{0,&dormitory}, {1,&teaching_area}, {2,&canteen}, {3,&recreation}};

    place* RandomDormitory(){
        return dormitory[uid(0,dormitory.size()-1)(e)];
    }
    place* RandomClassroom(){
        return teaching_area[uid(0,teaching_area.size()-1)(e)];
    }
    place* RandomCanteen(){
        return canteen[uid(0,canteen.size()-1)(e)];
    }
    place* RandomRecreation(){
        return recreation[uid(0,recreation.size()-1)(e)];
    }
};

// enum SchoolName{scut, sysu, gut, gufs, gmu, gucm, xcm, scnu, gpu}; 
inline school schools[10];
inline std::map<std::string,size_t> SchoolName{
    {"SCUT",0},         //华南理工大学
    {"SYSU",1},         //中山大学
    {"GUT",2},          //广东工业大学
    {"GUFS",3},         //广东外语外贸大学
    {"GMU",4},          //广州大学
    {"GUCM",5},         //广州中医药大学
    {"XCM",6},          //星海音乐学院
    {"GPU",7},          //广州药科大学
    {"SCNU",8},         //华南师范大学
    {"GAFA",9}};        //广州美术学院

inline std::string RandomSchool(){
    size_t get = uid(0,9)(e);
    return find_if(begin(SchoolName), end(SchoolName), [&get](auto &p){return p.second == get;}) -> first;
}       //
