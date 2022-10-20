// Author: Shivani
// Date: 20/10/2022

// link to the question
// https://leetcode.com/problems/course-schedule-iii/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // soring according to lastday in increasing order
        sort(courses.begin(), courses.end(), [&](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        
        // priority queue to store duration of courses
        priority_queue<int> pq;
        int time = 0; // time to store the total time taken
        
        for(int i=0; i<courses.size(); i++){

            // adding course time to total time and pushing in the priority queue
            time += courses[i][0];
            pq.push(courses[i][0]);
            
            // if total time taken including this course is greater than the last day then subtract the course with 
            // biggest duration (which is on the top of priority queue) and pop that course from priority queue
            if(time > courses[i][1]){
                time -= pq.top();
                pq.pop();
            }
        }
        
        // as queue only contains the courses taken so size of queue is the number of courses which is our answer
        return pq.size();
    }
};