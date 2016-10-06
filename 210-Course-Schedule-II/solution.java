public class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        List<Integer>[] graph = buildGraph(numCourses, prerequisites, indegree);
        int[] result = new int[numCourses];
        int pos = numCourses;
        
        Queue<Integer> queue = new LinkedList<Integer>();
        
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (indegree[j] == 0) {
                    break;
                }
            }
            if (j == numCourses) {
                return new int[0];
            }
            
            indegree[j] = -1;
            List<Integer> list = graph[j];
            result[--pos] = j;
            if (list != null) {
                for (int k : list) {
                    --indegree[k];
                }
            }
        }
        return result;
    }
    
    private List<Integer>[] buildGraph(int numCourses, int[][] prerequisites, int[] indegree){
        List<Integer>[] graph = new ArrayList[numCourses];
        for (int[] pair: prerequisites) {
            int index = pair[0];
            List<Integer> list = graph[index];
            if (list == null) {
                list = new ArrayList();
                graph[index] = list;
            }
            list.add(pair[1]);
            indegree[pair[1]]++;
        }
        return graph;
    }
}