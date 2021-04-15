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

bool SavePlace(std::string filename) {
    try{
        std::ofstream FILE(filename);
        for(auto &p: AllPlace)
            FILE << p;
        FILE.close();
    }
    catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
        return 0; 
    }
    return 1;
}

bool ImportPerson(std::string filename) {
    try
    {
        std::string IN;
        std::ifstream FILE(filename);
        while(std::getline(FILE,IN)) {
            if(IN.empty()) continue;
            std::stringstream s(IN);
            std::string a;size_t b; bool c;
            s >> a >> b >> c;
            Person.push_back(person(a,b,c));
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }   return 1;
    
}

bool ReadPerson(std::string filename) {
    try{
        std::string name;
        std::ifstream FILE(filename);
        while(FILE >> name){
            FILE >> Person;
        }
        FILE.close();
    }
    catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
        return 0; 
    }
    return 1;
}

bool SavePerson(std::string filename) {
    try{
        std::ofstream FILE(filename);
        for(auto &p: Person){
            FILE << p.GetName() << endl;
            FILE << p << endl;
        }
        FILE.close();
    }
    catch(const std::exception& e){ 
        std::cerr << e.what() << '\n';
        return 0; 
    }
    return 1;
}
