cmake_minimum_required(VERSION 3.10)

include_directories(/home/joshua/googletest/googletest/include)

# Google Test settings
set(BUILD_GMOCK OFF CACHE BOOL "Builds the googlemock subproject" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Enable installation of googletest." FORCE)

# Include directories for Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test executable
add_executable(test_tickets test_tickets.c)

# Link the test executable with Google Test and the library target
target_link_libraries(test_tickets GTest::Main pthread)

# Add test
# If you don't have a separate test file, you can directly write tests in your main.c file
add_test(
    NAME test_tickets
    COMMAND test_tickets
)