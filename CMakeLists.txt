cmake_minimum_required(VERSION 3.5)

project(CRad)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(CherenkovRadiation CherenkovRadiation.cpp ${sources} ${headers})

target_link_libraries(CherenkovRadiation ${Geant4_LIBRARIES})

