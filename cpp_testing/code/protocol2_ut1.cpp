class MockDb : public Db {
  void save_error(const char*) { std::cout << "Saving error\n"; }
};

TEST_F(HandshakeTest, TxOK) {
  class Contestador_OK : public Contestador {
    public: const char* get_msg(){ return MSG_2; }
  };

  ACE_Acceptor<Contestador_OK, ACE_SOCK_ACCEPTOR> acceptor(PORT);

  MockDb db;
  Handshake saludador(&db);
  saludador.saludar();
}

TEST_F(HandshakeTest, RecvFail) {
  class Contestador_Fail: public Contestador {
    public: const char* get_msg(){ return "Garbage"; }
  };

  MockDb db;
  ACE_Acceptor<Contestador_Fail, ACE_SOCK_ACCEPTOR> acceptor(PORT);
  Handshake saludador(&db);
  saludador.saludar();
}
