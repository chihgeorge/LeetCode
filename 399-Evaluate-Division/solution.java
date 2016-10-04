public class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        Map<String, Map<String, Double>> numberMap = new HashMap();
        for(int i = 0; i < equations.length; i++){
            addPairs(numberMap, equations[i][0], equations[i][1], values[i]);
            addPairs(numberMap, equations[i][1], equations[i][0], 1.0/values[i]);
        }
        
        double[] result = new double[queries.length];
        
        for(int i = 0; i < queries.length; i++){
            Double res = findPairs(numberMap, queries[i][0], queries[i][1], new HashSet<>());
            if(res != null){
                result[i] = res;
            }else{
                result[i] = -1.0;
            }
        }
        
        return result;
    }
    
    private void addPairs(Map<String, Map<String, Double>> numberMap, String num1, String num2, Double value){
        Map<String, Double> pairMap = numberMap.get(num1);
        if(pairMap == null) {
            pairMap = new HashMap<>();
            numberMap.put(num1, pairMap);
        }
        pairMap.put(num2, value);
    }
    
    private Double findPairs(Map<String, Map<String, Double>> numberMap, String num1, String num2, Set<String> visited){
        String pairKey = num1 + "," + num2;
        if(visited.contains(pairKey)){
            return null;
        }else if(!numberMap.containsKey(num1) || (!numberMap.containsKey(num2))){
            return null;
        }else if(num1.equals(num2)){
            return 1.0;
        }
        
        Map<String, Double> pairMap = numberMap.get(num1);
        visited.add(pairKey);
        for(String key : pairMap.keySet()) {
            Double result = findPairs(numberMap, key, num2, visited);
            if(result != null) {
                return result * pairMap.get(key);
            }
        }
        visited.remove(pairKey);
        return null;
    }
}