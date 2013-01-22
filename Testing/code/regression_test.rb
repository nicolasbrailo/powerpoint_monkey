def test_destruccion
  avion = Avion.new
  submarino = Submarino.new
  jeep = Jeep.new

  {avion, submarino, jeep}.
    each.set_combustible 0

  Expect{ avion.avanzar == 0 }
  Expect{ avion.destruido == true }
  Expect{ submarino.avanzar == 0 }
  Expect{ submarino.destruido == true }
  Expect{ jeep.avanzar == 0 }
  Expect{ jeep.destruido == false }
end
