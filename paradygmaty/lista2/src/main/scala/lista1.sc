// zad 1
// scala> def evenR(n:Int): Boolean ={
//  println("evenr")
//  if n==0 then true else oddR(n-1)
//}
//def oddR(n:Int): Boolean = {
//  println("evenr")
//  if n == 0 then false else evenR(n-1)
//}
//
// 4 wywolania

//zad 4
val (_::_::x::_) = List(-2,-1,0,1,2);
val (_ :: (y, _) :: _) = List((1,2), (0,1));


def zad5[A](list1: List[A], list2: List[A]): Boolean =
  (list1, list2) match {
    case (Nil, _) => true
    case (_, Nil) => false
    case (ha::ta, hb::tb) if ha != hb => false
    case (_ :: ta, _ :: tb) => zad5(ta, tb)
  }

zad5(List(1,2,3,4), List(1,2,3,4,5,6,7))
zad5(List(), List(1,2,3,4,5,6,7))
zad5(List(1,2,3,4), List());
zad5(List(1,2,3,4,1), List(1,2,3,4,5,6,7))