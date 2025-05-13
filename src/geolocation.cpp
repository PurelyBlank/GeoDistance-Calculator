#include "constants.h"
#include "geolocation.h"
#include <cmath>
#include <limits>

std::pair<double, double> getLatitudeLongitude(std::string_view location)
{
    std::string latitude{ location.substr(0, location.find(' ')).substr(0, '/') };
    std::string longitude{ location.substr(latitude.size() + 1).substr(0, '/') };
    char latDir{ latitude[latitude.size() - 1] };
    char lonDir{ longitude[longitude.size() - 1] };

    double dlat{ std::stod(latitude) };
    double dlon{ std::stod(longitude) };
    if (latDir == 'S')
        dlat *= -1;
    if (lonDir == 'E')
        dlon *= -1;
    return std::make_pair(dlat, dlon);
}

/*
 * haversine formula, assumes latitude are both same direction
 * and longitude are both same direction
 * modify arguments otherwise to suffice
 *
 * Assume North and West are default directions
 * If South, convert latitude to negative
 * If East, convert longitude to negative
 */
double calcGreatCircleDist( double latitudeOne, double longitudeOne,
                            double latitudeTwo, double longitudeTwo)
{
    double lat1Radians{ M_PI * latitudeOne / 180 };
    double long1Radians{ M_PI * longitudeOne / 180 };
    double lat2Radians{ M_PI * latitudeTwo / 180 };
    double long2Radians{ M_PI * longitudeTwo / 180 };
    
    double dlat{ lat2Radians - lat1Radians };
    double dlong{ long2Radians - long1Radians };
    double a{ std::pow(std::sin(dlat / 2), 2) + 
              std::cos(lat1Radians) * 
              std::cos(lat2Radians) * 
              std::pow(std::sin(dlong / 2), 2) };
    double c{ 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a)) };    
    return constants::EARTH_RADIUS_MILES * c;
}

/*
 * "start" and all locations is of this format "<latitude/direction><space><longitude/direction>"
 */
std::pair<std::string, double> getClosestLocation(std::string_view start, 
                                                  std::unordered_map<std::string, std::string>& locations)
{
    const std::pair<double, double>& latLon{ getLatitudeLongitude(start) };
    double startLat{ latLon.first };
    double startLon{ latLon.second };
    
    std::pair<std::string, double> closest{};
    double distance{ std::numeric_limits<double>::infinity() };
    for (const auto& locationPair: locations) {
        const std::pair<double, double>& location{ getLatitudeLongitude(locationPair.first) };
        double newDistance{ calcGreatCircleDist(startLat, startLon, location.first, location.second) };
        if (newDistance < distance) {
            closest = std::make_pair(locationPair.first, newDistance);
            distance = newDistance;
        }
    }

    return closest;
}

/*
 * "start" and all locations is of this format "<latitude/direction><space><longitude/direction>"
 */
