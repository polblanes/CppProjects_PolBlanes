#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>


enum class Weapon { FISTS, GUN, SHOTGUN, REVOLVER, SNIPER, MACHINE_GUN, MAX };
const int ZOMBIE_MAX = 10;
class Zombie;

class Player {
public :
	//atributes
	Weapon weapon;
	float precision;
	int life;

	//Methods
	void attack(Zombie &);
	bool isAlive(){
		return life > 0;
	}

	//Constructors
	Player():
		weapon(static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX))),
		precision((rand() % 10) / 10.f),
		life(100) {};

	Player(Weapon t_weapon, float t_precision, int t_life):
		weapon(t_weapon),
		precision(t_precision),
		life(t_life) {};

};

class Zombie {
public:
	//Atributes
	int distanceToPlayer;
	float speed;
	float damage;
	int life;

	//Methods
	void attack(Player &player) {
		player.life -= static_cast<int>(damage);
	}
	bool isAlive() {
		return life > 0;
	}

	//Constructors
	Zombie(int t_distanceToPlayer, float t_speed, float t_damage, int t_life):
		distanceToPlayer(t_distanceToPlayer),
		speed(t_speed),
		damage(t_damage),
		life(t_life) {};

	Zombie():
		distanceToPlayer(20 + rand() % (200 - 20)),
		speed((rand() % 20) / 20.f),
		damage((rand() % 20) / 20.f),
		life(100) {};
};

void Player::attack(Zombie &zombie) {
	zombie.life -= static_cast<int>(static_cast<int>(weapon)*precision);
}

std::ostream& operator<< (std::ostream& os, Weapon& w) {
	switch (w) {
	case Weapon::FISTS:
		os << "fists";
	case Weapon::GUN:
		os << "gun";
	case Weapon::SHOTGUN:
		os << "shotgun";
	case Weapon::REVOLVER:
		os << "revolver";
	case Weapon::SNIPER:
		os << "sniper";
	case Weapon::MACHINE_GUN:
		os << "machine gun";
	}
	return os;
}

void main() {
	std::cout << std::setprecision(2);

	srand(time(nullptr));
	Player player;
	Zombie zombieArray[ZOMBIE_MAX];

	bool zombiesAreAlive;
	do {
		zombiesAreAlive = false;
		for (int i = -1; i < 10; i++) {
			if (i < 0) {
				std::cout << "Player: " << std::endl << "        " << "Life: " << player.life << ", Weapon: " << player.weapon << ", Precision: " << player.precision << std::endl;
			}
			else {
				if (zombieArray[i].distanceToPlayer > 0) {
					zombieArray[i].distanceToPlayer -= floor(zombieArray[i].speed);
					if (player.weapon != Weapon::FISTS) {
						player.attack(zombieArray[i]);
					}
				}
				else {
					zombieArray[i].attack(player);
					player.attack(zombieArray[i]);
				}
				std::cout << "Zombie[" << i << "]:" << std::endl << "        " << "Life: " << zombieArray[i].life << ", Distance: " << zombieArray[i].distanceToPlayer
					<< ", Speed: " << zombieArray[i].speed << ", Damage: " << zombieArray[i].damage << std::endl;
			}
			if (zombieArray[i].isAlive()) {
				zombiesAreAlive = true;
			}
		}
		std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

	} while (zombiesAreAlive && player.isAlive());
	std::cout << "GAME OVER: ";
	if (zombiesAreAlive) {
		std::cout << "Zombies ate the player's brain!" << std::endl;
	}
	else {
		std::cout << "Player killed all the zombies!" << std::endl;
	}
}

