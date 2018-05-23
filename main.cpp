#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print (vector<vector<int>> visited, vector<vector<char>> maze);


int solve_maze(vector<vector<char>> maze, int n, int m)
{

    vector<vector<int>> visited;
    visited.resize(n);

    for (int i = 0; i < n; i++) {      // initialize the visited array. make -10 those cells with # (i.e. walls)
        visited[i].resize(m);
        for (int j = 0; j < m; j++)	   // so we would not step on them. 
        {
            // -1 stands for "not visited"
            visited[i][j] = maze[i][j] == '.' ? -1 : -10;
        }
    }



    queue <pair<int,int>> list;
    pair<int,int> start;
    start= make_pair(0,0);

    visited[start.first][start.second] = 0; // make the first element visited

    list.push(start);

    while (!list.empty()) {
        pair<int,int> current = list.front();
        list.pop();

        if(current.second-1 > -1 && visited[current.first][current.second-1]==-1){ //check the left neighbor
            visited[current.first][current.second-1] = visited[current.first][current.second]+1;
            list.push(make_pair(current.first,current.second-1));
        }

        if(current.second+1 < m && visited[current.first][current.second+1]==-1) { //check the right neighbor
            visited[current.first][current.second+1] = visited[current.first][current.second]+1;
            list.push(make_pair(current.first,current.second+1));
        }

        if(current.first-1 > -1 && visited[current.first-1][current.second]==-1){ //check the up neighbor
            visited[current.first-1][current.second] = visited[current.first][current.second]+1;
            list.push(make_pair(current.first-1,current.second));
        }

        if(current.first+1 < n && visited[current.first+1][current.second]==-1){ //check the down neighbor
            visited[current.first+1][current.second] = visited[current.first][current.second]+1;
            list.push(make_pair(current.first+1,current.second));
        }
    }
    print(visited, maze);
}


void print (vector<vector<int>> visited, vector<vector<char>> maze){
    int n = visited.size();
    int m = visited[0].size();
    int last = visited[n-1][m-1];
    maze[n-1][m-1] = 'x';

    for(int i = n - 1; i > -1; --i)
        for(int j = m - 1; j > -1; --j){
            if(j-1>-1 && visited[i][j-1]==last-1) {
                maze[i][j-1] = 'x';
                last--;
            }
            else if(j+1< m && visited[i][j+1]==last-1) {
                maze[i][j+1] = 'x';
                last--;
            }
            else if(i-1>-1 && visited[i-1][j]==last-1) {
                maze[i-1][j] = 'x';
                last--;
            }
            else if(i+1<n && visited[i+1][j]==last-1) {
                maze[i+1][j] = 'x';
                last--;
            }

        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }


}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> mymaze;
    mymaze.resize(n);
    for (int i = 0; i < n; ++i)
        mymaze[i].resize(m);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin>>mymaze[i][j];

    solve_maze(mymaze,n,m);
    return 0;
}



/*
6 9
..#....##
#...##.##
##.#....#
#..######
#.......#
######...

*/