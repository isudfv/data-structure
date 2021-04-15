#pragma once
#include <iostream>
#include "trace.h"
#include "header.h"
#include "school.h"
class person {
protected:
	inline static std::map<size_t,person*> IdPerson;
	inline static size_t total = 0; 

	std::string name ;	//姓名
	size_t age;			//年龄
	bool sex; 			//1-男  0-女 
	size_t unique_id ;
	// size_t state; //1-health 2-no symptom 3-Infected 4-Recovery
	std::string school_name;	//所属学校名称
	place* dormitory; 	//宿舍
	// trace fourteen_day;
	std::vector<trace> fourteen_day;	//过去十四日行程
public:
	person() {
		IdPerson[++total] = this;
		fourteen_day.resize(14);
	}
	person( std::string name, size_t age, bool sex, std::string school="", place *dormitory = nullptr )
	:name(name), age(age), sex(sex), unique_id(++total), dormitory(dormitory) {
		IdPerson[total] = this;
		fourteen_day.resize(14);
	} 
	
	virtual ~person() = default;
	bool GetSex() ;					//获取性别
	bool ChangeSex(bool temp) ;		//修改性别
	bool ChangeAge(size_t temp) ;	//修改年龄
	// bool SetState(size_t) ;
	// size_t GetState() ;
	size_t GetAge() ;				//获取年龄
	size_t GetUniqueId() ;			//获取编号	
	std::string GetName() ;			//获取姓名
	std::string GetSchoolName() ;	//获取学校名称
	place* GetDormitory() ;			//获取宿舍

	bool SetName(std::string temp) ;	//设置姓名
	bool SetSchool(std::string temp) ;	//设置学校
	bool SetDormitory(place* temp) ;	//设置宿舍
	bool SetRandomSchool();				//随机设置学校

	trace GetTrace(size_t) ;			//获取第n+1天的行程
	std::vector<trace> GetTrace();		//获取全部行程
	trace GetWholeTrace();				//同上，整合为一个trace
	bool SetRandomTrace();				//随机生成行程
	// bool ChangeTrace(const trace& );

	bool Append(std::vector<point>, size_t);	//将点加入到n+1天的行程
	bool Delete(std::vector<point>, size_t);	//将点从n+1天的行程删除
	virtual bool InsertIntoPlace(place*);		//将人员信息加入到地点
	virtual bool DeleteFromPlace(place*);		//将人员信息从地点删除

	static std::vector<person*> GetFromId(const std::vector<size_t>&) ;	//通过ID查找人员
	static person* 			    GetFromId(size_t) ;						//同上
	static std::vector<person*> GetFromName(const std::string&) ; 				//通过姓名查找人员
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
	friend std::istream& operator >> (std::istream&, std::list<person>&);
};

inline std::list<person> Person;		//存放所有人员信息(程序启动时读取文件)
