#include "Game.h"

int sizex = 40, sizey = 40;

void Level::loadMap() {
	for (int y = 0; y < sizey; y++) {
		for (int x = 0; x < sizex; ++x) {
			map[y][x] = '.';
		}
	}
	map[actor.position.y][actor.position.x] = 'P';
	for (int i = 0; i < enemies.size(); i++) {
		Position* pos = &enemies[i].position;
		map[(*pos).y][(*pos).x] = 'E';
	}
}

void Level::loadActor() {
	cout << "Enter actor name\n";
	string str;
	cin >> str;
	actor.name = str;
	cout << "Enter actor heal point\n";
	int tmp;
	cin >> tmp;
	actor.hp = tmp;
	cout << "Enter actor armor\n";
	cin >> tmp;
	actor.armor = tmp;
	cout << "Enter actor damage\n";
	cin >> tmp;
	actor.damage = tmp;
	actor.position = { rand() % sizex, rand() % sizey };
}

void Level::loadEnemies() {
	enemies = vector<Enemy>();
	for (int i = 0; i < 5; i++) {
		Enemy tmp;
		tmp.name = "Enemy#" + to_string((i + 1));
		tmp.hp = rand() % 101 + 50;
		tmp.armor = rand() % 51;
		tmp.damage = rand() % 16 + 15;
		while (true) {
			bool leave = false;
			Position pos = { rand() % sizex, rand() % sizey };
			for (int n = 0; n < enemies.size(); n++) {
				if (pos == enemies[n].position || pos == actor.position) {
					leave = true;
					break;
				}
			}
			if (leave) {
				continue;
			}
			tmp.position = pos;
			break;
		}
		enemies.push_back(tmp);
	}
}

void Level::draw() {
	for (int y = 0; y < sizey; y++) {
		for (int x = 0; x < sizex; ++x) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}

void Level::move(string str) {
	Position lastPos = actor.position;
	if (str == "top") {
		if (actor.position.y > 0) {
			if (collision(Position{ actor.position.x, actor.position.y - 1 })) {
				attack(Position{ actor.position.x, actor.position.y - 1 }, actor.damage);
			}
			else {
				map[actor.position.y][actor.position.x] = '.';
				actor.position.y--;
				map[actor.position.y][actor.position.x] = 'P';
			}
		}
	}
	if (str == "bottom") {
		if (actor.position.y < sizey - 1) {
			if (collision(Position{ actor.position.x, actor.position.y + 1 })) {
				attack(Position{ actor.position.x, actor.position.y + 1 }, actor.damage);
			}
			else {
				map[actor.position.y][actor.position.x] = '.';
				actor.position.y++;
				map[actor.position.y][actor.position.x] = 'P';
			}
		}
	}
	if (str == "right") {
		if (actor.position.x < sizex - 1) {
			if (collision(Position{ actor.position.x + 1, actor.position.y })) {
				attack(Position{ actor.position.x + 1, actor.position.y }, actor.damage);
			}
			else {
				map[actor.position.y][actor.position.x] = '.';
				actor.position.x++;
				map[actor.position.y][actor.position.x] = 'P';
			}
		}
	}
	if (str == "left") {
		if (actor.position.x > 0) {
			if (collision(Position{ actor.position.x - 1, actor.position.y })) {
				attack(Position{ actor.position.x - 1, actor.position.y }, actor.damage);
			}
			else {
				map[actor.position.y][actor.position.x] = '.';
				actor.position.x--;
				map[actor.position.y][actor.position.x] = 'P';
			}
		}
	}

	for (int i = 0; i < enemies.size(); i++) {
		Position* pos = &enemies[i].position;
		int tmp = rand() % 4;

		switch (tmp) {
		case 0:
			if (pos->y != sizey - 1) {
				if (this->collision(Position{ (*pos).x, (*pos).y + 1 })) {
					attack(Position{ (*pos).x, (*pos).y + 1 }, enemies[i].damage, true);
					break;
				}
				map[pos->y][pos->x] = '.';
				pos->y++;
				map[pos->y][pos->x] = 'E';
				break;
			}
			break;
		case 1:
			if (pos->y != 0) {
				if (this->collision(Position{ (*pos).x, (*pos).y - 1 })) {
					attack(Position{ (*pos).x, (*pos).y - 1 }, enemies[i].damage, true);
					break;
				}
				map[pos->y][pos->x] = '.';
				pos->y--;
				map[pos->y][pos->x] = 'E';
				break;
			}
			break;
		case 2:
			if (pos->x != sizex - 1) {
				if (this->collision(Position{ (*pos).x + 1, (*pos).y })) {
					attack(Position{ (*pos).x + 1, (*pos).y }, enemies[i].damage, true);
					break;
				}
				map[pos->y][pos->x] = '.';
				pos->x++;
				map[pos->y][pos->x] = 'E';
				break;
			}
			break;
		case 3:
			if (pos->x != 0) {
				if (this->collision(Position{ (*pos).x - 1, (*pos).y })) {

					attack(Position{ (*pos).x - 1, (*pos).y }, enemies[i].damage, true);
					break;
				}
				map[pos->y][pos->x] = '.';
				pos->x--;
				map[pos->y][pos->x] = 'E';
				break;
			}
			break;
		}

	}

}

bool Level::collision(Position pos) {
	if (pos == actor.position) {
		return true;
	}
	for (int i = 0; i < enemies.size(); i++) {
		if (pos == enemies[i].position) {
			return true;
		}
	}
	return false;
}

void Level::attack(Position pos, int damage, bool enemy) {
	if (enemy) {
		if (actor.position == pos) {
			damage = damage - actor.armor;
			if (damage > 0) {
				actor.hp = actor.hp - damage;

			}
		}
		return;
	}
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i].position == pos) {
			damage = damage - enemies[i].armor;
			if (damage > 0) {
				enemies[i].hp = enemies[i].hp - damage;
				if (enemies[i].hp < 1) {
					map[enemies[i].position.y][enemies[i].position.x] = '.';
					enemies.erase(enemies.begin() + i);
				}
				return;
			}
		}

	}
}

