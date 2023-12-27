cmake_minimum_required(VERSION 3.10)
project(pubsub)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Libraries
add_library(pubsubbrokerlib src/pubsubbroker.cpp)
target_include_directories(pubsubbrokerlib PUBLIC include)
target_link_libraries(pubsubbrokerlib pthread)

add_library(publisherlib src/publisher.cpp)
target_include_directories(publisherlib PUBLIC include)
target_link_libraries(publisherlib pubsubbrokerlib)

add_library(subscriberlib src/subscriber.cpp)
target_include_directories(subscriberlib PUBLIC include)
target_link_libraries(subscriberlib pubsubbrokerlib)

# Main executable
add_executable(pubsub src/main.cpp)
target_link_libraries(pubsub pubsubbrokerlib  publisherlib subscriberlib)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(testpubsub tests/test.cpp tests/test1.cpp)
target_link_libraries(testpubsub GTest::gtest_main pubsubbrokerlib publisherlib subscriberlib)
include(GoogleTest)
gtest_discover_tests(testpubsub)
