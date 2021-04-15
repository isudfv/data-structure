#include "header.h"
#include "place.h"
#include "TIME.h"
#include "person.h"
#include "infected.h"
#include "file.h"
// #include <filesystem>

int main(int argc, char* argv[]) {
	// cout << argc << endl; 
	system("chcp 65001");

	// cout << fmt::format("I'd rather be {1} than {0}.\n", "right", "happy");

	/* for( auto& p: member ){
		std::cout << p << " " ;
	}
	std::cout << std::endl;

	std::map<std::string,int> school;
	school["郭建桁"] = 1;

	cout << school["郭建桁"] << endl ;

	while(1){
		cout << RandomSchool() << endl;
	} */


	// place a(1,2) ; 
	// auto [x,y] = a.GetCoodinate() ; 

	/* std::initializer_list<place> p = {{1,2}, {1,3}, {1,4}, {1,5}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}};
	AllPlace.insert(end(AllPlace), begin(p), end(p));

	

	place a(1,1),b(1,2),c(2,1),d(2,2);

	std::vector<person> s{{"郭建桁",18,1}, {"温晓平",18,1}, {"蔡明宸",18,1}, {"韩希贤",18,0}, {"黄一婷",17,1}} ;
	std::vector<infected> f{{"gjh",18,1}, {"wxp",18,1}, {"cmc",18,1}, {"hxx",18,0}} ;


	for( auto &p: s ){
		std::cout << p << std::endl;
	} */

	// namespace fs = std::filesystem;
	// fs::path Path("../file");
	// for(auto &p: fs::directory_iterator(Path)) {
	// 	ReadPlace(p);//????????????
	// }


	std::string path("../file/GUFS.txt");
	ReadPlace(path);
	// ReadPerson("../output/gjh.txt");

	// for (auto& p : Person) {
	// 	cout << p << endl;
	// }
	// printf("========\n");

	// cout << place::CoordinatePlace.size() << endl;
	// for (auto& [x, y] : place::CoordinatePlace) {
	// 	cout << x.first << " " << x.second << " " << y->GetPlaceName() << endl;
	// }

	/* auto x = place::FindPlaceByCoordinate(4690,   1518);
	cout << "PLACE:\n" << *x << endl ; 

	auto y = place::FindPlaceByCoordinate(4516,   2452);
	cout << "PLACE:\n" << *y << endl ; 
	auto z = place::FindPlaceByCoordinate(4516,   2452);
	cout << "PLACE:\n" << *z << endl ;  */

	/* ImportPerson("../file/PERSON.txt");
	for (auto& p : Person) {
		cout << p.GetName() << endl;
		p.SetRandomSchool();
		cout << p.GetSchoolName() <<" " <<  *p.GetDormitory() << endl;
		p.SetRandomTrace();
		cout << p << endl;
	} */

	/* person s{ "郭建桁",18,1 };
	s.SetSchool("GUFS");
	s.SetDormitory(place::FindPlaceByCoordinate(4678,2364));
	s.SetRandomTrace();

	Person.push_back(std::move(s)); */

	// trace xx = trace::RandomPath(place::FindPlaceByCoordinate(4678,2364), "GUFS");
	// printf("=======\n");
	// cout << xx.GetPath()[1] << endl;
	// cout << xx.GetPath()[2] << endl;
	// cout << xx.GetPath()[3] << endl;
	// cout << xx.GetPath()[3] << endl;
	// cout << xx.GetPath()[4] << endl;
	// for(auto p: xx.GetPath()) {
	// 	cout << p;
	// }
	// cout << s << endl;
	// SavePerson("../output/gjh.txt");
	// std::ofstream FFF("../output/gjh.txt",std::ios::out);
	// if(FFF){
	// 	cout << "FALSE\n";
	// }	//???????
	// if(!FFF){
	// 	cout << "true";
	// }
	// cout << trace::RandomPath(29,"GUFS") << endl;
	// cout << trace::RandomPath(29,"GUFS") << endl;
	// cout << s.GetTrace() << endl;





	return 0;
}