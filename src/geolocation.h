#ifndef GEOLOCATION_H
#define GEOLOCATION_H

#include <string>
#include <string_view>
#include <vector>

double calcGreatCircleDist(double latitudeOne, double longitudeOne,
                           double latitudeTwo, double longitudeTwo);
const std::string& getClosestLocation(std::string_view start, 
                                      const std::vector<std::string>& locations);
const std::string& getFarthestLocation(std::string_view start, 
                                      const std::vector<std::string>& locations);

#endif
