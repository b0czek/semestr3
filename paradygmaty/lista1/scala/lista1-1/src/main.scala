object Main {
  // zad1
  def flatten1[A] (xss: List[List[A]]): List[A] =
    if xss.size == 0 then List() else xss.head ::: flatten1(xss.tail)

  def count[A] (x: A, xs: List[A]): Int =
    if xs.size == 0 then 0 else ((if xs.head == x then 1 else 0) + count(x, xs.tail))



  //  def count[A] (x: A, xs: List[A]): Int = xs match {
  //    case l if(l.size == 0) => 0
  //    case l => ((if l.head == x then 1 else 0) + count(x, l.tail))
  //  }

  def replicate[A] (x: A, n: Int): List[A] =
    if n == 0 then List() else replicate(x, n-1) :+ x

  def sqrList(xs: List[Int]): List[Int] =
    if xs.size == 0 then List() else xs.head * xs.head :: sqrList(xs.tail)

  def palindrome[A] (xs: List[A]): Boolean =
    xs == xs.reverse
//   xs.size <= 1 || (xs.head == xs.tail.reverse.head && palindrome(xs.tail.reverse.tail))

  def listLength[A](xs: List[A]): Int =
    if xs == List() then 0 else 1 + listLength(xs.tail)

  def main(args: Array[String]): Unit = {

    palindrome(List('k','a','j','a','k'))
    val sqrList1: (List[Int]) => List[Int] = xs =>
        if xs.size == 0 then List() else xs.head * xs.head :: sqrList(xs.tail)


  }
}