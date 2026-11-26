#include <Novice.h>
#include <stdio.h>
#include "Player.h"
#include "Boss.h"
#include "Energy.h"

const char kWindowTitle[] = "1247_PPPPPPPP";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1440, 900);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// プレイヤーの作成
	Player player;
	// ボスの作成
	Boss boss;
	// エネルギーの作成
	Energy energy;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player.Update(keys, preKeys);

		// Jキーを押した瞬間にボスへ10ダメージ(テスト用)
		if (keys[DIK_J] && !preKeys[DIK_J])
		{
			boss.TakeDamage(10);
		}

		// ボスの更新
		// プレイヤーの座標をボスに渡す
		boss.Update(player.GetX(), player.GetY());

		energy.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// 背景の描画
		Novice::DrawBox(0, 0, 1440, 900, 0.0f, BLACK, kFillModeSolid);

		// エネルギーゲージの描画
		energy.Draw();

		// プレイヤーの描画
		player.Draw();

		// ボスの描画
		boss.Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
