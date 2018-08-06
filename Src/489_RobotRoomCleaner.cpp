/*
Given a robot cleaner in a room modeled as a grid.

Each cell in the grid can be empty or blocked.

The robot cleaner with 4 given APIs can move forward, turn left or turn right.
Each turn it made is 90 degrees.

When it tries to move into a blocked cell, its bumper sensor detects the obstacle
and it stays on the current cell.

Design an algorithm to clean the entire room using only the 4 given APIs shown below.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
Example:

Input:
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3

Explanation:
All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.
Notes:

The input is only given to initialize the room and the robot's position internally.
You must solve this problem "blindfolded". In other words, you must control the
robot using only the mentioned 4 APIs, without knowing the room layout and the
initial robot's position.
The robot's initial position will always be in an accessible cell.
The initial direction of the robot will be facing up.
All accessible cells are connected, which means the all cells marked as 1 will be
accessible by the robot.
Assume all four edges of the grid are all surrounded by wall.
*/

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

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class Solution {
public:
    void cleanRoom(Robot& robot) {
        _DFS(robot, 0, 0);
        return;
    }

    void _DFS(Robot& robot, int row, int col){

        if(visited.find({row, col}) != visited.end())
            return;

        robot.clean();
        visited.insert({row, col});

        if(moveUp(robot)){
            _DFS(robot, row, col+1);
            moveDown(robot);
        }

        if(moveDown(robot)){
            _DFS(robot, row, col-1);
            moveUp(robot);
        }

        if(moveLeft(robot)){
            _DFS(robot, row-1, col);
            moveRight(robot);
        }

        if(moveRight(robot)){
            _DFS(robot, row+1, col);
            moveLeft(robot);
        }
        return;

    }

    bool moveUp(Robot& robot){
        return robot.move();
    }

    bool moveLeft(Robot& robot){
        robot.turnLeft();
        bool ret = robot.move();
        robot.turnRight();
        return ret;
    }

    bool moveDown(Robot& robot){
        robot.turnLeft();
        robot.turnLeft();
        bool ret = robot.move();
        robot.turnRight();
        robot.turnRight();
        return ret;
    }

    bool moveRight(Robot& robot){
        robot.turnRight();
        bool ret = robot.move();
        robot.turnLeft();
        return ret;
    }

private:
    unordered_set<pair<int, int>, pairhash> visited;

};

// clean solution

class Solution {
public:
    void cleanRoom(Robot& robot) {

        dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        idx = 0;
        _DFS(robot, 0, 0);
        return;
    }

    void _DFS(Robot& robot, int row, int col){

        robot.clean();
        visited.insert({row, col});

        for(int i = 0; i < 4; i++){
            int row_nxt = row + dir[idx][0];
            int col_nxt = col + dir[idx][1];
            auto it = visited.find({row_nxt, col_nxt});
            if( it == visited.end() && robot.move()){
                _DFS(robot, row_nxt, col_nxt);
                moveBack(robot);
            }
            robot.turnRight();
            idx = (idx+1)%4;
        }
        return;
    }

    void moveBack(Robot& robot){
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnRight();
        robot.turnRight();
        return;
    }

private:
    set<pair<int, int>> visited;
    vector<vector<int>> dir;
    int idx;
};
