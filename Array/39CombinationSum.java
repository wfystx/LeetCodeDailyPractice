class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        helper(res, new ArrayList<Integer>(), candidates, target, 0);
        return res;
    }
    public void helper(List<List<Integer>> res, List<Integer> temp, int candidates[], int target, int start){
        if(target>0){
            for(int i=start; i<candidates.length && target>=candidates[i]; i++){
                temp.add(candidates[i]);
                helper(res, temp, candidates, target-candidates[i], i);
                temp.remove(temp.size()-1);
            }
        }else if(target==0) res.add(new ArrayList<Integer>(temp));
        
    }
}