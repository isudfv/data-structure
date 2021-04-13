#pragma once
#include "header.h"

class place {
	
	size_t x, y; 
	std::string PlaceName;
	std::string SchoolName;
	size_t property;
	std::set<size_t> visit; 	//unique_id who is visited
	std::set<size_t> patient; //unique_id who is diagnosed
public:
	inline static std::map<std::pair<size_t ,size_t >,place*> CoordinatePlace;
	place() {};
	place(size_t  x, size_t  y, std::string s="", std::string m="", size_t n=0): x(x), y(y), PlaceName(s), SchoolName(m), property(n) {
		CoordinatePlace[{x,y}] = this;
	}
	place(const place& a) {
		*this = a;
		CoordinatePlace[{x,y}] = this;
	}
	~place(){}

	// void insert();
	bool ReadPlace();
	bool InsertHealthy(size_t);
	bool InsertPatient(size_t);
	bool DeleteHealthy(size_t);
	bool DeletePatient(size_t);
	std::string GetPlaceName();
	std::string GetSchoolName();
	size_t GetProperty();
	std::pair<size_t ,size_t > GetCoodinate(){return {x,y};}
	std::set<size_t> GetVisitPerson() ;
	std::set<size_t> GetDiagnosePerson() ;
	size_t GetHazard() ;// 1-low(no patient visited) 2-mid(the near place patent visited) 3-high(patient visited)
	friend bool operator ==(place a ,place b) ;
	static size_t FindPlaceByCoordinate(size_t  x, size_t  y) ;
	static size_t FindPlaceByCoordinate(std::pair<size_t ,size_t > s);
	friend std::istream& operator >> (std::istream& in, place& a);
	friend std::istream& operator >> (std::istream& in, std::vector<place>& a);
	friend std::ostream& operator << (std::ostream& out, place& a);
};

inline std::vector<place> AllPlace;