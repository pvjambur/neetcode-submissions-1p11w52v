import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        // 1️⃣ Frequency map
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // 2️⃣ Buckets: index = frequency
        int n = nums.length;
        List<Integer>[] bucket = new ArrayList[n + 1];

        for (int key : freq.keySet()) {
            int count = freq.get(key);
            if (bucket[count] == null) {
                bucket[count] = new ArrayList<>();
            }
            bucket[count].add(key);
        }

        // 3️⃣ Collect top k frequent elements
        int[] res = new int[k];
        int idx = 0;

        for (int i = n; i >= 0 && idx < k; i--) {
            if (bucket[i] != null) {
                for (int num : bucket[i]) {
                    res[idx++] = num;
                    if (idx == k) break;
                }
            }
        }

        return res;
    }
}
