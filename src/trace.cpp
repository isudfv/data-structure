#include "trace.h"
std::vector<point>& trace::GetTrace() {
    return path;
}

bool trace::AddPoint(const point& temp){
    try
    {
        path.push_back(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }   return 1;
}

bool trace::AddPoint(std::vector<point> temp) {
    try
    { 
        path.insert(end(path), begin(temp), end(temp)); 
        // cout << path.size() << "+++++" << endl ; 
    }
    catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
        return 0; 
    }
    return 1;
}

void trace::DelPoint(const std::vector<point>& temp) {
    remove_if( begin(path), end(path), [&temp](const auto& p){ 
        return find(begin(temp), end(temp), p) != end(temp);
    });  
}

void trace::DelPoint(const point& temp) {
    remove(begin(path), end(path), temp);
}

bool trace::ChangePoint(point from, point to) {
    /* for(int i = 0;i < path.size();i++){
        if((path[i].GetPlace() == from.GetPlace())
        &&(path[i].GetArriveTime() == from.GetArriveTime())
        &&(path[i].GetLeaveTime() == from.GetLeaveTime())){
            path.erase(path.begin()+i);
            path.push_back(to);
            return 1;
        }        
    } */
    std::replace( begin(path), end(path), from, to ); 
    return 0;
}

bool operator == (const trace& a, const trace& b){
    return a.path == b.path; 
}

trace trace::RandomPath(size_t dormitory, std::string school_name) {
    trace temp;
    school school = schools[SchoolName[school_name]];
    // fmt::print("Dormitory: {}   School: {}\n", dormitory, school_name);
    std::uniform_int_distribution<size_t>
        leaving_dormitory((size_t)7.5*60,8*60),
        breakfest_hours(8*60,(size_t)8.5*60),
        morning_class(9*60,12*60),
        lunch_hours(12*60,13*60),
        afternoon_class(14*60,17*60),
        recreation_hours(17*60,20*60),
        returning_dormitory(20*60,22*60),
        duration(10,30);

    temp.AddPoint({
        {dormitory, 0, leaving_dormitory(e)},
        {dormitory, returning_dormitory(e), 0},
        {school.RandomCanteen(), breakfest_hours(e), breakfest_hours(e)},
        {school.RandomClassroom(), morning_class(e), morning_class(e)},
        {school.RandomCanteen(), lunch_hours(e), lunch_hours(e)},
        {school.RandomClassroom(), afternoon_class(e), afternoon_class(e)},
        {school.RandomRecreation(), recreation_hours(e), recreation_hours(e)}
    });
    return temp;
}

std::vector<point> trace::GetPath(){
    return path;
}

std::ostream &operator << (std::ostream &out, const trace &a){
    // cout << a.path.size() << "===" << endl;
    for (auto &p: a.path)
        out << p << "  ";
    return out;
}

std::ostream &operator << (std::ostream &out, const std::vector<trace> &a){
    for (auto &p: a)
        out << p << endl;
    return out;
}

std::istream& operator >> (std::istream& in, trace& a){
    point temp;
    while(in >> temp) a.AddPoint(temp);
    return in;
}

std::istream &operator >> (std::istream &in, std::vector<trace> &a){
    std::string s;
    for (auto &p: a){
        std::getline(in, s);
        std::stringstream IN(s);
        IN >> p;
    }
    return in;
}