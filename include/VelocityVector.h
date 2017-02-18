#pragma once
class VelocityVector {
public:
	float x;
	float y;
	bool dissipates = true;
	int duration = 1;
	int time_existed = 0;
	bool done = false;
	float difference_x;
	float difference_y;

	VelocityVector(float x, float y, bool dissipates, int duration) : x(x), y(y), dissipates(dissipates), duration(duration) {
		difference_x = x / duration;
		difference_y = y / duration;
	};

	void dissipate() {
		if (dissipates) {
			x -= difference_x;
			y -= difference_y;
		}
		time_existed += 1;
		if (time_existed == duration){
			done = true;
		}
	}
};