#pragma once
class MSBoardTextView
{
public:
    MSBoardTextView(MinesweeperBoard const & board);
    void display() const;
private:
    MinesweeperBoard const & dowyswietlenia;

};