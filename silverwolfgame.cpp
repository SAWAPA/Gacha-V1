//Gacha <no garuntee>

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

enum class ItemType {
    star1,
    star2,
    star3,
    star4,
    star5
};

const double commonProbability = 0.50;
const double rareProbability = 0.30;
const double epicProbability = 0.10;
const double legendaryProbability = 0.07;
const double mysticalProbability = 0.02;

mt19937 rng(time(nullptr));

ItemType rollGacha() {
    uniform_real_distribution<double> distribution(0.0, 1.0);
    double roll = distribution(rng);

    if (roll < commonProbability) {
        return ItemType::star1;
    }
    else if (roll < commonProbability + rareProbability) {
        return ItemType::star2;
    }
    else if (roll < commonProbability + rareProbability + epicProbability) {
        return ItemType::star3;
    }
    else if (roll < commonProbability + rareProbability + epicProbability + legendaryProbability) {
        return ItemType::star4;
    }
    else if (roll < commonProbability + rareProbability + epicProbability + legendaryProbability + mysticalProbability) {
        return ItemType::star5;
    }
}

int main()
{
    string fname;
    char silvergame;
    int countroll;

    do {
        // Clear screen
        system("cls");

        //cout << "Create your name = ";
        //cin >> fname;
        cout << "How many Roll? : ";
        cin >> countroll;
        cout << "System : " << countroll << " Rolls (Y / N) : ";
        cin >> silvergame;

        if (silvergame == 'Y' || silvergame == 'y') {
            int durationInSeconds = 5; // Duration of the loading animation in seconds
            int framesPerSecond = 10; // Number of frames per second
            int totalFrames = durationInSeconds * framesPerSecond;

            for (int frame = 0; frame < totalFrames; ++frame) {
                // Determine the width of the loading block based on the current progress
                int width = (frame * 103) / totalFrames;

                cout << "Loading: [";
                for (int i = 0; i < 50; ++i) {
                    if (i < width / 2)
                        cout << "#";
                    else
                        cout << " ";
                }
                cout << "]" << width << "%\r";
                cout.flush();

                this_thread::sleep_for(chrono::milliseconds(10 / framesPerSecond));
            }

            cout << endl;

            for (int i = 0; i < countroll; ++i) {
                ItemType item = rollGacha();

                switch (item) {
                case ItemType::star1:
                    cout << "1 Star" << endl;
                    break;
                case ItemType::star2:
                    cout << "2 Star" << endl;
                    break;
                case ItemType::star3:
                    cout << "3 Star" << endl;
                    break;
                case ItemType::star4:
                    cout << "- 4 Star -" << endl;
                    break;
                case ItemType::star5:
                    cout << "=- 5 Star -=" << endl;
                    break;
                }
            }
        }
        else if (silvergame == 'N' || silvergame == 'n') {
            cout << "Exit" << endl;
        }
        else {
            cout << "!! ERROR !!" << endl;
        }

        cout << "Do you want to play again? (Y/N) ";
        cin >> silvergame;

    } while (silvergame == 'Y' || silvergame == 'y');

    return 0;
}
