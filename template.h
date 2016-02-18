#ifndef __TEMPLATE_H
#define __TEMPLATE_H

template<typename T> class DefenderT{
	public:
		friend T;
		void Defence(int x, int y){}
		void Tackle(int x, int y){}

	private:
		int pos_x = 15;
		int pos_y = 0;
		int speed = 2;
		int stamina = 120;
};

template <typename T> class AttacketT{
	public:
		friend T;
		void Move(int x, int y){}
		void SpeedUp(float ratio);

	private:
		int pos_x = 0;
		int pos_y = -30;
		int speed = 3;
		int stamina = 100;
};

using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;

#ifdef UNIT_TEST

class Validator{
	public:
		void Validate(int x, int y, DefenderTest& d){}
		void Validate(int x, int y, AttackerTest& d){}
};
using DefenderTest = DefenderT<Validator>;
using AttackerTest = AttackerT<Validator>;

#endif //UNIT_TEST

#endif

