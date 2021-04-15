#pragma once
#include "header.h"


bool ReadPlace(std::string filename);  //读取地点信息 1-成功 2-失败 (下同)
bool SavePlace(std::string filename);

bool ImportPerson(std::string filename);
bool ReadPerson(std::string filename);  //读取人员信息
bool SavePerson(std::string filename);