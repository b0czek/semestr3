let argmax list =
    let rec helper (list, maxval, idx) =  
        if list = [] then ([], maxval)
        else
            let head = List.hd list in
            let (res, newmax) = helper (List.tl list, (if maxval > head then maxval else head), idx+1) in
            if head = newmax then ((idx :: res), newmax) else (res, newmax) in
    if list = [] then [] else 
      let (idxs, max) = helper(list, List.hd list, 0) in 
      idxs;;

  argmax [1;2;2;2;0;0;-1;2;5];;
