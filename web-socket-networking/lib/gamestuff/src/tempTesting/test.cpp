#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../../include/Foreach.h"
#include "../../include/Messages.h"
#include "../../include/when.h"



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

TEST(test, whenTestTrue)
{
    vector<Rules*> rules;
    bool cond = true;
    rules.push_back(new Globalmessage("Test when"));
    rules.push_back(new Globalmessage("Test when 2"));

    pair<bool, vector<Rules*>> whenPair{cond,rules};
    when whenRule{whenPair};
    whenRule.runRule();
    EXPECT_TRUE(true);
}

TEST(test, whenTestTrue)
{
    vector<Rules*> rules;
    bool cond = false;
    rules.push_back(new Globalmessage("Test when shouldn't run this"));
    rules.push_back(new Globalmessage("Test when 2"));

    pair<bool, vector<Rules*>> whenPair{cond,rules};
    when whenRule{whenPair};
    whenRule.runRule();
    EXPECT_TRUE(true);
}


TEST(test,ForEachTest)
{
    
    vector<Rules*> nestedRules2;
    Globalmessage* msg = new Globalmessage{"From when Rule being run"};
    nestedRules2.push_back(msg);
    vector<Rules*> nestedRules;
    Globalmessage* msg2 = new Globalmessage{"From inner ForEach loop"};
    nestedRules.push_back(msg2);
    pair<bool,vector<Rules*>> whenPair{true, nestedRules2};
    when* whentest = new when{whenPair};
    nestedRules.push_back(whentest);
    Globalmessage* msg3 = new Globalmessage{"From inner ForEach loop after when loop"};
    nestedRules.push_back(msg3);
    Foreach secondFor{nestedRules};
    vector<Rules*> rules;
    rules.push_back(&secondFor);
    Globalmessage* msg4 = new Globalmessage("From parent ForEach after nested");
    rules.push_back(msg4);
    Foreach firstFor{rules};
    
    firstFor.runRule();
    
    EXPECT_TRUE(true);
}

