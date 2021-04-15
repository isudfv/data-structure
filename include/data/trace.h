#pragma once
#include "point.h"
#include "header.h"
#include "school.h"
class trace {
	std::vector<point> path;		//单日的行程点集合
public:
	trace() {}
	trace(std::vector<point> s): path(s){}

	bool AddPoint(const point&);		 	//添加点(一或多个)
	bool AddPoint(std::vector<point>) ;
	bool DelPoint(const point&);			//删除点(一或多个)
	bool DelPoint(const std::vector<point>&) ;
	bool ChangePoint(point from, point to) ;		//修改指定点的信息
	static trace RandomPath(place*,std::string);	//随机生成一天的行程
	std::vector<point> GetPath();					//获取路径
	friend bool operator == (const trace& a, const trace& b);
	friend std::ostream& operator << (std::ostream&, const trace&);
	friend std::ostream& operator << (std::ostream&, const std::vector<trace>&);
	friend std::istream& operator >> (std::istream&, trace&);
	friend std::istream& operator >> (std::istream&, std::vector<trace>&);
};
