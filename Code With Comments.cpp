/*  Rajat Rathi  */
/***********************************Backtracking Solution********************************/
#include<bits/stdc++.h>
using namespace std;

bool success=false;
vector<vector<int>> grid(9,vector<int> (9)),ans(9,vector<int>(9));

/*row_check function checks whether the number(num) which is to be filled in the cell (x,y) is present
in the row(x) or not. If its present then it returns false else true.
False means that we can not fill the number(num) in the desired cell (x,y) and true means we can 
fill the number(num) in the cell (x,y) if the other two functions col_check and box_check also
returns true.*/
bool row_check(int x,int num)
{
    for(int col=0;col<9;col++)
    {
        if(grid[x][col]==num)
            return false;
    }
    return true;
}

/*col_check function checks whether the number(num) which is to be filled in the cell (x,y) is present
in the column(y) or not. If its present then it returns false else true.
False means that we can not fill the number(num) in the desired cell (x,y) and true means we can 
fill the number(num) in the cell (x,y) if the other two functions row_check and box_check also
returns true.*/
bool col_check(int y,int num)
{
    for(int row=0;row<9;row++)
    {
        if(grid[row][y]==num)
            return false;
    }
    return true;
}

/*box_check function checks whether the number(num) which is to be filled in the cell (x,y) is present
in the small (3*3) box or not. If its present then it returns false else true.
False means that we can not fill the number(num) in the desired cell (x,y) and true means we can 
fill the number(num) in the cell (x,y) if the other two functions row_check and col_check also
returns true.*/
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

/*sudoku_solver generates the solution to the sudoku by backtracking on all the possibilities.*/
void sudoku_solver(int x,int y)
{
	//Base Case to stop recursion.
    if(x==9)//We have correctly filled the sudoku. Now let's store the sudoku in "ans". 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                ans[i][j]=grid[i][j];
            }
        }
        success=true;//We got the solution. Hurray!!
		//Now let's prune unnecessary possibilities. 
        return;
    }

    if(grid[x][y]!=0)//Let's move to the next valid cell.
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
        if(success)//Pruning the backtracking
            return;
    }
    else
    {
    	//Time to check every number which can fit in the cell. However time taking process XD.
        for(int num=1;num<=9;num++)
        {
            int row=(x/3)*3,col=(y/3)*3;//Think.... Getting coordinates of top left corner of the box.
            if(row_check(x,num) && col_check(y,num) && box_check(row,col,num))
            {
                grid[x][y]=num;//Its valid. Let's now place it and solve further.
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
                if(success)//Let's save some time. Pruuuuunnnnnneeeeeeeeeeee.....
                    return;
                grid[x][y]=0;//Returning back to the last stage. Backtracking.
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
  	
  	//sudoku_solver uses backtracking to iterate through all the possibilities and finally finds the solution. 
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


