let rec cutOut a b list = match (list, a, b) with
 | ([], _, _)  -> []
 | (_,_,-1) -> []
 | (hd::tl, 0, _) -> hd :: cutOut 0 (b-1) tl
 | (hd::tl, _, _) -> cutOut (a-1) (b-1) tl;;

cutOut 0 0 [];;
cutOut 5 8 [];;
cutOut 5 8 [1;2;3];;
cutOut 5 8 [1;2;3;4;5;6;7];;
cutOut 0 0 [1;2;3;4;5;6;7;8];;
cutOut 1 1 [1;2;3;4;5;6;7;8];;
cutOut 3 5 [1;2;3;4;5;6;7;8];;

let cutOut15 = cutOut 1 5;;
cutOut15 [1;2;3;4;5;6;7;8;9;0];;



let split3RecSeq list = 
  let rec split list n = match list with
    | [] -> (([],[],[]), n)
    | h :: t -> 
        let ((first, second, third), length) = split t (n+1) in
        let oneThird = length / 3 in
        match n with 
        | _ when n < oneThird -> ((h :: first, second, third), length)
        | _ when n < 2 * oneThird -> ((first, h :: second, third), length)
        | _ when n < 3 * oneThird -> ((first, second, h :: third), length) 
        | _ -> ((first, second,third), length) in

  let (lists, length) = split list 0 in 
  lists;;
split3RecSeq [];;
split3RecSeq [1];;
split3RecSeq [1;2];;
split3RecSeq [1;2;3];;
split3RecSeq [1;2;3;4];;
split3RecSeq [1;2;3;4;5];;
split3RecSeq [1;2;3;4;5;6];;
split3RecSeq [1;2;3;4;5;6;7];;
split3RecSeq [1;2;3;4;5;6;7;8];;

let rec split3Rec list = match list with 
  | first :: second :: third :: tl -> 
    let (l1, l2, l3) = split3Rec tl in
    (first :: l1, second :: l2, third :: l3)
  |  _ -> ([],[],[]);;

split3Rec [];;
split3Rec [1];;
split3Rec [1;2];;
split3Rec [1;2;3];;
split3Rec [1;2;3;4];;
split3Rec [1;2;3;4;5];;
split3Rec [1;2;3;4;5;6];;
split3Rec [1;2;3;4;5;6;7];;
split3Rec [1;2;3;4;5;6;7;8];;
  

let split3Tail list = 
  let rec splitTail list (l1,l2,l3) = match list with
    | first :: second :: third :: tl -> splitTail tl (first :: l1, second :: l2, third :: l3);
    | _ -> (l1,l2,l3) in
  splitTail list ([],[],[]);;


split3Tail [];;
split3Tail [1];;
split3Tail [1;2];;
split3Tail [1;2;3];;
split3Tail [1;2;3;4];;
split3Tail [1;2;3;4;5];;
split3Tail [1;2;3;4;5;6];;
split3Tail [1;2;3;4;5;6;7];;
split3Tail [1;2;3;4;5;6;7;8];;