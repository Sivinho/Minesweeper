#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"
#include "MSTextController.hpp"
#include <time.h>
#include <cstdlib>

int main()
{
    srand(time(NULL));
    MinesweeperBoard plansza(10,5,GameMode::HARD);
    MSBoardTextView view(plansza);
    MSTextController ctrl{plansza, view};
    ctrl.play();
    return 0;
}