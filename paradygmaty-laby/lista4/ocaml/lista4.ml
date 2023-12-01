(* 1 *)
type point2D = float * float;;

let distance ((a,b): point2D) = sqrt(a *. a +. b *. b);;


(* 2 *)
type gender = Male | Female | Other of string;;

type person = string * string * gender * int * int;;
type partnership = person * person;;

let younger ((a, b) : partnership) = match (a,b) with 
| ((_,_,_,ageA,_), (_,_,_,ageB,_)) -> if ageA > ageB then b else a;;

let man: person = ("Jan", "Kowalski", Male, 30, 44);;
let woman: person = ("Maja", "Kowalska", Female, 29, 39);;

let youngerPerson = younger (man, woman);;



type person' = { firstName: string; lastName: string; gender: gender; age: int; shoeSize: int };;
type partnership' = {personA: person'; personB: person'};;

let younger' (p : partnership') = if p.personA.age > p.personB.age then p.personB else p.personA;;


let man' : person' = { firstName = "Jan"; lastName = "Kowalski"; gender = Male; age = 30; shoeSize = 44 };;
let woman' : person' = { firstName = "Maja"; lastName = "Kowalska"; gender = Female; age = 29; shoeSize = 39 };;
let youngerPerson' = younger' {personA = man'; personB = woman'};;




(* 3 *)
type weekDay = 
  | Monday
  | Tuesday
  | Wednesday
  | Thursday
  | Friday
  | Saturday
  | Sunday;;

let weekDayToString = function
  | Monday -> "poniedzialek"
  | Tuesday -> "wtorek"
  | Wednesday -> "sroda"
  | Thursday -> "czwartek"
  | Friday -> "piatek"
  | Saturday -> "sobota"
  | Sunday -> "niedziela";;

let nextDay = function
| Monday -> Tuesday
| Tuesday -> Wednesday
| Wednesday -> Thursday
| Thursday -> Friday
| Friday -> Saturday
| Saturday -> Sunday
| Sunday -> Monday;;

(* 4 *)
type ('a) maybe = Just of 'a | Nothing;;

let safeHead = function 
  | [] -> Nothing
  | h::_ -> Just h;;

(* 5 *)
type solidFigure = 
  | Cuboid of float * float * float 
  | Cone of float * float 
  | Sphere of float 
  | Cylinder of float * float;;

let volume = function
  | Cuboid(x,y,z) -> x *. y *. z
  | Cone(r, h) -> Float.pi *. r *. r *. h /. 3.
  | Sphere(r) -> Float.pi *. r *. r *. r *. 4. /. 3.  
  | Cylinder(r, h) -> Float.pi *. r *. r *. h;;



