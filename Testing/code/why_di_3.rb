def test_compra
  # Scaffolding
  dagoberto = Cliente.new
  dagoberto.billetera = Billetera.new
  dagoberto.billetera.saldo = 2

  singleton = Singleton.new
  singleton.instance = DB_Factory.new
  ResourceLocator.DbSingleton = singleton
  db = ResourceLocator.DbSingleton.get_instance
  db.set_cliente = dagoberto

  item = Empanada.new
  item.precio = 2

  # Test real - Dependencias ocultas
  venta = Venta.new
  venta.add item
  Expect{ venta.comprar == true }
  Expect{ venta.total == 2 }
end
