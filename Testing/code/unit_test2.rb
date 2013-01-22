def test_destruccion
  avion = Avion.new
  submarino = Submarino.new

  {avion, submarino}.
    each.set_combustible 0

  Expect{ avion.avanzar == 0 }
  Expect{ avion.destruido == true }
  Expect{ submarino.avanzar == 0 }
  Expect{ submarino.destruido == true }
end
