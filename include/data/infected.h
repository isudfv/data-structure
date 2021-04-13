#pragma once
#include "person.h"

class infected: public person{
private:
    bool NoSymptom; //1-无症状 0-有症状
public:
    infected(std::string name, size_t age, bool sex): person(name, age, sex), NoSymptom(0){}
    infected(const person& p): person(p) {}
    ~infected(){}
    bool GetNoSymptom();
    virtual bool InsertIntoPlace(size_t);
    virtual bool DeleteFromPlace(size_t);
};

inline std::vector<infected> Infected; 

bool PersonToInfected(const person& p);
bool PersonToInfected(const std::string& s); 