#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace testing;

class Foo { public:
	MOCK_METHOD1(bar, void(char*));
};

// argN's are automagically defined
ACTION(CopyHello) { strcpy(arg0, "Hello world"); }
ACTION_P(CopyStr, str) { strcpy(arg0, str); }

. . .

TEST(Handshake, TxOK) {
	Foo foo;
	EXPECT_CALL(foo, bar(_))
		.WillOnce(WithArg<0>(CopyStr("hola mundo")))
		.WillOnce(WithArg<0>(CopyHello()));

	char buff[5];
	foo.bar(buff);
	EXPECT_STREQ(buff, "hola");
}
