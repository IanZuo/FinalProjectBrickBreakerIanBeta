#pragma once

class GameSession {
private:
    int lives;

    GameSession() : lives(3) {}  // 3 life points
public:
    static GameSession& Get() {
        static GameSession instance;
        return instance;
    }

    void Reset() { lives = 3; }
    void LoseLife() { lives--; }
    int GetLives() const { return lives; }
    bool IsGameOver() const { return lives <= 0; }
};
