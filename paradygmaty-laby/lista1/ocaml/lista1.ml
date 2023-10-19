let reverse4 = fun (a,b,c,d) -> d,c,b,a;;

reverse4(1,2,3,4);;

let rec sumProd = fun (s,e) -> 
  if s >= e then (0,1) else 
    let (sum, prod) = sumProd(s+1, e) in
    (sum + s, prod * s);;

sumProd(1,10);;
sumProd(0,1);;
sumProd(0,0);;
sumProd(1,2);;
sumProd(10,12);;
    
let rec sumDivisors = function
  | (num, 0) -> 0
  | (num, i) when num mod i = 0 -> i + sumDivisors(num, i-1)
  | (num, i) -> sumDivisors(num, i - 1) ;;

let isPerfect = function
  | 0 -> false
  | n -> (sumDivisors (n, n/2) = n);;


isPerfect 0;;
isPerfect 1;;
isPerfect 2;;
isPerfect 3;;
isPerfect 6;;
isPerfect 28;;

let rec insert = fun (list, element, idx) -> match list with
  | [] -> [element]
  | _ when idx = 0 -> element :: list
  | x :: xs -> x :: insert(xs, element, idx - 1);;

let table = [1;2;3;4];;

insert(table, 12, 0);;
insert(table, 12, 1);;
insert(table, 12, 2);;
insert(table, 12, 3);;
insert(table, 12, 4);;
insert(table, 12, 5);;

