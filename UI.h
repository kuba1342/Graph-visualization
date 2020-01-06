#include "ofGraphics.h"
#include "ofAppRunner.h"
#include <string>

#pragma once
class UI {
	int mode;
	std::string displayMode;
	std::string manual;

public:
	UI();

	void setup(int newMode);

	void draw();

	void checkMode(int newMode);

	void checkManual(bool manualStatus);

	~UI();
};

