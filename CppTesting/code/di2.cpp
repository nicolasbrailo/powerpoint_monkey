// Codigo externo
class Diccionario { public:
  const char* saludo(){ return "Hola mundo"; }
};

class DictProxy { public:
	virtual const char* saludo() {
		Diccionario d;
		return d.saludo();
	}
};

class Saludador { public:
  DictProxy *dict;
  Saludador(DictProxy *dict): dict(dict) {}

  const char* saludar(){ return dict->saludo(); }
};
