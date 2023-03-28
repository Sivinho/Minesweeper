#pragma once
class MSTextController
{
private:
    MinesweeperBoard & wprowadzenie;
    MSBoardTextView & widok_planszy;
public:
    MSTextController(MinesweeperBoard & board,MSBoardTextView & view);
    void play();
};
