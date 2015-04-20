#include<simplecpp>
#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);

// assign values to all unassigned locations for Sudoku solution

bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

// Searches the grid to find an entry that is still unassigned.
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

// Returns whether any assigned entry n the specified row matches the given number.
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

//Returns whether any assigned entry in the specified column matches the given number
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

//Returns whether any assigned entry within the specified 3x3 box matches the given number.
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

//Returns whether it will be legal to assign num to the given row,col location.

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}

bool validSudoku(int grid[N][N])
{
    bool valid = true;
    for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
            {
                if(grid[i][j] == 0)
                    continue;

                for (int col = 0; col < 9; col++)
                    {
                    if (grid[i][col] == grid[i][j] && col!=j)
                        {
                        valid = false;
                        break;
                        }
                    }

                for (int row = 0; row < 9; row++)
                    {
                    if (grid[row][j] == grid[i][j] && row!=i)
                        {
                        valid = false;
                        break;
                        }
                    }

                int boxStartRow = i - i % 3;
                int boxStartCol = j - j % 3;
                for (int row = 0; row < 3; row++)
                    for (int col = 0; col < 3; col++)
                        if (grid[row + boxStartRow][col + boxStartCol] == grid[i][j] && (row+boxStartRow)!=i && (col + boxStartCol)!=j )
                            {
                            valid = false;
                            break;
                            }
            }
        }
    return valid;
}

//print grid
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<<grid[col][row]<<"  ";
        cout<<endl;
    }
}

main_program
{
    int sudoku[9][9];
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            sudoku[i][j]=0;
        }
    }
