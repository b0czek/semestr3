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

insert(List(), 1, 1)
insert(List(1,2), 10, -1)
insert(List(1,2,3,4), 12, 0)
insert(List(1,2,3,4), 12, 1)
insert(List(1,2,3,4), 12, 2)
insert(List(1,2,3,4), 12, 3)
insert(List(1,2,3,4), 12, 4)
insert(List(1,2,3,4), 12, 5)
insert(List("a", "b", "c"), "x", 1)

def choice(list1: List[Int], list2: List[Int]): List[Int] =
  if list1 == Nil then
    if list2 == Nil then List() else list2.head :: choice(list1, list2.tail)
  else
    if list2 == Nil then list1.head :: choice(list1.tail, list2) else
      (if list1.head > list2.head then list1.head else list2.head) :: choice(list1.tail, list2.tail)

choice(List(), List())
choice(List(2,8,6,1,2,1,1,1,6), List())
choice(List(2,8,6,1,2,1,1,1,6), List(1,10,7,2,2,2))
choice(List(2,8), List(1,10,7,2,2,2))
choice(List(0,8,100,100), List(1,10,7,1000))



def squish[A](xss: List[List[A]]): List[A] =
  def squishInner(xs: List[A], xss: List[List[A]]): List[A] =
    if xs == Nil then
      if xss == Nil then List() else squishInner(xss.head, xss.tail)
    else
      xs.head :: squishInner(xs.tail, xss)

  if xss == Nil then List() else squishInner(xss.head, xss.tail)

squish(List())
squish(List(List(), List()))
squish(List(List(1), List()))
squish(List(List(1), List(), List(2)))
squish(List(List(1), List(2)))
squish(List(List(1,2,3,4), List(4,4,4,4), List(1,1,1,1111)))
squish(List(List('a', 'b', 'c'), List('d','e', 'f')))