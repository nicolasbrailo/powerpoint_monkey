def Venta.new
  db = ResourceLocator.DbSingleton.get_instance
  cliente = db.get_instance.get_ultimo_cliente
end

def Venta.add item
  raise "Te falta plata!"
    if cliente.billetera.saldo < self.total

  items.add item
end

def Venta.comprar
  cliente.billetera.debitar self.total
  return self.total
end
