cmake_minimum_required(VERSION 3.14)

enable_testing()

# Fetch the Google Test framework
include(FetchContent)
message(STATUS "Fetching Google Test...")
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.14.0
  GIT_PROGRESS TRUE
  )
FetchContent_MakeAvailable(googletest)

# Include directories for Google Test
include_directories(${GTEST_INCLUDE_DIRS})
# Add your test executable
add_executable(test_tickets test_tickets.cc)

# Link the test executable with Google Test and the library target
target_link_libraries(test_tickets tickets_lib GTest::gtest_main GTest::gtest)

include(GoogleTest)
gtest_discover_tests(test_tickets)
