def test_division
  Expect{1 == 2/2}
  Expect{Err == 1/0}
  Expect{-5 == -5/1}
  Expect{-5 == 5/-1}
  Expect{5 == -5/-1}
  # Etc ...
end
