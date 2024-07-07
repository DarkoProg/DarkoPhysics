cmake_minimum_required(VERSION 3.29)
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED True)

project(PhysicsEngine VERSION 0.1)

# set(SOURCES "src/*.cpp")
file(GLOB SOURCES "src/*.cpp")

add_executable(PhysicsEngine ${SOURCES})
target_include_directories(PhysicsEngine PRIVATE ${PROJECT_SOURCE_DIR}/include)


#compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
