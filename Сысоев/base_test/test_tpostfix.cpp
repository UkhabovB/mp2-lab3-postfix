#include "postfix.h"
#include <gtest.h>

class TPostfixTest : public ::testing::Test
{
public:
	TPostfix *pf;
	TPostfixTest() : pf(NULL) {};
    void CreatePostfix(string s)
	{
		pf = new TPostfix(s);
	}
	
	~TPostfixTest()
	{
		delete pf;
	}

};
TEST_F(TPostfixTest,can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix pf("a+b"));
}
#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);
}

