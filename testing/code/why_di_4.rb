def Venta.new cuenta
  self.cuenta = cuenta
end

def Venta.add item
  raise "Te falta plata!"
    if cuenta.saldo < self.total

  items.add item
end

def Venta.comprar
  cuenta.debitar self.total
  return self.total
end
