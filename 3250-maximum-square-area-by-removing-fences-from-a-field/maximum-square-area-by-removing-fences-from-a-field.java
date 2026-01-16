import java.util.*;

class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        long mod = 1_000_000_007;
        
        // 1. Get all horizontal positions including boundaries 1 and m
        int[] h = Arrays.copyOf(hFences, hFences.length + 2);
        h[h.length - 2] = 1;
        h[h.length - 1] = m;
        Arrays.sort(h);
        
        // 2. Get all vertical positions including boundaries 1 and n
        int[] v = Arrays.copyOf(vFences, vFences.length + 2);
        v[v.length - 2] = 1;
        v[v.length - 1] = n;
        Arrays.sort(v);
        
        // 3. Store all possible horizontal gaps in a HashSet
        Set<Integer> hGaps = new HashSet<>();
        for (int i = 0; i < h.length; i++) {
            for (int j = i + 1; j < h.length; j++) {
                hGaps.add(h[j] - h[i]);
            }
        }
        
        // 4. Find the largest gap that also exists in the vertical lines
        long maxSide = -1;
        for (int i = 0; i < v.length; i++) {
            for (int j = i + 1; j < v.length; j++) {
                int gap = v[j] - v[i];
                if (hGaps.contains(gap)) {
                    maxSide = Math.max(maxSide, gap);
                }
            }
        }
        
        // 5. Return -1 if no square found, otherwise return area % mod
        if (maxSide == -1) return -1;
        return (int) ((maxSide * maxSide) % mod);
    }
}