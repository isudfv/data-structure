#pragma once
#include "header.h"

class place {
	
	size_t x, y; 				//地点坐标
	std::string PlaceName;		//地点名称
	std::string SchoolName;		//所属学校
	size_t property;			//地点的属性 0-宿舍 1-教学 2-餐饮 3-娱乐
	std::set<size_t> healthy; 	//访问过该地点的健康人的ID
	std::set<size_t> patient;   //访问过该地点的病人的ID
	
public:
	inline static std::map<std::pair<size_t ,size_t >,place*> CoordinatePlace;
	place() {}
	place(size_t  x, size_t  y, std::string s="", std::string m="", size_t n=0): x(x), y(y), PlaceName(s), SchoolName(m), property(n) {
		//CoordinatePlace[{x,y}] = this;
	}
	//place(const place& a) {/* CoordinatePlace[{x,y}] = this; */ }
	~place(){}
	// void insert();
	// bool ReadPlace();
	bool AddToMap();
	bool InsertHealthy(size_t);		//插入健康人的ID
	bool InsertPatient(size_t);		//插入病人的ID
	bool DeleteHealthy(size_t);		//删除健康人的ID
	bool DeletePatient(size_t);		//删除病人的ID
	std::string GetPlaceName();		//获取地点名称
	std::string GetSchoolName();	//获取所属学校
	size_t 		GetProperty();			//获取属性
	std::pair<size_t,size_t > GetCoodinate(){return {x,y};}	//获取地点坐标
	std::set<size_t> 		  GetHealthyPerson() ;		//获取访问过的健康人的ID
	std::set<size_t> 		  GetDiagnosePerson() ;		//获取访问过的病人的ID
	size_t 					  GetHazard() ;// 1-低风险(附近没有病人) 2-中(附近有病人) 3-高(有病人)
	friend bool operator == (place a ,place b) ;

	static place* FindPlaceByCoordinate(size_t  x, size_t  y) ;//通过坐标寻找地点
	static place* FindPlaceByCoordinate(std::pair<size_t ,size_t > s);
	static place* FindPlaceByCoordinate(place&);
	static std::vector<place*> FindPlaceByName(std::string);//通过名字寻找地点

	friend std::istream& operator >> (std::istream& in, place& a);
	friend std::istream& operator >> (std::istream& in, std::list<place>& a);
	friend std::ostream& operator << (std::ostream& out, place& a);
};

inline std::list<place> AllPlace;		//存放所有地点的信息(程序启动时读取文件)