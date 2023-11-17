let (><) l1 l2 f = 
  let rec combine a b = 
    match (a,b) with
    | (ha :: ta, hb :: tb) -> (ha, hb) :: combine ta tb 
    | _ -> [] in 
  List.map f (combine l1 l2);;

let mult (x,y) = x*y;;

let a = [] >< [];;
a mult;;

let a = [1;2;3;4] >< [5;6;7;8];;
a mult;;

let a = [1;2] >< [1;2;3;4;5];;
a mult;;

let a = [1;2;3;4;5] >< [1;2];;
a mult;;

let a = [1;2;3;4] >< ['a';'b';'c';'d'];;
a (fun (x,y) -> x + Char.code y);;
