#pragma once
#include "point.h"
#include "header.h"
#include "school.h"
class trace {
	std::vector<point> path;
public:
	trace() {}
	trace(std::vector<point> s): path(s){}

	std::vector<point>& GetTrace() ;

	bool AddPoint(const point&);
	bool AddPoint(std::vector<point>) ;
	void DelPoint(const point&);
	void DelPoint(const std::vector<point>&) ;
	bool ChangePoint(point from, point to) ;
	static trace RandomPath(size_t,std::string);
	std::vector<point> GetPath();
	friend bool operator == (const trace& a, const trace& b);
	friend std::ostream& operator << (std::ostream&, const trace&);
	friend std::ostream& operator << (std::ostream&, const std::vector<trace>&);
	friend std::istream& operator >> (std::istream&, trace&);
	friend std::istream& operator >> (std::istream&, std::vector<trace>&);
};
