def Vehiculo.avanzar
  if combustible > 0 then
    combustible=combustible-1
    return self.velocidad
  else
    destruido = true
    return 0
  end
end
def Avion.velocidad() return 20 end
def Submarino.velocidad() return 10 end
