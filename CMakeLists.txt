cmake_minimum_required(VERSION 3.12)
project(road_fighter)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

find_package(SFML 2 COMPONENTS system window graphics)

set(SRC src/road_fighter/main.cpp src/road_fighter/Entity.cpp src/road_fighter/Entity.h src/road_fighter/PlayerCar.cpp src/road_fighter/PlayerCar.h src/road_fighter/RacingCar.cpp src/road_fighter/RacingCar.h src/road_fighter/PassableCar.cpp src/road_fighter/PassableCar.h src/road_fighter/World.cpp src/road_fighter/World.h src/road_fighter/Bullet.cpp src/road_fighter/Bullet.h src/road_fighter/Random.cpp src/road_fighter/Random.h src/road_fighter/Transformation.cpp src/road_fighter/Transformation.h src/road_fighter/Game.cpp src/road_fighter/Game.h src/road_fighter/Observer.cpp src/road_fighter/Observer.h src/road_fighter/Score.cpp src/road_fighter/Score.h)

include_directories(${SFML_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(road_fighter ${SRC})

target_link_libraries(road_fighter ${SFML_LIBRARIES})

install(TARGETS road_fighter DESTINATION bin)
