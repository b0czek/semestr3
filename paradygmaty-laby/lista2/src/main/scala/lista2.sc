import scala.annotation.tailrec

def cutOut[A](a: Integer)(b: Integer)(list: List[A]): List[A] = (list,a,b) match {
  case (Nil, _, _) => Nil
  case (_,_,-1) => Nil
  case (hd :: tl, 0, _) => hd :: cutOut(0)(b-1)(tl)
  case (hd :: tl, _, _) => cutOut(a-1)(b-1)(tl)
}
cutOut(0)(0)(Nil)
cutOut(5)(8)(Nil)
cutOut(5)(8)(List(1, 2, 3))
cutOut(5)(8)(List(1, 2, 3, 4, 5, 6, 7))
cutOut(0)(0)(List(1, 2, 3, 4, 5, 6, 7, 8))
cutOut(1)(1)(List(1, 2, 3, 4, 5, 6, 7, 8))
cutOut(3)(5)(List(1, 2, 3, 4, 5, 6, 7, 8))

val cutOut15 = cutOut(1)(5) _
cutOut15(List(1, 2, 3, 4, 5, 6, 7, 8, 9, 0))

def split3RecSeq[A](list: List[A]): (List[A], List[A], List[A]) = {
  def split(list: List[A], n: Int): ((List[A], List[A], List[A]), Int) = list match {
    case Nil => ((Nil, Nil, Nil), n)
    case h :: t =>
      val ((first, second, third), length) = split(t, n + 1)
      val oneThird = length / 3
      n match {
        case _ if n < oneThird => ((h :: first, second, third), length)
        case _ if n < 2 * oneThird => ((first, h :: second, third), length)
        case _ if n < 3 * oneThird => ((first, second, h :: third), length)
        case _ => ((first, second, third), length)
      }
  }

  val (lists, _) = split(list, 0)
  lists
}

println(split3RecSeq(Nil))
println(split3RecSeq(List(1)))
println(split3RecSeq(List(1, 2)))
println(split3RecSeq(List(1, 2, 3)))
println(split3RecSeq(List(1, 2, 3, 4)))
println(split3RecSeq(List(1, 2, 3, 4, 5)))
println(split3RecSeq(List(1, 2, 3, 4, 5, 6)))
println(split3RecSeq(List(1, 2, 3, 4, 5, 6, 7)))
println(split3RecSeq(List(1, 2, 3, 4, 5, 6, 7, 8)))

def split3Rec[A](list: List[A]): (List[A], List[A], List[A]) = list match {
  case first :: second :: third :: tl =>
    val (l1, l2, l3) = split3Rec(tl)
    (first :: l1, second :: l2, third :: l3)
  case _ => (Nil, Nil, Nil)
}

// Example usage
println(split3Rec(Nil))
println(split3Rec(List(1)))
println(split3Rec(List(1, 2)))
println(split3Rec(List(1, 2, 3)))
println(split3Rec(List(1, 2, 3, 4)))
println(split3Rec(List(1, 2, 3, 4, 5)))
println(split3Rec(List(1, 2, 3, 4, 5, 6)))
println(split3Rec(List(1, 2, 3, 4, 5, 6, 7)))
println(split3Rec(List(1, 2, 3, 4, 5, 6, 7, 8)))


def split3Tail[A](list: List[A]): (List[A], List[A], List[A]) = {
  @tailrec
  def splitTail(list: List[A], acc: (List[A], List[A], List[A])): (List[A], List[A], List[A]) = list match {
    case first :: second :: third :: tl => splitTail(tl, (first :: acc._1, second :: acc._2, third :: acc._3))
    case _ => acc
  }

  splitTail(list, (Nil, Nil, Nil))
}

// Example usage
println(split3Tail(Nil))
println(split3Tail(List(1)))
println(split3Tail(List(1, 2)))
println(split3Tail(List(1, 2, 3)))
println(split3Tail(List(1, 2, 3, 4)))
println(split3Tail(List(1, 2, 3, 4, 5)))
println(split3Tail(List(1, 2, 3, 4, 5, 6)))
println(split3Tail(List(1, 2, 3, 4, 5, 6, 7)))
println(split3Tail(List(1, 2, 3, 4, 5, 6, 7, 8)))
