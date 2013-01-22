class Diccionario { public:
  const char* saludo(){ return "Hola mundo"; }
};

class Saludador { public:
  Diccionario *dict;
  Saludador(Diccionario *dict): dict(dict) {}

  const char* saludar(){ return dict->saludo(); }
};
