#include "constants.h"
#include "geolocation.h"
#include <cmath>

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
