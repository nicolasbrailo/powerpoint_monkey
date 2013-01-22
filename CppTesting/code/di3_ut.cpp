class MockDict {
  public:
  MOCK_METHOD_0(saludo, const char*());
};

TEST(SaludadorTest, saludar) {
  MockDict dict;

  EXPECT_CALL(dict, saludo())
    .WillOnce(Return("ciao mondo"));

  Saludador<MockDict> s(&dict);
  s.saludar();
}
