def test_compra
  item = MockItem.new
  cuenta = MockCuenta.new
  item.expect_call("precio").returns( 2 )
  cuenta.expect_call("saldo").returns( 2 )
  cuenta.expect_call("debitar", 2).returns( true )

  venta = Venta.new cuenta
  venta.add item
  Expect{ venta.comprar == true }
  Expect{ venta.total == 2 }
end
