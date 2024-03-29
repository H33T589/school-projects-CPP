#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Color { RED, GREEN, BLUE };
enum class Gender { MALE, FEMALE };
enum class HorseType { RACING, WORKING, LEISURE };
enum class HorseSize { BIG, SMALL, NORMAL };

class Mammal {
protected:
    float speed;
    Color color;
    bool tail;

public:
    // Constructor
    Mammal(float _speed, Color _color, bool _tail)
        : speed(_speed), color(_color), tail(_tail) {
    }

    // Getter methods
    float getSpeed() const {
        return speed;
    }

    Color getColor() const {
        return color;
    }

    bool hasTail() const {
        return tail;
    }
};

class Horse : public Mammal {
private:
    Gender gender;
    HorseType type;
    HorseSize size;
    int distanceTraversed;
    double price;

public:
    // Constructors
    Horse(float _speed, Color _color, bool _tail, Gender _gender, HorseType _type, HorseSize _size, double _price)
        : Mammal(_speed, _color, _tail), gender(_gender), type(_type), size(_size), distanceTraversed(0), price(_price) {
    }

    // Default constructor
    Horse() : Mammal(0.0, Color::RED, true), gender(Gender::MALE), type(HorseType::RACING), size(HorseSize::BIG), distanceTraversed(0), price(0.0) {}

    // Getter methods and other methods...
    Gender getGender() const {
        return gender;
    }

    HorseType getType() const {
        return type;
    }

    HorseSize getSize() const {
        return size;
    }

    int getDistanceTraversed() const {
        return distanceTraversed;
    }

    double getPrice() const {
        return price;
    }

    void updateDistanceTraversed() {
        distanceTraversed += static_cast<int>(speed);
    }
};

int getRandomNumber() {
    return rand() % 10;
}

void initializeHorses(Horse horses[]) {
    for (int i = 0; i < 3; ++i) {
        float speed = static_cast<float>(getRandomNumber()) * 3.0;
        Color color = static_cast<Color>(getRandomNumber() % 3);
        bool tail = getRandomNumber() % 2 == 0;
        Gender gender = static_cast<Gender>(getRandomNumber() % 2);
        HorseType type = static_cast<HorseType>(getRandomNumber() % 3);
        HorseSize size = static_cast<HorseSize>(getRandomNumber() % 3);
        double price = static_cast<double>(getRandomNumber() % 751 + 50);

        horses[i] = Horse(speed, color, tail, gender, type, size, price);
    }
}

void simulateRace(Horse horses[], int trackLength, double& initialMoney, double& winningMoney, double& lostMoney, int chosenHorse, double betAmount) {
    int time = 0;
    while (true) {
        for (int i = 0; i < 3; ++i) {
            horses[i].updateDistanceTraversed();
            if (horses[i].getDistanceTraversed() >= trackLength) {
                cout << "Horse " << i + 1 << " wins!" << endl;
                cout << "Time taken: " << time << " seconds" << endl;
                cout << "Horse Type: ";
                switch (horses[i].getType()) {
                    case HorseType::RACING:
                        cout << "Racing" << endl;
                        break;
                    case HorseType::WORKING:
                        cout << "Working" << endl;
                        break;
                    case HorseType::LEISURE:
                        cout << "Leisure" << endl;
                        break;
                }

                if (i == chosenHorse - 1 && chosenHorse != 0) {
                    double prize = betAmount * 4;
                    winningMoney += prize;
                    cout << "Congratulations! You won $" << prize << endl;
                    cout << "New account balance is $" << (initialMoney + winningMoney - lostMoney) << endl;
                } else {
                    lostMoney += betAmount;
                    cout << "Sorry, you lost $" << betAmount << endl;
                    cout << "New account balance is $" << (initialMoney - lostMoney) << endl;
                }

                return;
            }
        }
        time++;
    }
}

void displayRaceResults(Horse horses[]) {
    for (int i = 0; i < 3; ++i) {
        cout << "Horse " << i + 1 << ": Distance Traversed - " << horses[i].getDistanceTraversed() << " meters" << endl;
    }
}

