#include "person.h"
using std::string;
using std::vector;

bool person::GetSex(){
    return sex; 
}

bool person::ChangeSex(bool temp){
    sex = temp; 
    return sex == temp; 
}

size_t person::GetAge(){
    return age; 
}

bool person::ChangeAge(size_t temp){
    age = temp; 
    return age == temp; 
}

size_t person::GetUniqueId(){
    return unique_id; 
}

/* bool person::SetState(size_t temp){
    state = temp;
    return state == temp;
}

size_t person::GetState(){
    return state;
}
 */
string person::GetName(){
    return name; 
}

string person::GetSchoolName(){
    return school_name; 
}

bool person::SetSchool(string temp){
    school_name = temp; 
    return school_name == temp; 
}

place* person::GetDormitory(){
    return dormitory; 
}

bool person::SetDormitory(place* temp){
    dormitory = temp; 
    return dormitory == temp; 
}

bool person::SetRandomSchool() {
    try
    {
        school_name = RandomSchool();
        cout << school_name <<endl;
        cout << SchoolName[school_name] << endl;
        dormitory = schools[SchoolName[school_name]].RandomDormitory();
        cout << dormitory << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }   return 1;
}

std::vector<trace> person::GetTrace(){
    return fourteen_day; 
}

trace person::GetTrace(size_t date) {
    return fourteen_day[date];
}

trace person::GetWholeTrace() {
    trace temp;
    for(auto &p: fourteen_day) {
        temp.AddPoint(p.GetPath());
    }
    return std::move(temp);
}

bool person::SetRandomTrace() {
    try
    {
        for( size_t d = 0; d < 14; ++ d ) 
            fourteen_day[d] = trace::RandomPath(dormitory,school_name);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
    
}

// bool person::ChangeTrace(const trace& temp){
//     fourteen_day = temp; 
//     return fourteen_day == temp; 
// }

bool person::InsertIntoPlace(place* temp) {
    try
    {
        temp->InsertHealthy(unique_id);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

bool person::DeleteFromPlace(place* temp) {
    try
    {
        temp->DeleteHealthy(unique_id);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

bool person::Append(std::vector<point> temp, size_t date){
    bool op = 1;
    try {
        fourteen_day[date].AddPoint(temp);
        for_each(begin(temp), end(temp), [this](auto& p){
            InsertIntoPlace(p.GetPlace());
        });
    } catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        op = 0;
    }  
    return op;
}

bool person::Delete(std::vector<point> temp, size_t date) {
    static auto all = GetWholeTrace().GetPath();
    try
    {
        fourteen_day[date].DelPoint(temp);
        for_each(begin(temp), end(temp), [this](auto& p){
            if(find(begin(all), end(all), p.GetPlace()) == end(all))
                DeleteFromPlace(p.GetPlace());
        });
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

person* person::GetFromId(size_t temp){
    return person::IdPerson[temp];
}

std::vector<person*> person::GetFromId(const std::vector<size_t>& a) {
    std::vector<person*> temp;
    for_each(begin(a), end(a), [&temp](auto &p){
        std::back_inserter(temp) = GetFromId(p);
    });
    return temp;
}

std::vector<person*> person::GetFromName(const std::string &a) {
    std::vector<person*> temp;
    for(auto &p: Person)
        if(p.GetName().find(a) != std::string::npos)
            temp.push_back(&p);
    return temp;
}

/* bool person::OutputToFile(fs::path filename) {
    std::ofstream FILE(filename);
    FILE << *this << endl << fourteen_day;
    return 1;
} */

std::ostream& operator << (std::ostream& out, const person& a) {
	// out << fmt::format("{:<10s}{:<10d}{:<10}{:<10d}{:<10s}{:<10d}\n", 
	// 	a.name, a.age, a.sex, a.unique_id, a.school_name, a.dormitory);
    out << a.name << " " << a.age << " " << a.sex << " " << a.school_name << " " << *a.dormitory << endl;
	out << a.fourteen_day ;
	return out; 
} 

std::istream& operator >> (std::istream& in, person& a) {
    place temp;
    in >> a.name >> a.age >> a.sex >> a.school_name >> temp >> a.fourteen_day;
    a.dormitory = place::FindPlaceByCoordinate(temp);
    return in;
}

std::istream& operator >> (std::istream& in, std::list<person> &a) {
    person temp;
    in >> temp;
    a.push_back(std::move(temp));
    return in;
}