class Solution {
public:
    struct Node{
        int pos;
        int health;
        int dir;
        int i;
    };
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<Node> robots;
        for (int i = 0 ; i < positions.size() ; ++i) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end(), [](const Node& a, const Node& b) {
            return a.pos < b.pos;
        });
        
        vector<Node> stack;
        for (auto &robot : robots) {
            if (robot.dir == 'R') {
                stack.push_back(robot);
                continue;
            }

            bool gone = false;

            while (!stack.empty() && stack.back().health <= robot.health && stack.back().dir == 'R') {
                if (stack.back().health == robot.health) {
                    stack.pop_back();
                    gone = true;
                    break;
                }
                robot.health--;
                stack.pop_back();
            }

            if (!gone && !stack.empty() && stack.back().dir == 'R' && stack.back().health > robot.health) {
                stack.back().health--;
                gone = true;
            }

            if (!gone) {
                stack.push_back(robot);
            }
        }

        sort(stack.begin(), stack.end(), [](const Node& a, const Node& b) {
            return a.i < b.i;
        });

        vector<int> result;
        for (const auto& robot : stack) {
            result.push_back(robot.health);
        }

        return result;
    }
};