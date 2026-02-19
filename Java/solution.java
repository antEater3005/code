import java.util.Arrays;

class Solution {

    // Find the next non overlapping interval
    private int findValAtNextEvent(int[][] events, int target) {
        int left = 0, right = events.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }

    public int maxTwoEvents(int[][] events) {
        int ans = 0;

        Arrays.sort(events, (a, b) -> {
            if (a[0] == b[0])
                return Integer.compare(a[1], b[1]);
            return Integer.compare(a[0], b[0]);
        });

        int[] maxToRight = new int[events.length];
        maxToRight[events.length - 1] = events[events.length - 1][2];
        for (int i = events.length - 2; i >= 0; i--)
            maxToRight[i] = Math.max(maxToRight[i + 1], events[i][2]);

        for (int i = 0; i < events.length; i++) {
            int l = events[i][0], r = events[i][1], val = events[i][2];
            int nextEvent = findValAtNextEvent(events, r);
            if (nextEvent < events.length)
                ans = Math.max(ans, val + maxToRight[nextEvent]);
            ans = Math.max(ans, val);
        }
        return ans;
    }
}