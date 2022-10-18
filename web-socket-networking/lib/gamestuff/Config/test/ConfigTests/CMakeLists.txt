add_executable(ConfigTest ConfigTest.cpp)
target_link_libraries(ConfigTest PUBLIC Config GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ConfigTest)
