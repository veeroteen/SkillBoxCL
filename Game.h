#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Position {
public:
    int x, y;
    bool operator==(Position pos) {
        if (x == pos.x && y == pos.y) {
            return true;
        }
        return false;
    }
};

struct Enemy {
    int hp;
    int armor;
    int damage;
    string name;
    Position position;
};
struct Actor {
    int hp;
    int armor;
    int damage;
    string name;
    Position position;
};


class Level {
private:
    char map[40][40];
    Actor actor = Actor();
    vector<Enemy> enemies;
public:
    void loadMap();
    void loadActor();
    void loadEnemies();
    void draw();
    void move(string str);
    bool collision(Position pos);
    void attack(Position pos, int damage,bool enemy= false);
    int status();
    void save();
    void load();
};

class Game {
private:
    Level level;
public:
    void start();

};


