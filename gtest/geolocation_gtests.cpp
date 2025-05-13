#include <gtest/gtest.h>
#include <cmath>
#include <string_view>
#include <string>
#include <unordered_map>
#include "geolocation.h"

namespace {
    constexpr double EPSILON{ 0.0001 };

    TEST(CalcGreatCircleDist, SameLocation)
    {
        EXPECT_NEAR(calcGreatCircleDist(0.0, 0.0, 0.0, 0.0), 0.0, EPSILON);
        EXPECT_NEAR(calcGreatCircleDist(20.44, 30.61, 20.44, 30.61), 0.0, EPSILON);
    }    

    TEST(GetLatitudeLongitude, Locations)
    {
        EXPECT_EQ(getLatitudeLongitude("20.8987/N 156.4305/W"), std::make_pair(20.8987, 156.4305));
        EXPECT_EQ(getLatitudeLongitude("47.4647/N 8.5492/E"), std::make_pair(47.4647, -8.5492));
        EXPECT_EQ(getLatitudeLongitude("23.4356/S 46.4731/W"), std::make_pair(-23.4356, 46.4731));
    }

    TEST(CalcGreatCircleDist, DiffLocation)
    {
        // Used: "https://www.vcalc.com/wiki/great-circle-distance" for verification

        // N W | N W : LAX -> Kahului Airport
        EXPECT_NEAR(calcGreatCircleDist(33.9425, 118.408, 20.8987, 156.43), 2483.3493, EPSILON);

        // N W | S W : LAX -> Sao Paolo-Guarulhos International Airport
        EXPECT_NEAR(calcGreatCircleDist(33.9425, 118.408, -23.4356, 46.4731), 6164.8965, EPSILON);

        // N W | N E : LAX -> Middle of Atlantic Ocean
        EXPECT_NEAR(calcGreatCircleDist(33.9425, 118.408, 23.4356, -46.4731), 8352.1297, EPSILON);

        // N W | S E : LAX -> Middle of Australia
        EXPECT_NEAR(calcGreatCircleDist(33.9425, 118.408, -25.2744, -133.7751), 8148.4695, EPSILON);

        // S E | N W : Sydney Airport -> John F. Kennedy International Airport
        EXPECT_NEAR(calcGreatCircleDist(-33.9500, -151.1817, 40.6446, 73.7797), 9953.0769, EPSILON);

        // S W | S W : Arturo Merino Benítez International Airport to Sao Paolo-Guarulhos International Airport
        EXPECT_NEAR(calcGreatCircleDist(-33.3898, 70.7944, -23.4356, 46.4731), 1625.1779, EPSILON);
    }

    TEST(GetClosestLocation, Closest)
    {
        constexpr std::string_view START{ "33.9425/N 118.4081/W" };
        std::unordered_map<std::string, std::string> locations = {
            {"20.8987/N 156.4305/W", "Kahului Airport"},
            {"47.4647/N 8.5492/E", "Zurich Airport"},
            {"23.4356/S 46.4731/W", "Sao Paolo-Guarulhos International Airport"}
        };

        std::pair<std::string, double>closest{ getClosestLocation(START, locations) };
        EXPECT_EQ("20.8987/N 156.4305/W", closest.first);
        EXPECT_NEAR(2483.3, closest.second, 0.1);
    }
}
