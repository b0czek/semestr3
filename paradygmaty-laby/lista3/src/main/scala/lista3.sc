val composites = (n: Int) =>
  val isComposite = (n: Int) =>
    (for(x <- List.range(2, Math.sqrt(n).ceil.toInt + 1); if n % x == 0) yield x) != Nil

  for(x <- List.range(4, n + 1); if isComposite(x)) yield x;


composites(2)
composites(10)
composites(100)