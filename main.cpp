#include<iostream>
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"


class visualSort : public olc::PixelGameEngine
{
	class visualData {
	public:
		int width = 20;
		int height;
		
	};
public:
	visualSort() {
		sAppName = "Visual Sort";
	}
	bool OnUserCreate() override {
		srand(time(NULL));
		for (int i = 0; i < num; i++){
			d[i].height = rand() % max;
		}
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override {
		Clear(olc::BLACK);
		int xside = 0;
		float time = fElapsedTime * 0.000002;
		for (int j = 0; j < num; j++) {
			
			FillRect(xside,1080-d[j].height, d[j].width, d[j].height, olc::WHITE);
			xside += 20;
			
		}
		
		if (GetMouse(olc::Mouse::LEFT).bHeld) {
				for (int b = 0; b < num - time - 1; b++) {
					if (d[b].height > d[b + 1].height)
						std::swap(d[b].height, d[b + 1].height);
				}
		}
		return true;
	}
private:
	const static int num = 95;
	visualData d[num];
	int max = 1080;
};

int main() {
	visualSort start;
	if (start.Construct(1920, 1080, 1, 1))
		start.Start();
	return 0;
}
