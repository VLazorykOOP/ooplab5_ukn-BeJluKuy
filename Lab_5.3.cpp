#include <iostream>
#include <string>

class SportGame {
protected:
    std::string name;

public:
    SportGame(const std::string& name) {
        this->name = name;
    }

    // Конструктор копіювання
    SportGame(const SportGame& other) {
        name = other.name;
    }

    // Конструктор перенесення
    SportGame(SportGame&& other) {
        name = std::move(other.name);
    }

    // Оператор присвоювання
    SportGame& operator=(const SportGame& other) {
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }

    // Оператор перенесення
    SportGame& operator=(SportGame&& other) {
        if (this != &other) {
            name = std::move(other.name);
        }
        return *this;
    }

    virtual void play() {
        std::cout << "Playing " << name << " sport game." << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const SportGame& game) {
        os << "Sport Game: " << game.name;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, SportGame& game) {
        is >> game.name;
        return is;
    }
};

class Football : public SportGame {
private:
    int numOfPlayers;

public:
    Football(const std::string& name, int numOfPlayers) : SportGame(name) {
        this->numOfPlayers = numOfPlayers;
    }

    // Конструктор копіювання
    Football(const Football& other) : SportGame(other) {
        numOfPlayers = other.numOfPlayers;
    }

    // Конструктор перенесення
    Football(Football&& other) : SportGame(std::move(other)) {
        numOfPlayers = other.numOfPlayers;
    }

    // Оператор присвоювання
    Football& operator=(const Football& other) {
        if (this != &other) {
            SportGame::operator=(other);
            numOfPlayers = other.numOfPlayers;
        }
        return *this;
    }

    // Оператор перенесення
    Football& operator=(Football&& other) {
        if (this != &other) {
            SportGame::operator=(std::move(other));
            numOfPlayers = other.numOfPlayers;
        }
        return *this;
    }

    void play() override {
        std::cout << "Playing football game: " << name << std::endl;
        std::cout << "Number of players: " << numOfPlayers << std::endl;
    }
};

int main() {
    Football game1("Football", 11);
    game1.play();

    std::cout << "Enter a football game: ";
    Football game2("Default", 0);
    std::cin >> game2;

    std::cout << "Game 1: " << game1 << std::endl;
    std::cout << "Game 2: " << game2 << std::endl;

    return 0;
}
