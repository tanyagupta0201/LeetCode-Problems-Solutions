// Name : Kshitij Barnwal
// Date : 27/10/2022

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;


class Solution {
    public int openLock(String[] deadends, String target) {
        HashSet<String> dead = new HashSet(Arrays.asList(deadends));
        
        HashSet<String> visited = new HashSet();
        visited.add("0000");
        
        Queue<String> queue = new LinkedList();
        queue.offer("0000");
        
        int level=0;
        
        while(!queue.isEmpty()){
            int size=queue.size();
            while(size>0){
                String lock_pos=queue.poll();
                if(dead.contains(lock_pos)){
                    size--;
                    continue;
                }
                if(lock_pos.equals(target)){
                    return level;
                }
                StringBuilder sb = new StringBuilder(lock_pos);
                for(int i=0;i<4;i++){
                    char curr_pos=sb.charAt(i);
                    String s1=sb.substring(0,i)+(curr_pos == '9'? 0 : curr_pos - '0'+1)+sb.substring(i+1);
                    String s2=sb.substring(0,i)+(curr_pos == '0'? 9 : curr_pos - '0'-1)+sb.substring(i+1);
                    if(!visited.contains(s1) && !dead.contains(s1)){
                        queue.offer(s1);
                        visited.add(s1);
                    }
                    if(!visited.contains(s2) && !dead.contains(s2)){
                        queue.offer(s2);
                        visited.add(s2);
                    }
                } 
                size--;
            }
            level++;
        }
        return -1;
    }
}