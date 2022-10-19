#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../include/Foreach.h"
#include "../../include/Messages.h"
#include "../../include/when.h"


class stubRule : public Rules
{
    public:
        MOCK_METHOD(void, runRule, (), (override));
};

using namespace std;
TEST(test,GlobalmessageTest)
{
    Globalmessage testMsg{"Hello World"};
    testing::internal::CaptureStdout();
    testMsg.runRule();

    string actual = testing::internal::GetCapturedStdout();
    string expected = "Message for Everyone: Hello World\n";
    
    EXPECT_EQ(actual, expected);
}

TEST(test,ForEachTest)
{
    vector<Rules*> rules;
    stubRule msg1;
    stubRule msg2;
    stubRule msg3;
    
    rules.push_back(&msg2);
    rules.push_back(&msg3);
    Foreach firstFor{rules};
    {
        testing::InSequence seq;
        EXPECT_CALL(msg1, runRule());
        EXPECT_CALL(msg2, runRule());
        EXPECT_CALL(msg3, runRule());
    }
    
    firstFor.runRule();
}