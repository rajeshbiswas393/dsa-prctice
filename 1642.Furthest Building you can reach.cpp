/*
1642. Furthest Building You Can Reach
Leet Code

You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

    If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
    If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.

Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.

*/

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int i=0;
        for( i=0;i<heights.size()-1;i++)
        {
            int diff=heights[i+1]-heights[i];
            if(diff<0)continue;
            bricks-=diff;
            pq.push(diff);
            if(bricks<0)
            {
                bricks+=pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders<0)break;
        }
        return i;
    }
};
