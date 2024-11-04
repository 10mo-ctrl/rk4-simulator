#ifndef _PARAM_H_
#define _PARAM_H_

// 定数マクロ
// #define NUM_STATE_X 2 // 状態数
// #define NUM_INPUT_U 2 // 入力数
constexpr int kNumStateX = 2; // 状態数
constexpr int kNumInputU = 2; // 入力数
constexpr int kNumOutputY = 2; // 出力数
constexpr double kSmplTimeSim = 0.05; // サンプリング時間(シミュレータ)
constexpr double kSmplTimeCtrl = 0.1; // サンプリング時間(制御器)
constexpr int kNumSimCtrl = int(kSmplTimeCtrl/kSmplTimeSim); // 制御割込カウント周期

#endif // _PARAM_H_