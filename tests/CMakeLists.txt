set(RC_ENABLE_GTEST ON)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

FetchContent_Declare(
  rapidcheck
  GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(rapidcheck)

add_library(rc INTERFACE IMPORTED)
target_link_libraries(rc INTERFACE rapidcheck)
target_link_libraries(rapidcheck_gtest INTERFACE rapidcheck)

# set_property(TARGET rc PROPERTY CXX_STANDARD 11)

file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(test_ccbb ${TEST_SOURCES} "autoSimTests.cpp")

include_directories (${CCBB_SOURCE_DIR}/src)
target_include_directories(test_ccbb INTERFACE rapidcheck) 

target_link_libraries(test_ccbb
  PRIVATE
  ccbb
  GTest::GTest
  rapidcheck
  rapidcheck_gtest
)

add_test(NAME CcbbTest COMMAND test_ccbb)
