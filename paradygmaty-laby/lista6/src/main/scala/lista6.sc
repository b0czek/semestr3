sealed trait Expression

case class Val(value: Double) extends Expression
case class Fun(fun: (Double, Double) => Double) extends Expression
case object Sum extends Expression
case object Diff extends Expression
case object Prod extends Expression
case object Div extends Expression

def test(fun: (Double, Double) => Double) = fun(1,2)

def evaluate(list : List[Expression]): Option[Double] =
  list match {
    case Val(value) :: Nil => Some(value)
    case Val(r) :: Val(l) :: operator :: xs => {
      val v = operator match {
        case Sum => l + r
        case Diff => l - r
        case Prod => l * r
        case Div if r == 0.0 => Double.NaN
        case Div => l / r
        case Val(x) => Double.NaN
        case Fun(f) => f(r, l)
      }
      if v.isNaN then None else evaluate(Val(v) :: xs)
    }

    case _ => None
  }

evaluate( List() )
evaluate( List(Val(1.0)))
evaluate( List(Sum))
evaluate( List(Val(1.0), Sum))
evaluate( List(Val(1.0), Val(2.0)))
evaluate( List(Val(1.0), Val(2.0), Val(3.0)))

evaluate( List(Val(1.0), Val(3.5), Sum) )
evaluate( List(Val(0.0), Val(1.0), Div) )
evaluate( List(Val(1.0), Val(2.0), Sum, Val(3.0), Val(4.0), Sum))
evaluate( List(Val(1.0), Val(2.0), Sum, Val(3.0), Sum, Val(4.0), Prod))


evaluate( List(Val(10.0), Val(3.0), Fun((a,b) => a*a*b)))
evaluate( List(Val(10.0), Val(3.0), Diff))
evaluate( List(Val(10.0), Val(3.0), Fun((a,b) => b-a)))

def test (a: Double, b: Double) : Double = a * a * b
evaluate( List(Val(10.0), Val(3.0), Fun(test)))
