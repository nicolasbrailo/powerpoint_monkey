def Jeep.avanzar
 if combustible > 0 then
  combustible=combustible-1
  return self.velocidad
 else
  return 0
 end
end
