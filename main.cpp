#include <iostream>
#include <random>

int Random() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);
    return dist(gen);
}

bool find(bool change_choise, char show_game) {
    int true_answer = Random();
    int machine_answer = Random();
    int wrong_answer = Random();
    int new_answer = Random();

    while (wrong_answer == true_answer)  wrong_answer = Random();

    if (show_game == 'Y' || show_game == 'y') {
        std::cout << "" << machine_answer << "|" << wrong_answer << "|";
    }

    if (change_choise == true) {
        for (new_answer = 1; new_answer == machine_answer || new_answer == wrong_answer; new_answer++) {}
        machine_answer = new_answer;

        if (show_game == 'Y' || show_game == 'y') {
            std::cout << "" << machine_answer << "|";
        }
    }

    int result = machine_answer == true_answer ? 1 : 0;

    if (show_game == 'Y' || show_game == 'y') {
        std::cout << "" << true_answer << "" << "| " << result << std::endl << std::endl;
    }
    return result;
}

int main() {
    int games;
    char show_game;
    char res;
     
    do {
        int wins_no_change_choise = 0;
        int loses_no_change_choise = 0;
        int wins_change_choise = 0;
        int loses_change_choise = 0;

        while (true) {
            std::cout << "How many games?" << std::endl;
            std::cin >> games;

            if (std::cin.fail() || games <= 0) {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("cls");
                std::cout << "Invalid input." << std::endl;
            }
            else {
                break;
            }
        }

        while (true) {
            std::cout << "Show games? Y/n " << std::endl;
            std::cin >> show_game;

            if (show_game == 'Y' || show_game == 'y' || show_game == 'N' || show_game == 'n') {
                break;
            }
            else {
                std::cout << "Invalid input. Please, enter Y or n." << std::endl;
            }
        }

        system("cls");

        if (games > 1000 && show_game != 'y' && show_game != 'Y') {
            std::cout << "Wait..." << std::endl;
        }

        if (show_game == 'Y' || show_game == 'y') {
            system("cls");
            std::cout << "a - machine answer " << std::endl;
            std::cout << "n - new machine answer" << std::endl;
            std::cout << "w - wrong door" << std::endl;
            std::cout << "t - true door" << std::endl << std::endl;

            std::cout << "a|w|t|win? " << std::endl;
        }

        for (int i = 0; i < games; i++) {
            find(false, show_game) ? wins_no_change_choise++ : loses_no_change_choise++;
        }

        if (show_game == 'Y' || show_game == 'y') {
            std::cout << std::endl << "a|w|n|t|win?" << std::endl;
        }

        for (int i = 0; i < games; i++) {
            find(true, show_game) ? wins_change_choise++ : loses_change_choise++;
        }

        if (games > 1000 && show_game != 'y' && show_game != 'Y') {
            system("cls");
        }

        std::cout <<  "                   wins / loses      winrate" << std::endl;
        std::cout <<  "No change choise   " << wins_no_change_choise << " / " << loses_no_change_choise << "       " << (static_cast<double>(wins_no_change_choise) / games * 100) << "%" << std::endl;
        std::cout << "Change choise      " << wins_change_choise << " / " << loses_change_choise << "       " << (static_cast<double>(wins_change_choise) / games * 100) << "%" << std::endl << std::endl;

        while (true) {
            std::cout << "Restart? Y/n" << std::endl;
            std::cin >> res;

            if (res == 'Y' || res == 'y' || res == 'N' || res == 'n') {
                break;
            }
            else {
                std::cout << "Invalid input. Please, enter Y or n." << std::endl;
            }
        }

        if (res != 'Y' && res != 'y') {
            return 0;
        }
        system("cls");

    } while (true);

    return 0;
}