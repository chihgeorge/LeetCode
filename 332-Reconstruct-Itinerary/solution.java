public class Solution {
    public List<String> findItinerary(String[][] tickets) {
        Map<String, PriorityQueue<String>> map = new HashMap<>();
        for (String[] ticket : tickets) {
            map.computeIfAbsent(ticket[0], x -> new PriorityQueue()).add(ticket[1]);
        }
    
        List<String> result = new LinkedList();
        Stack<String> stack = new Stack<>();

        stack.push("JFK");

        while (!stack.empty()) {
	        while (map.containsKey(stack.peek()) && !map.get(stack.peek()).isEmpty()) {
                String currentStop = stack.peek();
		        String nextStop = map.get(currentStop).poll();
		        stack.push(nextStop);
	        }
            result.add(0, stack.pop());
        }
        return result; 
    }
}