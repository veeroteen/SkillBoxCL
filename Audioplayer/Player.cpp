#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"


void Player::stop() {
	stat = status::stop;
	cout << current->name << " stoped\n";
}
void Player::play() {
	string str;
	cout << "Enter track name\n";
	cin >> str;
	for (int i = 0; i < tracks.size(); i++) {
		if (tracks[i].name == str) {
			current = &tracks[i];
			duration = current->duration;
			cout << "Now playing " << current->name << " create date: " << put_time(current->createDate, "%Y/%m/%d") << " duration: " << current->duration / 60 << ':' << current->duration % 60 << endl;
			break;
		}
	}
	t = time(nullptr);
	stat = status::play;
}
void Player::play(Track *track) {
	current = track;
	duration = current->duration;
	t = time(nullptr);
	stat = status::play;
	cout << "Now playing " << current->name << ", create date: " << put_time(current->createDate, "%Y/%m/%d") << ", duration: " << current->duration/60 << ':' << current->duration % 60 <<  endl;
}
void Player::next() {
	unsigned int track = rand() % tracks.size();
	if (&tracks[track] == current) {
		if (track == tracks.size()) {
			track--;
		}
		else if (track == 0) {
			track++;
		}
	}
	play(&tracks[track]);
}
void Player::pause() {
	stat = status::pause;
	cout << current->name << " paused\n";
}
void Player::engine() {
	while (true) {
		if (stat == status::play) {
			time_t tmp = time(nullptr);
			duration = duration - (tmp - t);
			t = tmp;
			if (duration <= 0) {
				next();
			}
		}
		cout << "Enter command\n";
		string str;
		cin >> str;

		if (str == "play" && stat != status::play) {
			if (stat == status::pause) {
				t = time(nullptr);
				stat = status::play;
				cout << "Track unpaused\n";
			}
			else {
				play();
			}
		}
		else if (str == "pause" && stat != status::pause) {
			pause();
		}
		else if (str == "stop" && stat != status::stop) {
			stop();
		}
		else if (str == "next") {
			next();
		}
		else if (str == "exit") {
			break;
		}
		

	}
}

Player::Player() {
	time_t t = time(0);
	tm* local = localtime(&t);

	tracks.push_back(Track{ local,rand() % 200 + 50, string("hh") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("gg") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("tt") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("aa") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("ww") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("ee") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("qq") });
	tracks.push_back(Track{ local,rand() % 200 + 50, string("uu") });


}