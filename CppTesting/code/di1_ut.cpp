class MockDict : public Diccionario {
  public:
  MOCK_METHOD_0(saludo, const char*());
};

TEST(SaludadorTest, saludar) {
  MockDict dict;

  EXPECT_CALL(dict, saludo())
    .WillOnce(Return("ciao mondo"));

  Saludador s(&dict);
  s.saludar();
}
