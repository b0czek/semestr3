type 'a lazyBinaryTree = TreeNone | TreeNode of 'a * (unit -> 'a lazyBinaryTree) * (unit -> 'a lazyBinaryTree);;

let rec treeFrom x = if x = 0 then TreeNone else TreeNode (x, (function () -> treeFrom(x - 1)), (function () -> treeFrom(x - 1)));;

let rec treeFoldL f acc tree = 
  match tree with
  | TreeNone -> acc
  | TreeNode(v,l,r) -> 
      let acc = treeFoldL f acc (l()) in 
      let acc = f acc v in
      treeFoldL f acc (r());;


let sum a b = a + b;;

let treenode = TreeNode(
  1, 
  (fun () -> TreeNode(2, (fun () -> TreeNone), (fun () -> TreeNone))), 
  (fun () -> TreeNone)
);;

treeFoldL (sum) 0 (treeFrom 1);;
treeFoldL (sum) 0 (treeFrom 2);;
treeFoldL (sum) 0 (treeFrom 3);;
treeFoldL (sum) 0 (treeFrom 4);;