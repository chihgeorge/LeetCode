/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null) {
		return null;
	}        

        UndirectedGraphNode firstNewNode = new UndirectedGraphNode(node.label); 
        HashMap<Integer, UndirectedGraphNode> map = new HashMap();
        
        map.put(firstNewNode.label, firstNewNode);
        
        Queue<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>(); 
        queue.offer(node); 
        
        while (!queue.isEmpty()) { 
            UndirectedGraphNode nextNode = queue.poll(); 
            for (UndirectedGraphNode neighbor : nextNode.neighbors) {
                if (!map.containsKey(neighbor.label)) { 
                    map.put(neighbor.label, new UndirectedGraphNode(neighbor.label));
                    queue.add(neighbor);
                }
                map.get(nextNode.label).neighbors.add(map.get(neighbor.label)); 
            }
        }
        
        return firstNewNode;
    }
}