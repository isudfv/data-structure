#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <iterator>
#include <set>
#include <random>
// #include <fmt/core.h>
// #include <fmt/format.h>
using size_t = unsigned long long int;
using std::cout, std::cin, std::endl;
using uid = std::uniform_int_distribution<int>;

inline static std::vector<std::string> member{"Hanxixian", "Guojianheng", "Wenxiaoping", "penghaiping"} ;
inline static std::default_random_engine e;