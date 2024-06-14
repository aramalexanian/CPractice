cmake_minimum_required(VERSION 3.10)

project(API_Calls C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${API_Calls_SOURCE_DIR}/bin/)

add_executable(api_call.exe src/api_call.c)
target_link_libraries(api_call.exe PUBLIC curl)

add_executable(unit_test.exe src/unit_test/unit_test.c)
target_link_libraries(unit_test.exe PUBLIC curl)
