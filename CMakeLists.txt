cmake_minimum_required(VERSION 3.12)
project(road_fighter)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

find_package(SFML 2 COMPONENTS system window graphics)

set(SRC src/main.cpp src/Entity.cpp src/Entity.h src/PlayerCar.cpp src/PlayerCar.h src/RacingCar.cpp src/RacingCar.h src/PassableCar.cpp src/PassableCar.h src/World.cpp src/World.h src/Bullet.cpp src/Bullet.h)

include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(road_fighter ${SRC})

target_link_libraries(road_fighter ${SFML_LIBRARIES})

install(TARGETS road_fighter DESTINATION bin)
