// Como el comportamiento se define por test
// estos mocks van a ser siempre iguales.
class MockSock : public ACE_SOCK_Stream {
  public:
  MOCK_METHOD4(send_n, ssize_t(void*, int, int, int*));
  MOCK_METHOD4(recv_n, ssize_t(void*, int, int, int*));
};

class MockDb : public Db {
  public:
  MOCK_METHOD1(save_error, void(const char*));
};

// Digamos que estos son los mensajes
#define CMD1 "Hello"
#define CMD2 "Bye"

// Y que esto hace magia
ACTION_P(CopyCmd, cmd){ strcpy(arg0, cmd); }
