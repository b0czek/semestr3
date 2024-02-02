trait Low
trait High extends Low
trait Super extends High

type Permission = Low // lowest permission rank

trait User[+UR <: Permission, +UW <: Permission] {

  def secret: String
  def secret_=(newSecret: String): Unit
}

class Terminal[TR <: Permission, TW <: TR](initialSecret: String) {
  private var secret: String = initialSecret

  def read(user: User[TR,_]): Unit = {
    user.secret = secret
  }
  def write(user: User[_,TW]): Unit = {
    secret = user.secret
  }
}

object LowUser extends User[Low, Low] {
   var secret: String = "???"

}

object LowHighUser extends User[Low, High] {
  var secret: String = "lowhigh"

}

object HighLowUser extends User[High, Low] {
  var secret: String = "highlow"

}

object HighUser extends User[High, High] {
  var secret: String = "faded"

}

object SuperUser extends User[Super, Super] {
  var secret: String = "super"

}

val lowTerminal = new Terminal[Low, Low]("lowterm")


LowUser.secret
lowTerminal.read(LowUser)
LowUser.secret


val highTerminal = new Terminal[High, High]("highterm")

//LowUser.secret
//highTerminal.read(LowUser)
//LowUser.secret

HighUser.secret
highTerminal.read(HighUser)
HighUser.secret


val lowHighTerminal = new Terminal[Low, High]("lowhighterm")

lowHighTerminal.read(LowUser)
lowHighTerminal.read(HighUser)
lowHighTerminal.write(HighUser)

//lowHighTerminal.write(LowUser)


//
//val highLowTerminal = new Terminal[High, Low]("highlowterminal");
//


val superTerminal = new Terminal[Super, Super]("superterm")
//superTerminal.read(LowUser)
//superTerminal.read(LowHighUser)
//superTerminal.read(HighLowUser)
//superTerminal.read(HighUser)
superTerminal.read(SuperUser)

