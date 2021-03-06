class MockDb : public Db {
  MOCK_METHOD1(save_error, void(const char*));
};

TEST_F(HandshakeTest, TxOK) {
  class Contestador_OK : public Contestador {
    public: const char* get_msg(){ return MSG_2; }
  };

  ACE_Acceptor<Contestador_OK, ACE_SOCK_ACCEPTOR> acceptor(PORT);

  MockDb db;
  EXPECT_CALL(db, error("recv")).Times(0);
  Handshake saludador(&db);
  saludador.saludar();
}

TEST_F(HandshakeTest, RecvFail) {
  class Contestador_Fail: public Contestador {
    public: const char* get_msg(){ return "Garbage"; }
  };

  MockDb db;
  EXPECT_CALL(db, error("recv")).WillOnce(Return());
  ACE_Acceptor<Contestador_Fail, ACE_SOCK_ACCEPTOR> acceptor(PORT);
  Handshake saludador(&db);
  saludador.saludar();
}
