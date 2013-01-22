class Foobar : public ACE_Svc_Handler <ACE_SOCK_Stream, ACE_MT_SYNCH> {
  public:          
  int open(void *msg){
    assert(0 == strcmp((char*)msg, MSG_1));
    peer().send_n("Garbage", strlen("Garbage"));
    peer().close();
    return 0;
  }
};

void test_handshake_fail() {
  DbSingleton = new Singleton;
  DbSingleton->setInstance(new ExcelDB);
  DbSingleton->getInstance()->truncate_errors("recv");
  DbSingleton->getInstance()->truncate_errors("send");

  ACE_Acceptor<Foobar, ACE_SOCK_ACCEPTOR> acceptor(PORT);
  Handshake saludador;
  saludador.saludar();

  int errs = DbSingleton->getInstance()->get_errors_cnt("recv");
  assert(errs == 1);
}

int main(){
	test_handshake_fail();
	return 0;
}

