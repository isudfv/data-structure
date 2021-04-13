// #include "point.h"
#include "place.h"
#include "school.h"
// #include "person.h"

/* void place::insert() {
    CoordinatePlace[{x,y}] = *this; 
} */

bool place::InsertHealthy(size_t temp){
    try
    {
        visit.insert(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

bool place::InsertPatient(size_t temp){
    try
    {
        patient.insert(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

bool place::DeleteHealthy(size_t temp) {
    try
    {
        visit.erase(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }   
    return 1; 
}

bool place::DeletePatient(size_t temp) {
    try
    {
        patient.erase(temp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }   
    return 1; 
}

std::string place::GetPlaceName(){
    return PlaceName;
}

std::string place::GetSchoolName(){
    return SchoolName;
}

size_t place::GetProperty(){
    return property;
}

std::set<size_t> place::GetVisitPerson() {
    return visit;
}

std::set<size_t> place::GetDiagnosePerson() {
    return patient;
} 

bool operator ==(place a ,place b) {
    return !((a.x-b.x)*(a.y-b.y));
}

size_t place::GetHazard() {
    if(patient.size()){
        return 3;
    }
    else{
        size_t sum = 0;
        for (auto &p: AllPlace){
            double r = sqrt((p.x-x))+sqrt((p.y-y));
            if(r <= 40000){
                sum += p.patient.size();
            }
        }
        if(sum) return 2;
        return 1;
    }
}

size_t place::FindPlaceByCoordinate(std::pair<size_t ,size_t > s){
	return find(begin(AllPlace), end(AllPlace), *place::CoordinatePlace[s]) - begin(AllPlace);
}

size_t place::FindPlaceByCoordinate(size_t  x, size_t  y) {
    return FindPlaceByCoordinate({x,y});
} 

std::istream& operator >> (std::istream& in, place& a) {
    in >> a.SchoolName >> a.PlaceName >> a.property >> a.x >> a.y;
    return in;
}

std::istream& operator >> (std::istream& in, std::vector<place>& a) {
    place temp;
    in >> temp;
    a.push_back(std::move(temp));
    // fmt::print("{}  {}  {}\n", a.back().SchoolName, a.back().property, a.size() ) ;
    schools[SchoolName[a.back().SchoolName]].v[a.back().property]->push_back(a.size());
    // fmt::print("{}  {}\n", schools[3].v[a.back().property]->size(), SchoolName[a.back().SchoolName]);
    return in;
}

std::ostream& operator << (std::ostream& out, place& a) {
    // out << fmt::format("{:<50s}{:<10d}{:<10d}", a.PlaceName, a.x, a.y);
    out << std::left << std::setw(50) << a.PlaceName << std::setw(10) << a.x << a.y ;
    return out;
}
