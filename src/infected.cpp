#include "infected.h"

bool infected::InsertIntoPlace(place* temp) {
    try
    {
        temp->InsertPatient(unique_id);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

bool infected::DeleteFromPlace(place* temp) {
    try
    {
        temp->DeletePatient(unique_id);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

bool infected::GetNoSymptom(){
    return NoSymptom;
}

bool HealthyToInfected(const person& s) {
    try
    {
        auto it = find( begin(Person), end(Person), s );
        for( auto &p: it->GetWholeTrace().GetPath() ){
            it -> DeleteFromPlace(p.GetPlace());
        }

        Infected.push_back(std::move(*it));
        Person.erase(it);
        auto it2 = end(Infected); 

        for( auto &p: it2->GetWholeTrace().GetPath() ){
            it2 -> InsertIntoPlace(p.GetPlace());
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;  
    }
    return 1; 
}

bool HealthyToInfected(const std::string& s) {
    if( count(begin(Person), end(Person), s) > 1 ){
        std::cerr << "Find mutiple matches\n";
        return 0;
    }
        
    return HealthyToInfected(*find(begin(Person), end(Person), s));
}

