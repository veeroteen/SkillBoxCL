#include <vector>
#include <string>
//Площадь
struct Area{
int area;
};
//Комната
struct Room: Area{
    std::string type;
};
//Этаж
struct Lvl: Area{
std::vector<Room> rooms;
int height;
};
struct House: Area{
    std::vector<Lvl> levels;
    bool pipe = false;
};
struct Garage: Area{
bool have = false;
};
struct Barn: Area{
    bool have = false;
};
struct Bathhouse: Area{
    bool have = false;
    bool pipe = false;
};
//Участок
struct Region{
    int count;
    House house;
    Garage garage;
    Barn barn;
    Bathhouse bathhouse;
};
//Село
struct Settlement{
std::vector<Region> regions;
};

