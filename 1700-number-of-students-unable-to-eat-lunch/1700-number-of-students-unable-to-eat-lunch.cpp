class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int s : students) q.push(s);
        for (int i = 0 ; i < n ; i++){
            int s = sandwiches[i];
            int cnt = 0;
            int N = q.size();
            while (true){
                if (s == q.front()){
                    q.pop();
                    break;
                }
                else {
                    cnt++;
                    q.push(q.front());
                    q.pop();
                    if (cnt == N) return cnt;
                }
            }
        }
        return q.size();
    }
};