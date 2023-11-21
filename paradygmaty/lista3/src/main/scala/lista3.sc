//2
def curry3[A,B,C,D](f: (A,B,C)=>D)(a: A)(b: B)(c: C) =
  f.apply(a,b,c)
def curry3[A,B,C,D] = (f: (A,B,C)=>D) => (a: A) => (b: B) => (c:C) => f.apply(a,b,c)

def uncurry3[A,B,C,D](f: A=>B=>C=>D) = Function.uncurried(f)


//3
def sumProd(xs: List[Int]): (Int, Int) =
  (xs foldLeft (0,1)) ((t:(Int,Int), x:Int) => (t._1+x, t._2*x))
