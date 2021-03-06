class Handshake {
  Db *db; ACE_SOCK_Stream *sock;
  Handshake(Db *db, ACE_SOCK_Stream *sock) : db(db), sock(sock) {}

  bool saludar() {
    Command cmd; uint32_t bt; ACE_Time_Value timeout(20);

    ssize_t res = sock->send_n("Hello",
                        sizeof("Hello"), &timeout, &bytes);

    if (res <= 0 || bytes < msg.size()) {
      db->save_error("send");
      return false;
    }
        
    res = sock->recv_n(cmd.buffer(),
                 cmd.sizeof_buffer(), &timeout, &bytes);

    if (res <= 0 || bytes < msg.size()) {
      db->save_error("recv");
      return false;
    }

    return true;
  }
};
