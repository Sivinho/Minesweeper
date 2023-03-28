#include "MinesweeperBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>



void MinesweeperBoard::generatemines(float per)
{
    int k=0;
    int mines=round(width*height*per);
    while(k<mines)
    {
        int a=rand()%height;
        int b=rand()%width;
        if(board[a][b].hasMine!=1)
        {
            board[a][b].hasMine = 1;
            k++;
        }
    }

}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode):width(width),height(height)
{
    board.reserve(height);
    for (int i = 0; i < height; i++)
    {
        std::vector<Field> temp;
        temp.reserve(width);
        for (int j = 0; j < width; j++)
        {
            Field tmp{0,0,0};
            temp.push_back(tmp);
        }
        board.push_back(temp);
    }
    if(mode==GameMode::EASY)
    {
        this->generatemines(0.1);

    }
    else if(mode==GameMode::NORMAL)
    {
        this->generatemines(0.2);
    }
    else if(mode==GameMode::HARD)
    {
        this->generatemines(0.3);
    }
    else
    {
        for(int i =0;i<width;i++)
        {
            board[0][i].hasMine= true;
        }
        for(int i=1;i<std::min(width,height);i++)
        {
            board[i][i].hasMine= true;
        }
        for(int i=2;i<=((height-1)-(height-1)%2);i+=2)
        {
            board[i][0].hasMine= true;
        }
    }
}

void MinesweeperBoard::debug_display() const
{
    ;
    for(int i = 0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            if(board[i][j].hasMine==0)
            {
                std::cout<<"[.";
            }
            else
            {
                std::cout<<"[M";
            }
            if(board[i][j].isRevealed==0)
            {
                std::cout<<".";
            }
            else
            {
                std::cout<<"o";
            }
            if(board[i][j].hasFlag==0)
            {
                std::cout<<".]";
            }
            else
            {
                std::cout<<"f]";
            }
        }
        std::cout<<std::endl;
    }
}

int MinesweeperBoard::getBoardWidth() const
{
    return width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return height;
}

int MinesweeperBoard::getMineCount() const
{
    int count=0;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(board[i][j].hasMine==1)
            {
                count++;
            }
        }
    }
    return count;

}

int MinesweeperBoard::countMines(int row, int col) const
{
    if((col>width-1 || col<0) || (row > height-1 || row<0))
    {
        return -1;
    }
    else if(board[row][col].isRevealed==0)
    {
        return -1;
    }
    else
    {
        int suma_min=0;
        for(int i =col-1;i<col+2;i++)
        {
            if((row-1>-1 && i>-1 && i<width)&&board[row-1][i].hasMine)
            {
                suma_min++;
            }
        }
        for(int i =col-1;i<col+2;i++)
        {
            if((row+1<height && i>-1 && i<width) && board[row+1][i].hasMine)
            {
                suma_min++;
            }
        }
        for(int i =col-1;i<col+2;i=i+2)
        {
            if((i>-1 && i<width)&&board[row][i].hasMine)
            {
                suma_min++;
            }
        }
        return suma_min;
    }
}

bool MinesweeperBoard::hasFlag(int row, int col) const
{
    if((col>width-1 || col<0) || (row > height-1 || row<0))
    {
        return false;
    }
    else if(board[row][col].hasFlag==0 || board[row][col].isRevealed==1)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void MinesweeperBoard::toggleFlag(int row, int col)
{
    if((col>width-1 || col<0) || (row > height-1 || row<0))
        ;
    else if(board[row][col].isRevealed==1||getGameState()!=GameState::RUNNING)
        ;
    else if(board[row][col].isRevealed==0)
    {
        if(board[row][col].hasFlag)
        board[row][col].hasFlag=false;
        else
        board[row][col].hasFlag=true;
    }
}

void MinesweeperBoard::revealField(int row, int col)
{
    if((col>width-1 || col<0) || (row > height-1 || row<0));
    else if(board[row][col].isRevealed==true||board[row][col].hasFlag==true||getGameState()!=GameState::RUNNING) ;
    else if(board[row][col].isRevealed==false && board[row][col].hasMine==false)
    {
        board[row][col].isRevealed=true;
    }
    else
    {
        board[row][col].isRevealed=true;
    }
}

bool MinesweeperBoard::isRevealed(int row, int col) const
{
    if((col>width-1 || col<0) || (row > height-1 || row<0))
    {
        return false;
    }
    else
    {
        return board[row][col].isRevealed;
    }
}

GameState MinesweeperBoard::getGameState() const
{
    int revealed {};
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(board[i][j].isRevealed==true && board[i][j].hasMine==true)
            {
                std::cout<<"Koniec gry - przegrales!! ;("<<std::endl;
                return GameState::FINISHED_LOSS;
            }
            else if(board[i][j].isRevealed==true)
            {
                revealed++;
            }
        }
    }
    if(revealed==width*height-getMineCount())
    {
        std::cout<<"Koniec gry - wygrales!!"<<std::endl;
        return GameState::FINISHED_WIN;
    }
    else
    {
        return GameState::RUNNING;
    }

}

char MinesweeperBoard::getFieldInfo(int row, int col) const
{
    if(((col>width-1 || col<0) || (row > height-1 || row<0)))
    {
        return '#';
    }
    else if(board[row][col].isRevealed==false && board[row][col].hasFlag==true)
    {
        return 'F';
    }
    else if(board[row][col].isRevealed==false && board[row][col].hasFlag!=true)
    {
        return '_';
    }
    else if(board[row][col].isRevealed==true && board[row][col].hasMine==true)
    {
        return 'x';
    }
    else if(board[row][col].isRevealed==true && countMines(row,col)==0)
    {
        return ' ';
    }
    else
    {
        int a=countMines(row,col);
        char b=a+48;
        return b;
    }
}