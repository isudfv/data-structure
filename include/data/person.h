#pragma once
#include <iostream>
#include "trace.h"
#include "header.h"
#include "school.h"
class person {
protected:
	inline static std::map<size_t,person> IdPerson;
	inline static size_t total = 0; 

	std::string name ;
	size_t age;
	bool sex; //1 male  0 female 
	size_t unique_id ;
	// size_t state; //1-health 2-no symptom 3-Infected 4-Recovery
	std::string school_name;
	size_t dormitory; //宿舍
	// trace fourteen_day;
	std::vector<trace> fourteen_day;
public:
	person() {};
	person( std::string name, size_t age, bool sex, std::string school="" ): name(name), age(age), sex(sex), unique_id(++total) {
		IdPerson[total] = *this;
		fourteen_day.resize(14);
	} 
	
	virtual ~person() = default;
	bool GetSex() ;
	bool ChangeSex(bool temp) ;
	bool ChangeAge(size_t temp) ;
	// bool SetState(size_t) ;

	// size_t GetState() ;
	size_t GetAge() ;
	size_t GetUniqueId() ;
	std::string GetName() ;
	std::string GetSchoolName() ;
	place& GetDormitory() ;

	bool SetName(std::string temp) ;
	bool SetSchool(std::string temp) ;
	bool SetDormitory(size_t temp) ;
	bool SetRandomSchool();

	trace GetTrace(size_t) ;
	std::vector<trace> GetTrace();
	trace GetWholeTrace();
	bool SetRandomTrace();
	// bool ChangeTrace(const trace& );

	bool Append(std::vector<point>, size_t);
	bool Delete(std::vector<point>, size_t);
	virtual bool InsertIntoPlace(size_t);
	virtual bool DeleteFromPlace(size_t);

	std::vector<person> GetFromId(std::vector<size_t>) ;
	static person GetFromId(size_t) ;

	// bool ImportFromFile();
	// bool OutputToFile(fs::path);

	
	friend bool operator == ( const person& a, const std::string &s ){
		return a.name == s; 
	}
	friend bool operator == ( const person& a, const person &b ){
		return a == b ; 
	}
	friend std::ostream& operator << (std::ostream& out, const person& a);
	friend std::istream& operator >> (std::istream&, person&); 
};

inline std::vector<person> Person;
