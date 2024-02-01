trait Low
trait High extends Low
trait Super extends High

type Permission = Low // lowest permission rank

trait User[+UR <: Permission, +UW <: Permission] {
  def retrieveFromTerminal(retrieved: String): Unit
  def passToTerminal(): String

}

class Terminal[TR <: Permission, TW <: TR](initialSecret: String) {
  private var secret: String = initialSecret

  def read(user: User[TR,Permission]): Unit = {
    user.retrieveFromTerminal(secret)
  }
  def write(user: User[Permission,TW]): Unit = {
    secret = user.passToTerminal()
  }
}

object LowUser extends User[Low, Low] {
   var secret: String = "???"

   override def retrieveFromTerminal(retrieved: String): Unit = secret = retrieved

   override def passToTerminal(): String = secret
}

object LowHighUser extends User[Low, High] {
  var secret: String = "lowhigh"

  override def retrieveFromTerminal(retrieved: String): Unit = secret = retrieved

  override def passToTerminal(): String = secret
}

object HighLowUser extends User[High, Low] {
  var secret: String = "highlow"

  override def retrieveFromTerminal(retrieved: String): Unit = secret = retrieved

  override def passToTerminal(): String = secret
}

object HighUser extends User[High, High] {
  var secret: String = "faded"

  override def retrieveFromTerminal(retrieved: String): Unit = secret = retrieved

  override def passToTerminal(): String = secret
}

object SuperUser extends User[Super, Super] {
  var secret: String = "super"

  override def retrieveFromTerminal(retrieved: String): Unit = secret = retrieved

  override def passToTerminal(): String = secret
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