item.expect_call("precio").returns( 2 )
cuenta.expect_call("saldo").returns( 2 )
cuenta.expect_call("debitar", 2).returns( true )
