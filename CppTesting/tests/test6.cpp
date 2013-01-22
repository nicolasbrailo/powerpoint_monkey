#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace testing;

class Diccionario { public:
	const char* saludo() {
		return "Hola mundo";
	}
};

class Saludador { public:
	Diccionario *dict;
	Saludador(Diccionario *dict): dict(dict) {}
	const char* saludar(){ return dict->saludo(); }
};

class MockDict : public Diccionario {
	public:
	MOCK_METHOD0(saludo, const char*());
};

TEST(SaludadorTest, saludar) {
	MockDict dict;
	Saludador s(&dict);
	s.saludar();
}