int Level::status() {
	if (actor.hp < 1)
	{
		return -1;
	}
	if (enemies.size() == 0)
	{
		return 1;
	}
	return 0;
}

void Level::save() {
	ofstream file("save.txt");
	string str = actor.name + " " + to_string(actor.hp) + " " + to_string(actor.armor) + " " +
		to_string(actor.damage) + " " + to_string(actor.position.x) + " " + to_string(actor.position.y);
	file << str << endl;
	for (int i = 0; i < enemies.size(); i++) {
		str = enemies[i].name + " " + to_string(enemies[i].hp) + " " + to_string(enemies[i].armor) + " " +
			to_string(enemies[i].damage) + " " + to_string(enemies[i].position.x) + " " + to_string(enemies[i].position.y);
		file << str << endl;
	}
	file.close();

}
void Level::load() {
	ifstream file("save.txt");


	stringstream stream;
	string str;
	getline(file, str);
	stream << str;

	stream >> actor.name;
	stream >> actor.hp;
	stream >> actor.armor;
	stream >> actor.damage;
	stream >> actor.position.x;
	stream >> actor.position.y;
	Actor ac = actor;
	enemies.clear();
	while (true) {
		stream.clear();
		getline(file, str);
		if (str == "") { break; }
		stream << str;
		Enemy enemy;
		stream >> enemy.name;
		stream >> enemy.hp;
		stream >> enemy.armor;
		stream >> enemy.damage;
		stream >> enemy.position.x;
		stream >> enemy.position.y;
		enemies.push_back(enemy);
	}
	loadMap();
	file.close();
}
void Game::start() {
	level.loadActor();
	level.loadEnemies();
	level.loadMap();
	while (true) {
		level.draw();
		cout << "Enter command\n";
		string str;
		cin >> str;
		if (str == "save") {
			level.save();
		}
		else if (str == "load") {
			level.load();
		}
		else
		{
			level.move(str);

			int stat = level.status();
			if (stat == 1) {
				cout << "You won!!!\n";
				return;
			}
			else if (stat == -1) {
				cout << "You Lose((\n";
				return;

			}
		}
	}


}