cmake_minimum_required(VERSION 4.0.1)
project(GeoLocation-Calculator CXX)

# Google test requires at least C++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Source Files === #
set(SRC_FILES_WITHOUT_MAIN
)


add_executable(${PROJECT_NAME} ${SRC_FILES_WITHOUT_MAIN} src/main.cpp)

# === Helper Files === #
set(HELPER_FILES
    helper/io.h
    helper/io.cpp
)

include_directories(helper)
target_sources(${PROJECT_NAME} PRIVATE ${HELPER_FILES})

# === Google Test === #
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

enable_testing()

# === Test Executables === #
### WILL NEED CHANGES FOR THIS PROJECT
set(GEO_LOCATION_GTESTS ${PROJECT_NAME}_gtests)
set(GEO_LOCATION_CALCULATOR_GTEST_FILES
    gtest/gtestmain.cpp
    ${SRC_FILES_WITHOUT_MAIN}
    ${HELPER_FILES}
)

add_executable(${GEO_LOCATION_GTESTS} ${GEO_LOCATION_CALCULATOR_GTEST_FILES})
target_link_libraries(${GEO_LOCATION_GTESTS} gtest gtest_main)
target_include_directories(${GEO_LOCATION_GTESTS} PRIVATE ${CMAKE_SOURCE_DIR}/src)
add_test(NAME geoloc_tests COMMAND ${GEO_LOCATION_GTESTS})

