//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

//Definition for a point.
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
  public:
    int maxPoints(vector<Point> &points) {
      double a, b;
      bool flag;
      int max_num = 0, same_points, temp;
      int i, j;
      for (i = 0; i < points.size(); ++i) {
        map<float, int> num_map; // key : 斜率, value : 点个数
        int yline = 0; // x 相同的直线点个数
        same_points = 1;
        temp = 0;
        for (j = i + 1; j < points.size(); ++j) {
          if (points[i].x != points[j].x) {
            a = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
            if (num_map.find(a) != num_map.end()) {
              num_map[a] +=1;
            } else {
              num_map[a] = 1;
            }
            if (num_map[a] > temp) {
              temp = num_map[a];
            }
            //printf("num map[%f] : %d\n", a, num_map[a]);
            // 需要注意相同的点
          } else if (points[j].y == points[i].y) {
            ++same_points;
            //printf("same poinsts num : %d\n", same_points);
          } else {
            ++yline;
            if (yline > temp) {
              temp = yline;
            }
          }
        }
        if (temp + same_points > max_num) {
          max_num = temp + same_points;
          //printf("max num : %d+%d=%d\n", temp, same_points, max_num);
        }
      }
      return max_num;
    }
};
int main() {
  Solution s;
  vector<Point> points;
  points.push_back(Point(1,2));
  points.push_back(Point(1,2));
  points.push_back(Point(1,2));
  points.push_back(Point(2,4));
  points.push_back(Point(3,2));
  points.push_back(Point(6,2));
  points.push_back(Point(6,7));
  points.push_back(Point(1,20));
  int max = s.maxPoints(points);
  printf("max num : %d\n", max);
  return 0;
}
