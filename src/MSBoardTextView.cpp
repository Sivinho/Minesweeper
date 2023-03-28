#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"
#include <iostream>

MSBoardTextView::MSBoardTextView(MinesweeperBoard const & board): dowyswietlenia(board)
{}
void MSBoardTextView::display() const
{
    for(int i = 0;i<dowyswietlenia.getBoardHeight();i++)
    {
        for(int j = 0;j<dowyswietlenia.getBoardWidth();j++)
        {
            std::cout<<"["<<dowyswietlenia.getFieldInfo(i,j)<<"]";
        }
        std::cout<<std::endl;
    }
};
