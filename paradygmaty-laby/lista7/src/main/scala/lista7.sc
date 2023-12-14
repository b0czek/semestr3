def modifiedPascalI(n: Int): Array[Array[Int]] = {
  val triangle = Array.fill(n)(Array.fill(0)(0))

  for (i <- 0 until n) {
    triangle(i) = Array.fill(i + 1)(0)
    triangle(i)(0) = 1

    for (j <- 1 to i) {
      var v = triangle(i - 1)(j - 1)

      if (j <= i - 1) {
        if (i % 2 == 0)
          v += triangle(i - 1)(j)
        else
          v -= triangle(i - 1)(j)
      }

      triangle(i)(j) = v
    }
  }

  triangle
}

// Example usage
val result = modifiedPascalI(6)