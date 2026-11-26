#include <Novice.h>
#include <math.h>
#include <cmath>
#include "Energy.h"

Energy::Energy()
{

	InitialValueEnergy_ = 0.0f;//初期値
	CurrentValueEnergy_ = 0.0f;//現在値
	MaximumValueEnergy_ = 100.0f;//最大値
	BaseAdditiveValue_ = 0.1f;//基礎加算値

}

void Energy::Update()
{
	if (MaximumValueEnergy_ >= CurrentValueEnergy_) {

		CurrentValueEnergy_ += BaseAdditiveValue_;

	}

}


void Energy::Draw()
{
	// ------------------------------
	// ボスのHPバー
	// ------------------------------

	// HPバーの位置
	int hpBarX = 1380;
	int hpBarY = 100;

	// HPバーの大きさ
	int hpBarWidth = 40;
	int hpBarHeight = 700;

	// 現在のHPの割合を計算
	float hpRate = static_cast<float>(CurrentValueEnergy_) / MaximumValueEnergy_;
	// 現在のHPに合わせてバーの幅を計算
	int currentHpHeight = static_cast<int>((hpBarHeight * hpRate) * -1);

	//エネルギーバーの背景（黒）
	Novice::DrawBox
	(
		hpBarX,
		hpBarY,
		hpBarWidth,
		hpBarHeight,
		0.0f,
		0x404040FF,
		kFillModeSolid
	);

	// エネルギーの残量（赤）
	Novice::DrawBox
	(
		hpBarX,
		hpBarY + hpBarHeight,
		hpBarWidth,
		currentHpHeight,
		0.0f,
		0xFF2040FF,
		kFillModeSolid
	);

	// HPバーの白い枠線
	Novice::DrawBox
	(
		hpBarX,
		hpBarY,
		hpBarWidth,
		hpBarHeight,
		0.0f,
		WHITE,
		kFillModeWireFrame
	);



}



