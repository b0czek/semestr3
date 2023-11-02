let reverse4 = fun (a,b,c,d) -> d,c,b,a;;

reverse4(1,2,3,4);;
reverse4("a", "b", "c", "d");;

let rec sumProd = fun (s,e) -> 
  if s >= e then (0,1) else 
    let (sum, prod) = sumProd(s+1, e) in
    (sum + s, prod * s);;

sumProd(1,10);;
sumProd(0,1);;
sumProd(0,0);;
sumProd(1,2);;
sumProd(10,12);;
sumProd(-7,8);;
sumProd(-7,0);;
    
let rec sumDivisors = fun (num, i) -> if i <= 0 then 0 else
  sumDivisors(num, i - 1) + if num mod i = 0 then i else 0


let isPerfect = fun n -> if n = 0 then false else sumDivisors(n, n/2) = n;;

isPerfect(-100);;
isPerfect 0;;
isPerfect 1;;
isPerfect 2;;
isPerfect 3;;
isPerfect 6;;
isPerfect 28;;

let rec insert = fun (list, element, idx) ->
  if list = [] then [element] else
    if idx == 0 then element:: list else List.hd list :: insert(List.tl list, element, idx - 1);;


let table = [1;2;3;4];;

insert([], 1, 1);;
insert([1;2], 10, -1);;
insert(table, 12, 0);;
insert(table, 12, 1);;
insert(table, 12, 2);;
insert(table, 12, 3);;
insert(table, 12, 4);;
insert(table, 12, 5);;
insert(["a"; "b"; "c"], "x", 1);;


let rec choice = fun(list1, list2) ->
  if list1 = [] then
    if list2 = [] then [] else List.hd list2 :: choice(list1, List.tl list2)
  else
    if list2 = [] then List.hd list1 :: choice(List.tl list1, list2) else
      List.hd (if List.hd list1 > List.hd list2 then list1 else list2) :: choice(List.tl list1, List.tl list2);;

choice([], []);;
choice([2;8;6;1;2;1;1;1;6], []);;
choice([2;8;6;1;2;1;1;1;6], [1;10;7;2;2;2]);;
choice([2;8], [1;10;7;2;2;2]);;
choice([0;8;100;100],[1;10;7;1000]);;


let squish = fun list ->
  let rec squishInner = fun (xs, xss) ->
    if xs = [] then 
      if xss = [] then [] else squishInner(List.hd xss, List.tl xss)
    else 
      List.hd xs :: squishInner(List.tl xs, xss) in
  
  if list = [] then [] else squishInner(List.hd list, List.tl list);;


squish [];;
squish [[]; []];;
squish [[1]; []];;
squish [[1]; []; [2]];;
squish [[1]; [2]];;
squish [[1;2;3;4]; [4;4;4;4]; [1;1;1;1111]];;
squish [['a';'b';'c']; ['d';'e';'f']];;


let rec select = fun (lists, idxs) -> 
  let rec getIdx = fun (list, idx) ->
      if idx = 0 then List.hd list else getIdx (List.tl list, idx - 1) in
  if lists = [] || idxs = [] then [] else getIdx(List.hd lists, List.hd idxs) :: select(List.tl lists, List.tl idxs);;

select([[1;5;3;8]; [2;7;4;1]], [2;0]);;

  let rec helper list maxval idx = 
    if list = [] then ([], maxval)
    else
      let (res, newmax) = helper ((List.tl list), maxval, idx+1) in
      if List.hd list = newmax then (List.hd list :: res) else res;;


