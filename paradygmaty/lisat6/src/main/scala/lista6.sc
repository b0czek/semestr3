// zad1
def whileLoop(predicate: () => Boolean, expression: () => Unit): Unit =
  while (predicate()) {
    expression()
  }

var count = 0
whileLoop(() => count < 3, () => {
  println(count);
  count += 1
})

def swap(tab: Array[Int], i: Int, j: Int): Unit =
  val temp = tab(i)
  tab(i) = tab(j)
  tab(j) = temp

def choose_pivot(tab: Array[Int], m: Int, n: Int) = tab((m+n) / 2)

def partition(tab: Array[Int], l: Int, r: Int): (Int, Int) = {
  var i = l
  var j = r
  val pivot = choose_pivot(tab, l, r)

  while (i <= j) {
    while (tab(i) < pivot) i += 1
    while (tab(j) > pivot) j -= 1

    if (i <= j) {
      swap(tab, i, j)
      i += 1
      j -= 1
    }
  }

  (i, j)
}

def quick(tab: Array[Int], l: Int, r: Int): Unit = {
  if (l < r) {
    val (i, j) = partition(tab, l, r)

    if (j - l < r - i) {
      quick(tab, l, j)
      quick(tab, i, r)
    } else {
      quick(tab, i, r)
      quick(tab, l, j)
    }
  }
}

def quicksort(tab: Array[Int]) : Unit =
  quick (tab, 0, tab.length - 1)

val arr = Array(5,7,1,4,444,23,34,342,1,1,1,1)
quicksort(arr)
arr

// zad3
// true
// false
// przyrownanie adresow i wartosci


// zad 4
// true - ten sam static string - ten sam adres
// true - to samo w stringu
// false - przyrownanie referencji przy zalokowanym stringu
// true - to samo w stringu

// zad 5
// 1,2,3
// 1,2,3 - kopie w forze nie nadpisuja oryginalu
// 1,2,3
// -1,-1,-1 - kopia wskaznika na ta sama tablice