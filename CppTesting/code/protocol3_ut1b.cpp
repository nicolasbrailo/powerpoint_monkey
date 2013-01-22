TEST(HandshakeTest, TxOK) {
  MockDb db; MockSock sock;

  // Expect no errors
  EXPECT_CALL(db, error("recv")).Times(0);
  EXPECT_CALL(db, error("send")).Times(0);

  // Do send and recv
  EXPECT_CALL(sock, send_n(MSG, sizeof(MSG), _, _))
    .WillOnce(DoAll(
               SetArgumentPointee<3>(sizeof(MSG)),
               Return(1)
             ));

  EXPECT_CALL(sock, recv_n(_, _, _, _))
    .WillOnce(DoAll(
               SetArgumentPointee<3>(sizeof(MSG2)),
               WithArgs<0, 1>(CopyCmd(MSG2)),
               Return(1)
             ));

  Handshake saludador(&db, &sock);
  EXPECT_TRUE(saludador.saludar());
}
