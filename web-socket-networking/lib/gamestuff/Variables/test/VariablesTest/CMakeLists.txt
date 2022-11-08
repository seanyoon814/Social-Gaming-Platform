add_executable(VariablesTest VariablesTest.cpp)
target_link_libraries(VariablesTest PUBLIC Variables GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(VariablesTest)
