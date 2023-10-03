// Name : Kshitij Barnwal
// Date : 27/10/2022

import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int openLock(String[] deadends, String target) {
        // use HashSet to track deadends and visited combination
        HashSet<String> dead = new HashSet(Arrays.asList(deadends));

        // Store visited nodes using HashSet
        HashSet<String> visited = new HashSet();
        visited.add("0000");

        // Start from '0000'
        Queue<String> queue = new LinkedList();
        queue.offer("0000");

        int level = 0; // Initial value of level is 0

        // Using while until queue is not empty
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size > 0) { // Loop until size is greater than 0
                String lock_pos = queue.poll(); // Returns and removes first element from queue
                if (dead.contains(lock_pos)) { // If current lock positions are present in deadends
                    size--; // Decrease size
                    continue; // Skip loop
                }

                // Current lock position == target then return level
                if (lock_pos.equals(target)) {
                    return level;
                }
                StringBuilder sb = new StringBuilder(lock_pos);

                // add current node's children to the queue
                // each wheel can be turn up and down
                // for each wheel
                for (int i = 0; i < 4; i++) {
                    char curr_pos = sb.charAt(i);
                    String s1 = sb.substring(0, i) + (curr_pos == '9' ? 0 : curr_pos - '0' + 1) + sb.substring(i + 1);
                    String s2 = sb.substring(0, i) + (curr_pos == '0' ? 9 : curr_pos - '0' - 1) + sb.substring(i + 1);

                    // if s1 is not visited and not present in deadends too then only added in queue
                    if (!visited.contains(s1) && !dead.contains(s1)) {
                        queue.offer(s1);
                        visited.add(s1);
                    }

                    // if s2 is not visited and not present in deadends too then only added in queue
                    if (!visited.contains(s2) && !dead.contains(s2)) {
                        queue.offer(s2);
                        visited.add(s2);
                    }
                }
                size--;
            }
            level++; // Increment level to return answer
        }
        return -1;
    }
}