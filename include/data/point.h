#pragma once
#include "place.h"
#include "header.h"
class point {
	place* arrival;		//到达的地点
	size_t arrive, leave;	//到达的时间和离开的时间(从0时经过的分钟数)
public:  
	point(place *x, size_t a = 0, size_t b = 0):arrival(x), arrive(a), leave(b) {
		if( a > b ) std::swap(arrive,leave);
	}
	point(){}
	~point(){}
	bool SetPlace(place* temp) ;	//设置地点
	bool SetTime(std::pair<size_t, size_t>);//设置到达和离开时间
	bool SetArriveTime(size_t temp) ;		//设置到达时间
	bool SetLeaveTime(size_t temp) ;		//设置离开时间
	place* GetPlace() ;						//获取地点
	size_t GetArriveTime() ; 				//获取到达时间
	size_t GetLeaveTime() ;					//获取离开时间
	bool Collision(point temp) ; 			//判断是否有相交的时间段
	friend bool operator == (const point& a, const point& b) ; 
	friend bool operator == (const point& a, const place& b) ;
	friend std::ostream& operator << (std::ostream &out, const point& a) ;
	friend std::istream& operator >> (std::istream &in, point& a) ;
};

