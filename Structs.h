#include <vector>
#include <string>
//Площадь
struct Area{
    double area;
};
//Комната
struct Room: Area{
    int type;
};
enum building_type
{
    house = 1,
    garage = 2,
    bathhouse = 4,
    barn = 8
};
enum room_type
{
    living = 1,
    children = 2,
    bedroom = 4,
    kitchen = 8,
    bathroom = 16
};
//Этаж
struct Lvl: Area{
    std::vector<Room> rooms;
    int height;
};
struct Building: Area{
    std::vector<Lvl> levels;
    bool pipe = false;
    int type;
};

//Участок
struct Region: Area{
    std::vector <Building> buildings;
};
//Село
struct Settlement{
    std::vector<Region> regions;
};

