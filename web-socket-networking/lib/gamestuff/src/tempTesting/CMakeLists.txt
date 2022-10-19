add_subdirectory(gtest)
enable_testing()

add_executable(fewRuleTests
    test.cpp)

    target_link_libraries(fewRuleTests
    gmock gtest gtest_main
    vineshTest
  )