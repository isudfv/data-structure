#include "point.h"

bool point::SetPlace(place *temp){
    arrival = temp;
    return arrival == temp;
}

bool point::SetTime(std::pair<size_t,size_t> temp){
    arrive = temp.first;
    leave = temp.second;
    return temp == std::make_pair(arrive,leave) ;
}

bool point::SetArriveTime(size_t a) {
    arrive = a;
    return arrive==a;
}

bool point::SetLeaveTime(size_t a) {
    leave = a;
    return leave==a;
}

place* point::GetPlace(){
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
    return a.arrival == b;
}

std::ostream& operator << (std::ostream &out, const point& a) {
	// out << fmt::format("{:<10d}{:<10d}{:<10d}", a.arrival, a.arrive, a.leave);
    out << *a.arrival << " " << a.arrive << " " <<  a.leave ;
	return out;
}

std::istream& operator >> (std::istream &in, point& a) {
    place temp;
    in >> temp >> a.arrive >> a.leave;
    a.arrival = place::FindPlaceByCoordinate(temp);
    return in;
}

