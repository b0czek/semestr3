

val composites = (n: Int) =>
  def map[A, B](f: A => B, list: List[A]):List[B] =
    list match {
      case Nil => Nil
      case h :: t => f(h) :: map(f, t)
    }
  def filter[A](f: A => Boolean, list: List[A]): List[A] =
    list match {
      case Nil => Nil
      case h :: t if f(h) => h :: filter(f, t)
      case h :: t => filter(f,t)
    }
  val isComposite = (n: Int) =>
    filter((x: Int) => (n % x == 0), List.range(2, Math.sqrt(n).ceil.toInt + 1)) != Nil

  filter((x: Int) => isComposite(x), List.range(4, n+1))


//  map(x => isComposite(x), List.range(4, n+1))
//  List.range(4, n+1).filter(x => isComposite(x))
//  for(x <- List.range(4, n + 1); if isComposite(x)) yield x;


composites(2)
composites(10)
composites(100)