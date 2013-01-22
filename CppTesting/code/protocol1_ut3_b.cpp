TEST_F(HandshakeTest, TxOK) {
  class Contestador_OK : public Contestador {
    public: const char* get_msg(){ return MSG_2; }
  };

  ACE_Acceptor<Contestador_OK, ACE_SOCK_ACCEPTOR> acceptor(PORT);
  saludador.saludar();
  EXPECT_EQ(0, db.get_errors_cnt("recv"));
}

TEST_F(HandshakeTest, RecvFail) {
  class Contestador_Fail: public Contestador {
    public: const char* get_msg(){ return "Garbage"; }
  };

  ACE_Acceptor<Contestador_Fail, ACE_SOCK_ACCEPTOR> acceptor(PORT);
  saludador.saludar();
  EXPECT_EQ(1, db.get_errors_cnt("recv"));
}
