add_executable(ListOpsTest ListOpsTest.cpp)
target_link_libraries(ListOpsTest PUBLIC ListOps GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ListOpsTest)