//------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <cmath>
#include <cfloat>
#include <vector>
#include <array>

#include "Eigen/Dense"

#include "param.h"
#include "runge_kutta.h"
#include "dynamics.h"
#include "controller.h"


// シミュレーション処理メイン部
template <class Method, class OEQ>
void Simulator(Method f, OEQ h, const char *filename)
{
	
	// SIM変数
	double t = 0;
	std::ofstream ofs(filename);
	std::cout << filename << std::endl;

	// 状態・入力変数
	Eigen::VectorXd x = Eigen::VectorXd::Zero(kNumStateX);
	Eigen::VectorXd u = Eigen::VectorXd::Zero(kNumInputU);
	Eigen::VectorXd y = Eigen::VectorXd::Zero(kNumOutputY);
	x << 1.0, 1.0; // 状態初期化

	// 制御器クラス
	Controller Ctrl(u);
	
	// シミュレーション処理
	for (int i = 0; i < 200; i++)
	{
		// 時間更新
		t += kSmplTimeSim;

		// 制御計算
		if(i%kNumSimCtrl == 0)
		{
			u = Ctrl(x);
		}
		
		// ルンゲクッタ更新
		x = f(t, x, u);
		y = h(t, x, u);

		//ロギング
		ofs << t << ",";
		for(auto tmp:x)
		{
			ofs << tmp << ",";
		}
		for(auto tmp:u)
		{
			ofs << tmp << ",";
		}
		for(auto tmp:y)
		{
			ofs << tmp << ",";
		}
		ofs << std::endl;
	}
}

//------------------------------------------------------------------------
int main(void)
{
	// 積分シミュレーション
	Simulator(RungeKutta<Dynamics::StateEquation>(kSmplTimeSim), Dynamics::OutputEquation(), "simout.csv");

	std::cout << "シミュレーション実行完了" << std::endl;
	// RungeKuttaクラスにテンプレート関数としてDIFFを定義しており、RungeKuttaクラス生成時にDynamics::StateEquationをテンプレート引数として渡している

}