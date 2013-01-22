TEST(Handshake, SendFail) {
  MockDb db; MockSock sock;

  // Expect no errors
  EXPECT_CALL(db, error("recv")).Times(0);
  EXPECT_CALL(db, error("send")).Times(1);

  // Do send and recv
  EXPECT_CALL(sock, send_n(MSG, sizeof(MSG), _, _))
    .WillOnce(DoAll(
               SetArgumentPointee<3>(0),
               Return(0)
             ));

  EXPECT_CALL(sock, recv_n(_, _, _, _))
    .Times(0);

  Handshake saludador(&db, &sock);
  EXPECT_FALSE(saludador.saludar());
}
