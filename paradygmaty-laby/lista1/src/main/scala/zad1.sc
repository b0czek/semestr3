// zad 1
def reverse4[A](tuple: (A,A,A,A)): (A,A,A,A) =
  (tuple._4, tuple._3, tuple._2, tuple._1)

reverse4(1,2,3,4)
reverse4('d', 'u', 'p', 'a')

// zad 2

def sumProd(s: Int, e: Int): (Int, Int) =
  if s >= e then (0, 1) else {
    val (sum, prod) = sumProd(s + 1, e)
    (sum + s, prod * s)
  }
  
sumProd(1,10)
sumProd(0,1)
sumProd(0,0)
sumProd(1,2)
sumProd(10,12)
sumProd(-7,8)
sumProd(-7,0)

// zad 3

def sumDivisors: (num: Int, i: Int) => Int = (num, i) => (num, i) match {
  case (num, 0) => 0
  case (num, i) if num % i == 0 => i + sumDivisors(num, i - 1)
  case (num, i) => sumDivisors(num, i - 1)
}


def isPerfect(n: Int): Boolean = n match {
  case n if n <= 0 => false
  case _ => sumDivisors(n, n/2) == n
}

isPerfect(-100)
isPerfect(0)
isPerfect(1)
isPerfect(2)
isPerfect(3)
isPerfect(6)
isPerfect(28)

// zad 4
def insert[A](list: List[A], element: A, idx: Int): List[A] = list match {
  case Nil => List(element)
  case _ if idx == 0 => element :: list
  case x :: xs => x :: insert(xs, element, idx - 1)
}

insert(List(), 1, 1);
insert(List(1,2), 10, -1)
insert(List(1,2,3,4), 12, 0)
insert(List(1,2,3,4), 12, 1)
insert(List(1,2,3,4), 12, 2)
insert(List(1,2,3,4), 12, 3)
insert(List(1,2,3,4), 12, 4)
insert(List(1,2,3,4), 12, 5)
insert(List("a", "b", "c"), "x", 1)
