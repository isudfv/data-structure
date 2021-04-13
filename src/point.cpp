#include "point.h"

bool point::SetPlace(size_t temp){
    arrival = temp;
    return arrival == temp;
}

bool point::SetTime(size_t temp){
    arrive = temp;
    return arrive == temp;
}

size_t point::GetPlace(){
    return arrival;
}

size_t point::GetArriveTime(){
    return arrive;
}

size_t point::GetLeaveTime(){
    return leave;
}

bool point::Collision(point temp){
    return (leave-temp.arrive)*(arrive-temp.leave) < 0; 
}

bool operator==(const point& a, const point& b) {
    return b.arrival == a.arrival && b.arrive == a.arrive && b.leave == a.leave;
}

bool operator == (const point& a, const place& b) {
    return AllPlace[a.arrival] == b;
}

std::ostream& operator << (std::ostream &out, const point& a) {
	// out << fmt::format("{:<10d}{:<10d}{:<10d}", a.arrival, a.arrive, a.leave);
    out << std::left << std::setw(10) << a.arrival << std::setw(10) <<  a.arrive << std::setw(10  ) <<  a.leave ;
	return out;
}

std::istream& operator >> (std::istream &in, const point& a) {
    in >> a.arrival >> a.arrive >> a.leave;
    return in;
}

