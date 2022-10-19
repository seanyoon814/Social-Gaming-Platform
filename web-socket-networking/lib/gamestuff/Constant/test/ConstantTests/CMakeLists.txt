add_executable(ConstantTest ConstantTest.cpp)
target_link_libraries(ConstantTest PUBLIC Constant GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ConstantTest)
