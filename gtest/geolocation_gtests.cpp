#include <gtest/gtest.h>
#include "geolocation.h"

namespace {
    constexpr double EPSILON{ 0.0001 };

    TEST(CalcGreatCircleDist, SameLocation)
    {
        EXPECT_NEAR(calcGreatCircleDist(0.0, 0.0, 0.0, 0.0), 0.0, EPSILON);
        EXPECT_NEAR(calcGreatCircleDist(20.44, 30.61, 20.44, 30.61), 0.0, EPSILON);
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
}
