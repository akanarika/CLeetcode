/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 */

// @lc code=start
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        //    0
        //    ^
        // 3<   > 1
        //    v 
        //    2
        dfs(robot, 0, 0, 0, visited);
    }

    void dfs(Robot& robot, int r, int x, int y, unordered_set<string>& visited) {
        string s = to_string(x) + "," + to_string(y);
        if (visited.find(s) != visited.end()) return;
        robot.clean();
        visited.insert(s);
        for (int i = 0; i < 4; i++) {
            int xx = x, yy = y;
            if (robot.move()) {
                switch(r) {
                    case 0:
                        yy--;
                        break;
                    case 1:
                        xx++;
                        break;
                    case 2:
                        yy++;
                        break;
                    case 3:
                        xx--;
                        break;
                }
                dfs(robot, r, xx, yy, visited);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
            r = (r + 1) % 4;
        }
    }
};
// @lc code=end
