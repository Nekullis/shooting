#pragma once
#include"dxlib.h"
#include"Bullet.h"
class Boss
{
public:
	Boss();
	virtual ~Boss();

	bool Process();
	bool Render();

};