void playGame() {
    Horse horses[3];
    int trackLength = 0;
    double initialMoney = 0.0;
    double winningMoney = 0.0;
    double lostMoney = 0.0;
    int chosenHorse = 0;
    double betAmount = 0.0;
    bool raceStarted = false;
    double initialmon;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Help." << endl;
        cout << "2. Choose length for this racing track." << endl;
        cout << "3. Pick your horse number and bet amount." << endl;
        cout << "4. Start the race." << endl;
        cout << "5. Check your financial status." << endl;
        cout << "9. Quit." << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Help
                cout << "Rules of the Game:" << endl;
                cout << "  - Initial cash for this game is specified by the player." << endl;
                cout << "  - The largest bet for each game is $800." << endl;
                cout << "  - The smallest bet for each game is $50." << endl;
                cout << "  - Each racing game is composed of three horses." << endl;
                cout << "  - Players can place his or her bet on any one of these three horses." << endl;
                cout << "  - The winning prize is: 4x the betting price." << endl;
                break;

            case 2:
                // Choose track length
                char trackChoice;
                cout << "Choose length for this racing track (x for 200, y for 500): ";
                cin >> trackChoice;
                if (trackChoice == 'x' || trackChoice == 'X') {
                    trackLength = 200;
                } else if (trackChoice == 'y' || trackChoice == 'Y') {
                    trackLength = 500;
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;

            case 3:
                    // Pick horse and place bet
                if (trackLength == 0) {
                    cout << "Please choose the length for the racing track first." << endl;
                } else if (raceStarted) {
                    cout << "Race has already started. Cannot choose a horse now." << endl;
                } else {
                cout << "Enter your initial cash: $";
                cin >> initialmon;
                initialMoney = initialmon;
                initializeHorses(horses);
                cout << "Available Horses:" << endl;
                for (int i = 0; i < 3; ++i) {                        
                    cout << "Horse " << i + 1 << ": Type - ";
                        switch (horses[i].getType()) {
                            case HorseType::RACING:
                                cout << "Racing";
                                break;
                            case HorseType::WORKING:
                                cout << "Working";
                                break;
                            case HorseType::LEISURE:
                                cout << "Leisure";
                                break;
                        }
                        cout << ", Speed - " << horses[i].getSpeed() << ", Price - $" << horses[i].getPrice() << endl;
                    }

                    cout << "Pick your horse number (1-3): ";
                    cin >> chosenHorse;
                    
                    cout << "Specify the bet amount (between $50 and $800): ";
                    cin >> betAmount;

                    if (chosenHorse >= 1 && chosenHorse <= 3 && betAmount >= 50 && betAmount <= 800 && betAmount <= initialMoney) {
                        initialMoney -= betAmount;
                    } else {
                        cout << "Invalid choice. Please try again." << endl;
                        chosenHorse = 0;
                        betAmount = 0.0;
                    }
                }
                break;

            case 4:
                // Start the race
                initialMoney = initialmon;
                if (trackLength == 0) {
                    cout << "Please choose the length for the racing track first." << endl;
                } else if (chosenHorse == 0) {
                    cout << "Please pick your horse and place a bet before starting the race." << endl;
                } else {
                    cout << "Race in progress..." << endl;
                    raceStarted = true;
                    simulateRace(horses, trackLength, initialMoney, winningMoney, lostMoney, chosenHorse, betAmount);
                    displayRaceResults(horses);
                }
                break;

            case 5:
                // Check financial status
                cout << "Initial Money: $" << initialmon << endl;
                cout << "Winning Money: $" << winningMoney << endl;
                cout << "Lost Money: $" << lostMoney << endl;
                cout << "Cash in Hand: $" << (initialmon + winningMoney - lostMoney) << endl;
                break;

            case 9:
                // Quit the game
                cout << "Exiting the game." << endl << "Thank you for playing..." << endl;
                return;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Call the playGame function to start the game
    playGame();

    return 0;
}

