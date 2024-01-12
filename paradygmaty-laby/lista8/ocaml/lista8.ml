module type MEMORY = sig
  type repr
  val init : int -> repr
  val get : int -> repr -> int
  val set : int -> int -> repr -> repr
  val dump : repr -> int list
end;;


module ArrayMemory : MEMORY = struct
    type repr = int option array

    let init size = Array.make size None
    
    let get index memory =
      if index < 0 || index >= Array.length memory then
        failwith "Invalid index"
      else
        match memory.(index) with
        | Some(value) -> value
        | None -> failwith "Empty cell"

    let set index value memory =
      if index < 0 || index >= Array.length memory then
        failwith "Invalid index"
      else
        memory.(index) <- Some(value);
        memory

    let dump memory =
      Array.to_list (Array.map (function Some(v) -> v | None -> 0) memory)
    

end;;



let () =
  let memory = ArrayMemory.init 10 in
  let memory = ArrayMemory.set 0 42 memory in
  let value = ArrayMemory.get 0 memory in
  let dump = ArrayMemory.dump memory in
  Printf.printf "Value at index 0: %d\n" value;
  Printf.printf "Memory dump: [%s]\n" (String.concat "; " (List.map string_of_int dump));;

  module ListMemory : MEMORY = struct
    type repr = int option list ref
  
    let init size = ref (List.init size (fun _ -> None))
        
    let get index memory = 
      match (List.nth !memory index) with 
      | Some(value) -> value
      | None -> failwith "Empty cell!"
        
    let set index value memory =
      memory := List.mapi  (fun idx v -> if idx == index then Some(value) else v) !memory;
      memory
    
    let dump memory = 
      List.map (function Some(v) -> v | None -> 0) !memory
  end;;
  

type instruction = Load of int*int | Add of int*int*int | Sub of int*int*int;;

module RAMMachine (Memory : MEMORY) = struct

  type repr = Memory.repr * instruction list

  let init size instructions =
    let memory = Memory.init size in
    (memory, instructions)

  let execute memory = function
    | Load (d, v) -> Memory.set d v memory
    | Add (d, a1, a2) ->
      let v1 = Memory.get a1 memory in
      let v2 = Memory.get a2 memory in
      Memory.set d (v1 + v2) memory
    | Sub (d, a1, a2) ->
      let v1 = Memory.get a1 memory in
      let v2 = Memory.get a2 memory in
      Memory.set d (v1 - v2) memory

  let step (memory, instructions) =
    match instructions with
    | [] -> (memory, [])
    | curr :: tl ->
      (execute memory curr, tl)

  let rec step_all machine = 
    match step machine with 
     | (memory, []) -> (memory, [])
     | machine -> step_all machine


  let dump (memory, _) = Memory.dump memory
end;;

module ArrayRAMMachine = RAMMachine(ArrayMemory);;

let () =
  let instructions = [Load(0, 42); Load(3, -6); Add(1, 0, 3); Add(2, 1, 1); Sub(2, 1, 2)] in
  let machine = ArrayRAMMachine.init 4 instructions in
  let final_memory = ArrayRAMMachine.step_all machine in
  let memory_dump = ArrayRAMMachine.dump final_memory in
  Printf.printf "Memory dump: [%s]\n" (String.concat "; " (List.map string_of_int memory_dump));;

