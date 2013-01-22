def test_compra
  item = Empanada.new
  item.precio = 2
  cuenta = Cuenta.new
  cuenta.saldo = 2

  # Test real - la dependencia es clara
  venta = Venta.new cuenta
  venta.add item
  Expect{ venta.comprar == true }
  Expect{ venta.total == 2 }
end
