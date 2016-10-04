public class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        Map<String, Map<String, double>> numberMap = new HashMap();
        int i = 0;
        for(String[] pair: equations){
            addPairs(numberMap, pair[0], pair[1], values[i]);
            addPairs(numberMap, pair[1], pair[0], 1.0/values[i]);
        }
        
        double[] result = new double[queries.length];
        i = 0;
        
        for(String[] pair: queries){
            double res = findPairs(numberMap, pair[0], pair[1], new HashSet<>());
            if(res == null){
                result[i++] = -1.0;
            }else{
                result[i++] = res;
            }
        }
    }
    
    private void addPairs(Map<String, Map<String, Double>> numberMap, String num1, String num2, double value){
        Map<String, double> pairMap = numberMap.get(num1);
        if(pairMap == null) {
            pairMap = new HashMap<>();
            numberMap.put(num1, pairMap);
        }
        pairMap.put(num2, value);
    }
    
    private double findPairs(Map<String, Map<String, Double>> numberMap, String num1, String num2, Set<String> visited){
        String pairKey = num1 + "," + num2;
        if(visited.contains(pairKey)){
            return null;
        }else if(!numberMap.containsKey(num1) || (!numberMap.containsKey(num2))){
            return null;
        }else if(num1 == num2){
            return 1.0;
        }
        
        Map<String, Double> pairMap = numMap.get(num1);
        visited.add(pairKey);
        for(String key : pairMap.keySet()) {
            double result = findPairs(numberMap, key, num2, visited);
            if(result != null) {
                return result * pairMap.get(key);
            }
        }
        visited.remove(pairKey);
        return null;
    }
}