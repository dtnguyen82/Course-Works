
public class AVLTree {
	public NodeTree root;
	public int theNodeCount;
	private int size;
	private int side;
	public AVLTree(){
		root = null;
	}
	public boolean isEmpty(){
		return root == null;
	}
	public int getSize(){
		return size;
	}
	public void insert(int value){
		root = insert(value, root);
	}
	public NodeTree insert(int value, NodeTree localRoot){
		if(localRoot == null){
			localRoot = new NodeTree(value);
			localRoot.height = 0;
		}
		else{
			if(value < localRoot.value){
				localRoot.left = insert(value,localRoot.left);
				if(height(localRoot.left) -height(localRoot.right) == 2){
					if(value < localRoot.left.value)
						localRoot = singleRotation(localRoot,0);
					else
						localRoot = doubleRotation(localRoot,0);
				}
			}else if(value > localRoot.value){
				localRoot.right = insert(value, localRoot.right);
				if(height(localRoot.right) - height(localRoot.left)==2){
					if(value>localRoot.right.value)
						localRoot = singleRotation(localRoot,1);
					else
						localRoot = singleRotation(localRoot,1);
				}
			}
			localRoot.height = Math.max(height(localRoot.left), height(localRoot.right)) + 1;
		}
		return localRoot;
	}
	
	public void remove(int value){
		try{
			root = remove(value,root);
		}catch(Exception e){
			System.err.println("+++ ERROR: "+e.getMessage());
		}
	}
	
	private NodeTree remove(int value, NodeTree localRoot)throws Exception{
		if(localRoot == null){
			throw new Exception("Node not found to remove");
		}
		NodeTree replacementNode;
		if(value < localRoot.value){
			localRoot.left = remove(value , localRoot.left);
			localRoot = rebalance(localRoot);
			localRoot.height = Math.max(height(localRoot.left), height(localRoot.right))+1;
		}else if(value > localRoot.value){
			localRoot.right = remove(value, localRoot.right);
			localRoot = rebalance(localRoot);
			localRoot.height = Math.max(height(localRoot.left), height(localRoot.right))+1;
		}else if(localRoot.left != null && localRoot.right != null){
			replacementNode = findMin(localRoot.right);
			replacementNode.left = localRoot.left;
			localRoot = null;
			replacementNode = rebalance(replacementNode);
			replacementNode.height = Math.max(height(replacementNode.left), height(replacementNode.right))+1;
			return replacementNode;
		}else
			localRoot = (localRoot.left != null) ? localRoot.left : localRoot.right;
		return localRoot;
	}
	private NodeTree findMin(NodeTree localRoot){
		NodeTree minNode;
		if(localRoot.left != null){
			minNode = findMin(localRoot.left);
			localRoot.left = minNode.right;
			if(localRoot.left == minNode){
				localRoot.height = Math.max(height(localRoot.left), height(localRoot.right))+1;
			}
			localRoot = rebalance(localRoot);
			localRoot.height = Math.max(height(localRoot.left), height(localRoot.right))+1;
			minNode.right = localRoot;
			return minNode;
		}else{
			return localRoot;
		}
	}
	private NodeTree singleRotation(NodeTree node, int side){
		NodeTree temp = node;
		if( side == 0 ){
			temp = node.left;
			node.left = temp.right;
			temp.right = node;
			node.height = Math.max( height( node.left ), height( node.right ) ) + 1;
			temp.height = Math.max( height( temp.right ), height( node ) ) + 1;
		}else if(side == 1){
			temp = node.right;
			node.right = temp.left;
			temp.left = node;
			node.height = Math.max( height( node.left ), height( node.right ) ) + 1;
			temp.height = Math.max( height( temp.right ), height( node ) ) + 1;
		}
		return temp;
	}
	private NodeTree doubleRotation(NodeTree node, int side)
	{
		if( side == 0 ) //Double Left Rotation
		{
			node.left = singleRotation( node.left, 1 );
			return singleRotation( node, 0 );
		}
		else if( side == 1 ) //Double Right Rotation
		{
			node.right = singleRotation( node.right, 0 );
			return singleRotation( node, 1 );
		}
		return node;
	}
	private NodeTree rebalance(NodeTree node){
		if( Math.abs(height( node.right ) - height( node.left )) == 2 ){
			if(node.left == null){
				if(node.right.left == null){
					node = singleRotation(node,1);
				}else
					node = doubleRotation(node,1);
			}else if(node.right == null){
				if(node.left.right == null)
					node = singleRotation(node,0);
				else
					node = doubleRotation(node,0);
			}
		}
		return node;
	}
	public boolean find(int value){
		NodeTree node = root;
		while(node != null){
			if(value < node.value)
				node = node.left;
			else if(value > node.value)
				node = node.right;
			else
				return true;
		}
		return false;
	}
	private static int height(NodeTree n){
		return n == null ? -1 : n.height;
	}
}
