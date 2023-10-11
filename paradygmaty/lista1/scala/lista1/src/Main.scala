import javax.swing.plaf.nimbus.NimbusLookAndFeel

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



  def main(args: Array[String]): Unit = {
    println("Hello world!");
    val list1 = List(1,2,3);
    val list2 = List(2,2,2);
    val list3 = List();

    flatten1(list3);


  }
}