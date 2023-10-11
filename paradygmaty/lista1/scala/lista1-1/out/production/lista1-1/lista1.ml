let rec flatten1 : 'a list list -> 'a list = fun lst ->
    if List.length(lst)=0 then [] else List.hd(lst) @ flatten1 (List.tl(lst))


let rec count : 'a * 'a list -> int = fun (x,lst) ->
    if List.length (lst)=0 then 0 else ((if List.hd (lst) = x then 1 else 0) + count(x, List.tl (lst)))

let rec replicate: 'a * int -> 'a list = fun (x,n) ->
    if n = 0 then [] else replicate(x,n-1) @ [x]
     
let rec sqrList : int list -> int list = fun(lst) ->
    if List.length lst = 0 then [] else [ List.hd lst * List.hd lst ] @ sqrList(List.tl lst)

let rec palindrome : 'a list -> bool = fun lst ->
    lst = List.rev lst
//    List.length lst <= 1 || (List.hd lst = List.hd (List.rev (List.tl lst)) && palindrome(List.tl(List.rev (List.tl lst))))


let rec listLength : 'a list -> int = fun lst ->
    if lst = [] then 0 else 1 + listLength(List.tl lst)