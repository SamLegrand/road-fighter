cmake_minimum_required(VERSION 3.12)
project(road_fighter)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

find_package(SFML 2 COMPONENTS system window graphics)

set(SRC main.cpp)

include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(road_fighter ${SRC})

target_link_libraries(road_fighter ${SFML_LIBRARIES})

install(TARGETS road_fighter DESTINATION ${PROJECT_SOURCE_DIR}/bin)
