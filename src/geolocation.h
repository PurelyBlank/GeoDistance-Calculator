#ifndef GEOLOCATION_H
#define GEOLOCATION_H

#include <string>
#include <string_view>
#include <unordered_map>

std::pair<double, double> getLatitudeLongitude(std::string_view location);
double calcGreatCircleDist(double latitudeOne, double longitudeOne,
                           double latitudeTwo, double longitudeTwo);
std::pair<std::string, double> getClosestLocation(std::string_view start, 
                                                        std::unordered_map<std::string, std::string>& locations);
std::pair<std::string, double> getFarthestLocation(std::string_view start, 
                                                        std::unordered_map<std::string, std::string>& locations);

#endif
