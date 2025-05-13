#include <iostream>
#include <string_view>
#include <unordered_map>

#include "io.h"
#include "geolocation.h"


std::pair<std::string, std::string> parseDestination(std::string_view destination) 
{
    size_t index{ destination.find(' ') + 1 };
    std::string location{ destination.substr(0, destination.find(' ', index)) };
    std::string name{ destination.substr(location.size() + 1) };
    return std::make_pair(location, name);
}


void run()
{
    std::cout << "Enter starting location: ";
    std::string start{ getUserLineInput() };
    
    std::cout << "Enter number of destinations: ";
    int numDestinations{ getUserNum() };
    
    std::unordered_map<std::string, std::string> destinations;
    for (int i{1}; i <= numDestinations; ++i) {
        std::cout << "Enter destination #" << i << ": "; 
        std::pair<std::string, std::string> parsedDest{ parseDestination(getUserLineInput()) };
 
        destinations.insert({parsedDest.first, parsedDest.second});    
    }
   
    std::cout << "\n-----------------------------------------------------------------------\n\n"; 

    std::cout << "Start Location: " << start << '\n';;
    std::cout << "Closest Location: ";
    std::pair<std::string, double> closest{ getClosestLocation(start, destinations) };
    std::cout << closest.first << " (" << destinations.find(closest.first)->second << ") (" << closest.second << ")\n";

    std::cout << "Farthest Location: ";
    std::pair<std::string, double> farthest{ getFarthestLocation(start, destinations) };
    std::cout << farthest.first << " (" << destinations.find(farthest.first)->second << ") (" << farthest.second << ")\n";
}

int main()
{
    run();    
    return 0;
}