//basic lines and texts
    initCanvas("made by group",1000,700);
    Rectangle r1(500,25,500,50);
    Rectangle r2(425,325,450,450);
    Rectangle r3(775,325,50,450);
    Rectangle r4(500,625,200,50);
    Rectangle r5(775,575,50,50);
    Line v1(250,100,250,550);
    Line v2(300,100,300,550);
    Line v3(350,100,350,550);
    Line v3d(352,100,352,550);
    Line v4(400,100,400,550);
    Line v5(450,100,450,550);
    Line v6(500,100,500,550);
    Line v6d(502,100,502,550);
    Line v7(550,100,550,550);
    Line v8(600,100,600,550);
    Line h1(200,150,650,150);
    Line h3(200,200,650,200);
    Line h3d(200,252,650,252);
    Line h4(200,250,650,250);
    Line h5(200,300,650,300);
    Line h6(200,350,650,350);
    Line h6d(200,402,650,402);
    Line h7(200,400,650,400);
    Line h8(200,450,650,450);
    Line h2(200,500,650,500);
    Line d1(750,150,800,150);
    Line d2(750,200,800,200);
    Line d3(750,250,800,250);
    Line d4(750,300,800,300);
    Line d5(750,350,800,350);
    Line d6(750,400,800,400);
    Line d7(750,450,800,450);
    Line d8(750,500,800,500);
    Text t1(775,125,"1");
    Text t2(775,175,"2");
    Text t3(775,225,"3");
    Text t4(775,275,"4");
    Text t5(775,325,"5");
    Text t6(775,375,"6");
    Text t7(775,425,"7");
    Text t8(775,475,"8");
    Text t9(775,525,"9");
    Text clr(775,575,"clear");
    Text solve(500,625,"Solve");
    Text head(500,25,"Sudoku Autosolver");

    bool to_solve = 0;
    do
    {

        int click1,x1,y1,value=0;
        while(true)
        {
            click1=getClick();
            x1=click1/65536;
            y1=click1%65536;
            cout<<x1<<","<<y1<<endl;
            if(x1>750&&x1<800&&y1>100&&y1<600)
            {
                cout<<"yes";
                switch((y1-50)/50)
                {
                case 1:
                    value =1;
                    break;
                case 2:
                    value =2;
                    break;
                case 3:
                    value =3;
                    break;
                case 4:
                    value =4;
                    break;
                case 5:
                    value =5;
                    break;
                case 6:
                    value =6;
                    break;
                case 7:
                    value =7;
                    break;
                case 8:
                    value =8;
                    break;
                case 9:
                    value =9;
                    break;
                case 10:
                    value =0;
                }
                break;
            }
            if(x1>400&&x1<600&&y1>600&&y1<650)
            {
                int count=0;
                for(int i=0; i<9; i++)
                {
                    for(int j=0; j<9; j++)
                    {
                        if(sudoku[i][j] != 0)
                            count++;
                    }
                }

                char choice;
                if(count<17)
                {
                    cout<<"To obtain a unique solution at least 17 values are needed.";
                    cout<<"\n Current number of values = "<<count;
                    cout<<"\n Would you like to continue with "<<count<<" number of values ... press (y/n)";
                    cin>>choice;

                    if(choice == 'y')
                    {
                        to_solve = 1;
                    }
                    // else by default not solved
                }
                else
                {
                    cout<<"\n Only a unique solution exists and it is: \n \n";
                    to_solve = 1;
                }

                break;
            }
        }
        cout<<value;

        if(to_solve == 1)
        {
            break;
        }


        int click2,x2,y2,i,j,cx,cy;
        while(true)
        {
            click2=getClick();
            x2=click2/65536;
            y2=click2%65536;
            i=(x2-150)/50 - 1;
            j=(y2-50)/50 - 1;
            cx=x2/50*50+25;
            cy=y2/50*50+25;
            if(x2>200&&x2<650&&y2>100&&y2<550)
            {
                sudoku[i][j]=value;
                cout<<sudoku[i][j];
                if(value==1)
                {
                    Text b1(cx,cy,"1");
                    b1.imprint();
                }
                else if(value==2)
                {
                    Text b2(cx,cy,"2");
                    b2.imprint();
                }
                else if(value==3)
                {
                    Text b3(cx,cy,"3");
                    b3.imprint();
                }
                else if(value==4)
                {
                    Text b4(cx,cy,"4");
                    b4.imprint();
                }
                else if(value==5)
                {
                    Text b5(cx,cy,"5");
                    b5.imprint();
                }
                else if(value==6)
                {
                    Text b6(cx,cy,"6");
                    b6.imprint();
                }
                else if(value==7)
                {
                    Text b7(cx,cy,"7");
                    b7.imprint();
                }
                else if(value==8)
                {
                    Text b8(cx,cy,"8");
                    b8.imprint();
                }
                else if(value==9)
                {
                    Text b9(cx,cy,"9");
                    b9.imprint();
                }
                else if(value==0)
                {
                    Text b10(cx,cy,"  ");
                    b10.imprint();
                }
                break;
            }

        }
    }
    while(!to_solve);

    cout<<"\n Sudoku state: \n \n";
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cout<<sudoku[j][i]<<" ";
        }
        cout<<"\n";
    }

    cout<<"Solving ... \n \n";

    if(validSudoku(sudoku) == false)
        cout<<"No solution exists"<<endl;
    else
    {
        if (SolveSudoku(sudoku) == true)
        {
            printGrid(sudoku);

            for(int i=0; i<9; i++)
            {
                for(int j=0; j<9; j++)
                {
                    int cx,cy,value;
                    cx = 225 + i*50;
                    cy = 125 + j*50;
                    value = sudoku[i][j];
                    if(value==1)
                    {
                        Text b1(cx,cy,"1");
                        b1.imprint();
                    }
                    else if(value==2)
                    {
                        Text b2(cx,cy,"2");
                        b2.imprint();
                    }
                    else if(value==3)
                    {
                        Text b3(cx,cy,"3");
                        b3.imprint();
                    }
                    else if(value==4)
                    {
                        Text b4(cx,cy,"4");
                        b4.imprint();
                    }
                    else if(value==5)
                    {
                        Text b5(cx,cy,"5");
                        b5.imprint();
                    }
                    else if(value==6)
                    {
                        Text b6(cx,cy,"6");
                        b6.imprint();
                    }
                    else if(value==7)
                    {
                        Text b7(cx,cy,"7");
                        b7.imprint();
                    }
                    else if(value==8)
                    {
                        Text b8(cx,cy,"8");
                        b8.imprint();
                    }
                    else if(value==9)
                    {
                        Text b9(cx,cy,"9");
                        b9.imprint();
                    }
                }
            }
        }
    }


    wait(15);
}
