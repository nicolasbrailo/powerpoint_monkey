#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace testing;

class False { public: bool saludar(){ return true; } };
class Mockasd { public:
	MOCK_METHOD4(recv_n, int(void*, int, int, int*));
};
TEST(Handshake, TxOK) {	SUCCEED();}
TEST(Handshake, RecvFail) {False saludador; EXPECT_FALSE(saludador.saludar());}
TEST(Handshake, SendFail) {
	Mockasd m;
	EXPECT_CALL(m, recv_n(_,_,_,_)).Times(0);
	int b; char* c;
	m.recv_n(c,0,0,&b);
	False saludador;
	EXPECT_FALSE(saludador.saludar());
}
