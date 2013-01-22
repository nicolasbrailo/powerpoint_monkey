class HandshakeTest : public Test { public:
  // Global a todo el test suite
  static void TearDownTestCase(){}
  static void SetUpTestCase(){ DbSingleton.setInstance(&ExcelDB); }

  // Por cada test case
  void TearDown(){}
  void SetUp(){
    db.truncate_errors("recv");
    db.truncate_errors("send");
  }

  // Puedo instanciar variables "globales" a mis tests
  Handshake saludador; Singleton DbSingleton; ExcelDB db;
};

class Contestador : public ACE_Svc_Handler <ACE_SOCK_Stream, ACE_MT_SYNCH> {
  public:
  virtual const char* get_msg() = 0;
  int open(void *msg){
    EXPECT_STREQ((char*)msg, MSG_1);
    peer().send_n(get_msg(), strlen(get_msg()));
    peer().close();
    return 0;
  }
};
