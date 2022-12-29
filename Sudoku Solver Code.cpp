/*  Rajat Rathi  */
#include<bits/stdc++.h>
using namespace std;

bool success=false;
vector<vector<int>> grid(9,vector<int> (9)),ans(9,vector<int>(9));

bool row_check(int x,int num)
{
    for(int col=0;col<9;col++)
    {
        if(grid[x][col]==num)
            return false;
    }
    return true;
}

bool col_check(int y,int num)
{
    for(int row=0;row<9;row++)
    {
        if(grid[row][y]==num)
            return false;
    }
    return true;
}

bool box_check(int row,int col,int num)
{
    for(int i=row;i<row+3;i++)
    {
        for(int j=col;j<col+3;j++)
        {
            if(grid[i][j]==num)
                return false;
        }
    }
    return true;
}

void sudoku_solver(int x,int y)
{
    if(x==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                ans[i][j]=grid[i][j];
            }
        }
        success=true;
        return;
    }

    if(grid[x][y]!=0)
    {
        if(y==8)
        {
            x++;
            y=0;
        }
        else
        {
            y++;
        }
        sudoku_solver(x,y);
        if(success)
            return;
    }
    else
    {
        for(int num=1;num<=9;num++)
        {
            int row=(x/3)*3,col=(y/3)*3;
            if(row_check(x,num) && col_check(y,num) && box_check(row,col,num))
            {
                grid[x][y]=num;
                int newx=x,newy=y;

                if(y==8)
                {
                    newx++;
                    newy=0;
                }
                else
                {
                    newy++;
                }
                sudoku_solver(newx,newy);
                if(success)
                    return;
                grid[x][y]=0;
            }
        }
    }
}

void print(vector<vector<int>> ans)
{
    cout << "Here is the solution to the sudoku: " << endl << endl;
    
	for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    cout << "/**************************Sudoku-Solver**************************/" << endl << endl;
    cout << "Enter the grid (0 for blank spaces):- " << endl;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];
        }
    }
  	
  	cout << endl << endl;
    sudoku_solver(0,0);
    print(ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}

