#include "file.h"
#include "header.h"
#include "place.h"
#include "person.h"



bool ReadPlace(std::string filename) {
    try{
        std::string IN;
        std::ifstream FILE(filename);
        while(std::getline(FILE,IN) ){
            if(IN.empty()) continue;
            std::stringstream s(IN);
            s >> AllPlace;
        }
        FILE.close();
    }
    catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
        return 0; 
    }
    return 1;
}

bool ReadPerson(std::string filename) {
    try{
        std::string IN;
        std::ifstream FILE(filename);
        while(std::getline(FILE,IN) ){
            if(IN.empty()) continue;
            std::stringstream s(IN);
            s >> Person ;
        }
        FILE.close();
    }
    catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
        return 0; 
    }
    return 1;
}
