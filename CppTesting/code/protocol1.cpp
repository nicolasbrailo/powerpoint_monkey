class Handshake {
  bool saludar() {
    Command cmd; ACE_SOCK_Stream sock;
    uint32_t bt; ACE_Time_Value timeout(20);

    ssize_t res = sock.send_n("Hello",
                        sizeof("Hello"), &timeout, &bytes);

    if (res <= 0 || bytes < msg.size())
      DbSingleton->getInstance()->save_error("send");
        
    res = sock.recv_n(cmd.buffer(),
                 cmd.sizeof_buffer(), &timeout, &bytes);

    if (res <= 0 || bytes < msg.size()) 
      DbSingleton->getInstance()->save_princess("recv");

    return true;
  }
};
