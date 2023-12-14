let modifiedPascalF n =
  let rec next_row f l = 
    match l with
     | [] -> []
     | h :: [] -> [1]
     | fst :: snd :: tl -> f fst snd :: next_row f (snd::tl) in
  let rec aux i row = 
    if i = n then []
    else row :: aux (i + 1) (1 :: next_row (if i mod 2 == 1 then (+) else (-)) row) in
  aux 0 [1];;

let modifiedPascalI n = 
  let triangle = Array.make n [||] in

  for i = 0 to n - 1 do
    triangle.(i) <- Array.make (i+1) 0;
    triangle.(i).(0) <- 1;
    
    for j = 1 to i do 
      let v = ref triangle.(i - 1).(j - 1) in
      if j <= i - 1 then (
        if i mod 2 = 0 then
          v := !v + triangle.(i - 1).(j)
        else
          v := !v - triangle.(i - 1).(j)
      );
      triangle.(i).(j) <- !v;
    done;
  done;

triangle;;