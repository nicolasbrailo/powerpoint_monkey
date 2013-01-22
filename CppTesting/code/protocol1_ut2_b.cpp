class Contestador : public ACE_Svc_Handler <ACE_SOCK_Stream, ACE_MT_SYNCH> {
  public:          
  int open(void *msg){
    EXPECT_STREQ((char*)msg, MSG_1);
    peer().send_n("Garbage", strlen("Garbage"));
    peer().close();
    return 0;
  }
};

TEST(HandshakeTest, RecvFail) {
  DbSingleton = new Singleton;
  DbSingleton->setInstance(new ExcelDB);

  ACE_Acceptor<Foobar, ACE_SOCK_ACCEPTOR> acceptor(PORT);
  Handshake saludador;
  saludador.saludar();

  int errs = DbSingleton->getInstance()->get_errors_cnt("recv");
  EXPECT_EQ(1, errs);
}
