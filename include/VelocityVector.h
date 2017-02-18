#pragma once
class VelocityVector {
public:
	float x;
	float y;
	bool dissipates = true;
	int duration = 1;
	int time_existed = 0;
	bool done = false;

	VelocityVector(float x, float y, bool dissipates, int duration) : x(x), y(y), dissipates(dissipates), duration(duration) {};

	void dissipate() {
		if (dissipates) {
			x -= x / duration;
		}
		time_existed += 1;
		if (time_existed == duration){
			done = true;
		}
	}
};