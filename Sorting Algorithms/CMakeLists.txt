cmake_minimum_required(VERSION 3.24.0)
project(SortingAlgorithms
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}
    main.cpp
    sorting_algorithms.cpp
    sorting_algorithms.hpp
)

add_executable(${PROJECT_NAME}_test
    tests.cpp
    sorting_algorithms.cpp
    sorting_algorithms.hpp
)

target_link_libraries(${PROJECT_NAME}_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_test)

source_group("Tests" FILES tests.cpp)
source_group("Implementation" FILES main.cpp sorting_algorithms.cpp sorting_algorithms.hpp)

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
    target_compile_options(${PROJECT_NAME}_test PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic)
endif()

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    target_compile_options(${PROJECT_NAME} PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
    target_compile_options(${PROJECT_NAME}_test PRIVATE -Wweak-vtables -Wexit-time-destructors -Wglobal-constructors -Wmissing-noreturn )
endif()

if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /w44265 /w44061 /w44062 )
    target_compile_options(${PROJECT_NAME}_test PRIVATE /W4 /w44265 /w44061 /w44062 )
endif()
