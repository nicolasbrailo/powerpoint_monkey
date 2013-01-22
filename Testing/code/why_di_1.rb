def test_compra
  item = Empanada.new
  item.precio = 2
  venta = Venta.new
  venta.add item
  Expect{ venta.comprar == true }
  Expect{ venta.total == 2 }
end
