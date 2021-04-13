#pragma once
#include "place.h"
#include "header.h"
class point {
	size_t arrival;
	size_t arrive, leave;
public:  
	point(size_t x, size_t a = 0, size_t b = 0):arrival(x), arrive(a), leave(b) {
		if( a > b ) std::swap(arrive,leave);
	}
	point(){}
	~point(){}
	bool SetPlace(size_t temp) ;
	bool SetTime(size_t temp) ;
	size_t GetPlace() ;
	size_t GetArriveTime() ; 
	size_t GetLeaveTime() ;
	bool Collision(point temp) ; 
	friend bool operator == (const point& a, const point& b) ; 
	friend bool operator == (const point& a, const place& b) ;
	friend std::ostream& operator << (std::ostream &out, const point& a) ;
	friend std::istream& operator >> (std::istream &in, const point& a) ;
};

