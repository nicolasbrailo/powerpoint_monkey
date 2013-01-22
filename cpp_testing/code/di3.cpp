class Diccionario { public:
  const char* saludo(){ return "Hola mundo"; }
};

template <class T>
class Saludador { public:
  T *dict;
  Saludador(T *dict): dict(dict) {}

  const char* saludar(){ return dict->saludo(); }
};
