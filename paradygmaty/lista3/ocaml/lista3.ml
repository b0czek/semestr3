(* 1.
  let f1 x = x 2 2;;
  f1: (int -> int -> 'a) -> 'a

  let f2 x y z = x ( y ^ z );;
  f2: (string -> 'a) -> string -> string -> 'a


*)

(* 2 *)
let curry3 f x y z = f(x,y,z);;
let curry3' = function f -> function x -> function y -> function z -> f(x,y,z);; 
(* typ: 
  curry3: ('a * 'b * 'c -> 'd) -> 'a -> 'b -> 'c -> 'd   
*)

let uncurry3 f (x,y,z) = f x y z;;
let uncurry3' = function f -> function (x,y,z) -> f x y z;;
(* typ:
  uncurry3: ('a -> 'b -> 'c -> 'd) -> 'a * 'b * 'c -> 'd   
*)

(* 3 *)
let rec sumProd xs =
  List.fold_left (fun (s,p) x -> (s+x, p*x)) (0, 1) xs;;

(* 4 *)
let rec quicksort = function
  [] -> []
  | [x] -> [x]
  | pivot :: tail -> let small = List.filter (fun y -> (y < pivot) ) tail
          and large = List.filter (fun y -> (y >= pivot) ) tail
          in quicksort small @ (pivot :: quicksort large);;
(* bo pivot nie jest usuwany w kolejnych rekurencyjnch wywolaniach funkcji przez co zawsze dzieli liste na pusta small i ta sama large *)

let rec quicksort' = function
  [] -> []
  | [x] -> [x]
  | x::xs -> let small = List.filter (fun y -> y < x ) xs
              and large = List.filter (fun y -> y > x ) xs
              in quicksort' small @ (x :: quicksort' large);;

(* brak base case'a *)