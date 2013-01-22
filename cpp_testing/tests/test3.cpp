#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace testing;

class Foo { public:
	MOCK_METHOD2(bar, bool(int, int*));
	MOCK_METHOD0(baz, int());
};

TEST(FooBar, Baz) {
	Foo foo;
	EXPECT_CALL(foo, baz()).Times(2)
		.WillOnce(Return(1));

	EXPECT_EQ(1, foo.baz());
	EXPECT_EQ(1, foo.baz());
}

TEST(Handshake, TxOK) {
	Foo foo;
	EXPECT_CALL(foo, bar(_, _)).
		WillOnce(DoAll(
					SetArgumentPointee<1>(5),
					Return(true)
					));

	int baz;
	EXPECT_TRUE(foo.bar(5, &baz));
	EXPECT_EQ(5, baz);
}
