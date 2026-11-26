#pragma once
#include "Vector2.h"

class Energy
{
public:
	Energy();
	void Update();
	void Draw();
	Vector2 pos() const;

private:

	float InitialValueEnergy_;//初期値
	float CurrentValueEnergy_;//現在値
	float MaximumValueEnergy_;//最大値
	float BaseAdditiveValue_;//基礎加算値


};