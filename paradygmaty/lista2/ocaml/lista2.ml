(* -2- *)


let rec fib n = match n with
  | 0 -> 0
  | 1 -> 1
  | _ -> fib(n - 1) + fib(n - 2);;

fib 10;;


  
(* elem1 = n-1 elem2 = n-2 *)
let fibTail n =
  let rec innerHelper n elem1 elem2 =
    if n = 0 then elem2
    else innerHelper (n - 1) elem2 (elem1 + elem2)
  in
  if n = 0 then 0
  else innerHelper (n - 1) 0 1;;
      
let n2 = 10 in
fibTail n2;;



(** zad 4 *)

let (_::_::x::_) = [-2;-1;0;1;2];;

let ( _ :: (x, _) :: _) = [(1,2); (0,1)];;


(** zad 5 *)
let rec zad5 lists = match lists with 
 | ([], _) -> true
 | (_, []) -> false
 | (ha :: ta, hb :: tb) when ha <> hb -> false
 | (_ :: ta, _ :: tb) -> zad5 (ta, tb);;


zad5 ([1;2;3;4], [1;2;3;4;5;6;7]);;
zad5 ([], [1;2;3;4;5;6;7]);;
zad5 ([1;2;3;4], []);;
zad5 ([1;2;3;4;1], [1;2;3;4;5;6;7]);;

