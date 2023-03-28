#include "MinesweeperBoard.hpp"
#include "MSBoardTextView.hpp"
#include "MSTextController.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>


MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : wprowadzenie(board),widok_planszy(view)
{}

void MSTextController::play()
{
    while(wprowadzenie.getGameState()==GameState::RUNNING)
    {
        std::cout << "MINESWEEPER:" << std::endl;
        widok_planszy.display();
        std::cout << std::endl;
        std::cout << "Co chcesz zrobić? Wybierz:" << std::endl << "1. Odkryj pole" << std::endl
                  << "2. Postaw lub zdejmij flage" << std::endl;
        std::cout << "Podaj cyfre odpowiadającą swojemu wyborowi: ";
        int choice;
        bool t = true;
        while (t) {
            std::cin >> choice;
            while (std::cin.fail() != false) {
                std::cout << std::endl << "Podaj liczbe całkowitą!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Podaj cyfre odpowiadającą swojemu wyborowi: ";
                std::cin >> choice;
            }
            switch (choice) {
                case 1:
                    t = false;
                    int x1, y1;
                    std::cout << "Podaj pole" << std::endl;
                    std::cout << "Podaj numer wiersza licząc od jedynki:";
                    std::cin >> x1;
                    std::cout << "Podaj numer kolumny licząc od jedynki:";
                    std::cin >> y1;
                    while (std::cin.fail() != false) {
                        std::cout << std::endl << "Podaj liczbe całkowitą!";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << std::endl << "Podaj pole" << std::endl;
                        std::cout << "Podaj numer wiersza licząc od jedynki:";
                        std::cin >> x1;
                        std::cout << "Podaj numer kolumny licząc od jedynki:";
                        std::cin >> y1;
                    }
                    wprowadzenie.revealField(x1 - 1, y1 - 1);
                    break;
                case 2:
                    t = false;
                    int x2, y2;
                    std::cout << "Podaj pole" << std::endl;
                    std::cout << "Podaj numer wiersza licząc od jedynki:";
                    std::cin >> x2;
                    std::cout << "Podaj numer kolumny licząc od jedynki:";
                    std::cin >> y2;
                    while (std::cin.fail() != false) {
                        std::cout << std::endl << "Podaj liczbe całkowitą";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << std::endl << "Podaj pole" << std::endl;
                        std::cout << "Podaj numer wiersza licząc od jedynki:";
                        std::cin >> x2;
                        std::cout << "Podaj numer kolumny licząc od jedynki:";
                        std::cin >> y2;
                    }
                    wprowadzenie.toggleFlag(x2 - 1, y2 - 1);
                    break;
                default:
                    std::cout << "Podałeś złą wartość, spróbuj ponownie: ";

            }
        };
        if (wprowadzenie.getGameState() == GameState::RUNNING) {
            system("clear");
        } else {
            system("clear");
            widok_planszy.display();
        }
    }
}


