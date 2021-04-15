#pragma once
#include "person.h"

class infected: public person{
private:
    bool NoSymptom; //1-无症状 0-有症状
public:
    infected(std::string name, size_t age, bool sex): person(name, age, sex), NoSymptom(0){}
    infected(const person& p): person(p), NoSymptom(0) {

    }
    ~infected(){}
    bool GetNoSymptom();    //获取该病人是否为无症状感染
    virtual bool InsertIntoPlace(place*);   //将人员信息加入到地点
    virtual bool DeleteFromPlace(place*);   //将人员信息从地点删除
};

inline std::vector<infected> Infected; 

bool HealthyToInfected(const person& p);
bool HealthyToInfected(const std::string& s); 