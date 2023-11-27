//1
type Point2D = (Double, Double)

def distance(point: Point2D): Double = {
  val (a, b) = point
  Math.sqrt(a * a + b * b)
}
//2
sealed trait Gender
case object Male extends Gender
case object Female extends Gender

type Person = (String, String, Gender, Int, Int)
type Partnership = (Person, Person)

def younger(pair: Partnership): Person =
  val (a, b) = pair
  pair match {
  case ((_, _, _, ageA, _), (_, _, _, ageB, _)) =>
    if (ageA > ageB) b else a
}
val man: Person = ("Jan", "Kowalski", Male, 30, 44)
val woman: Person = ("Maja", "Kowalska", Female, 29, 39)
val youngerPerson = younger((man,woman))


case class Person2(firstName: String, lastName: String, gender: Gender, age: Int, shoeSize: Int)
case class Partnership2(personA: Person2, personB: Person2)

def younger(partnership: Partnership2): Person2 =
  if (partnership.personA.age > partnership.personB.age) partnership.personB else partnership.personA

val man2: Person2 = Person2("Jan", "Kowalski", Male, 30, 44)
val woman2: Person2 = Person2("Maja", "Kowalska", Female, 29, 39)

val youngerPerson2: Person2 = younger(Partnership2(man2, woman2))

//3
sealed trait WeekDay
case object Monday extends WeekDay
case object Tuesday extends WeekDay
case object Wednesday extends WeekDay
case object Thursday extends WeekDay
case object Friday extends WeekDay
case object Saturday extends WeekDay
case object Sunday extends WeekDay

def weekDayToString(day: WeekDay): String = day match {
  case Monday => "poniedzialek"
  case Tuesday => "wtorek"
  case Wednesday => "sroda"
  case Thursday => "czwartek"
  case Friday => "piatek"
  case Saturday => "sobota"
  case Sunday => "niedziela"
}

def nextDay(day: WeekDay): WeekDay = day match {
  case Monday => Tuesday
  case Tuesday => Wednesday
  case Wednesday => Thursday
  case Thursday => Friday
  case Friday => Saturday
  case Saturday => Sunday
  case Sunday => Monday
}




//4
sealed trait Maybe[+A]
case class Just[A](value: A) extends Maybe[A]
case object Nothing extends Maybe[Nothing]

def safeHead[A](list: List[A]): Maybe[A] = list match {
  case Nil => Nothing
  case h :: _ => Just(h)
}

//5
sealed trait SolidFigure

case class Cuboid(x: Float, y: Float, z: Float) extends SolidFigure
case class Cone(r: Float, h: Float) extends SolidFigure
case class Sphere(r: Float) extends SolidFigure
case class Cylinder(r: Float, h: Float) extends SolidFigure

def volume(figure: SolidFigure): Float = figure match {
  case Cuboid(x, y, z) => x * y * z
  case Cone(r, h) => Math.PI.toFloat * r * r * h / 3.0f
  case Sphere(r) => Math.PI.toFloat * r * r * r * 4 / 3
  case Cylinder(r, h) => Math.PI.toFloat * r * r * h
}
