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

def sumDivisors: (num: Int, i: Int) => Int = (num, i) =>
  if i == 0 then 0 else
    sumDivisors(num, i - 1) + (if num % i == 0 then i else 0)



def isPerfect(n: Int): Boolean =
  if n <= 0 then false else
    sumDivisors(n, n/2) == n

isPerfect(-100)
isPerfect(0)
isPerfect(1)
isPerfect(2)
isPerfect(3)
isPerfect(6)
isPerfect(28)

// zad 4
def insert[A](list: List[A], element: A, idx: Int): List[A] =
  if list == Nil then List(element) else
    if idx == 0 then element :: list else list.head :: insert(list.tail, element, idx - 1)

insert(List(), 1, 1);
insert(List(1,2), 10, -1)
insert(List(1,2,3,4), 12, 0)
insert(List(1,2,3,4), 12, 1)
insert(List(1,2,3,4), 12, 2)
insert(List(1,2,3,4), 12, 3)
insert(List(1,2,3,4), 12, 4)
insert(List(1,2,3,4), 12, 5)
insert(List("a", "b", "c"), "x", 1)

def choice[A](list1: List[A], list2: List[A]): List[A] =
  if list1 == Nil 
