class Solution {
    public int minNumberOperations(int[] target) {
        Stack<Integer> st = new Stack<>();
        boolean down = false;
        int max_val = Integer.MIN_VALUE;
        int res = 0;
        int min_s = 0;
        for (int x: target){
            if (st.empty()) st.push(x);
            else{
                int temp = st.peek();
                if (temp<x && down==true){
                    res += (max_val - min_s);
                    min_s = temp;
                    max_val = x;
                    st.clear();
                    st.push(x);
                    down = false;
                }
                else if (temp>=x){
                    down = true;
                    st.push(x);
                }
                else{
                    st.push(x);
                }
            }
            max_val = Math.max(max_val,x);

        }
        res += (max_val - min_s);
        return res;
    }
}