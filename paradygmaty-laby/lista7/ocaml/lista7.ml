let modifiedPascalF n =
  let rec next_row f l = 
    match l with
     | [] -> []
     | h :: [] -> [1]
     | fst :: snd :: tl -> f fst snd :: next_row f (snd::tl) in
  let rec aux i row = 
    if i = n then []
    else row :: aux (i + 1) (1 :: next_row (if i mod 2 == 1 then (+) else (-)) row) in
  if n < 0 then [] else aux 0 [1];;


let modifiedPascalI n = 
  if n < 0 then [||] else
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



let sieve n = 
  let array = Array.make (n+1) true in
  let sqrtn = int_of_float (sqrt (float_of_int(n+1))) in
  let counter = ref 2 in
  for i = 2 to sqrtn do
    if array.(i) then (
      let j = ref (i*i) in
      while !j < (n+1) do
        if array.(!j) then (
          array.(!j) <- false;
          counter := !counter + 1;
        );

        j := !j + i;
      done;
  
    );
  done;
  let primes_count = max 0 ((n+1) - !counter) in
  let numbers = Array.make primes_count 0 in
  let idx = ref 0 in
  for i = 2 to n do 
    

    if array.(i) then (
      numbers.(!idx) <- i;
      idx := !idx + 1;
    );
  done;
  numbers;;

modifiedPascalF (-4);;
modifiedPascalF 0;;
modifiedPascalF 7;;
modifiedPascalI (-4);;
modifiedPascalI 0;;
modifiedPascalI 7;;

sieve 0;;
sieve 1;;
sieve 2;;
sieve 100;;