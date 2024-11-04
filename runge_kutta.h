#ifndef _RUNGEKUTTA_H_
#define _RUNGEKUTTA_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <array>

#include "Eigen/Dense"
#include "param.h"

//------------------------------------------------------------------------
struct SimVars
{
	Eigen::VectorXd x = Eigen::VectorXd::Zero(kNumStateX);
	Eigen::VectorXd u = Eigen::VectorXd::Zero(kNumInputU);

	// コンストラクタ
	SimVars(Eigen::VectorXd x0)
	{
		x = x0;
	}
	SimVars()
	{
	}

	// // 演算子オーバーロード
	// // 状態ベクトル要素ごとの加算
	// States operator+(const States &s)
	// {
	// 	std::array<double, kNumStateX> tmp{};
	// 	for (int i = 0; i < x.size(); i++)
	// 	{
	// 		tmp[i] = x[i] + s.x[i];
	// 	}
	// 	return States(tmp);
	// }
	// // 状態ベクトルのスカラ積
	// States operator*(const double f)
	// {
	// 	std::array<double, kNumStateX> tmp{};
	// 	for (int i = 0; i < x.size(); i++)
	// 	{
	// 		tmp[i] = x[i] * f;
	// 	}
	// 	return States(tmp);
	// }
};

//------------------------------------------------------------------------
template <class DIFF>
class RungeKutta
{
private:
	const double dt;
	const double hdt;
	DIFF diff;

public:
	RungeKutta(double _dt) : dt(_dt), hdt(_dt * 0.5) {};
	Eigen::VectorXd operator()(double t, Eigen::VectorXd x, Eigen::VectorXd u)
	{
		Eigen::VectorXd k1(kNumStateX), k2(kNumStateX), k3(kNumStateX), k4(kNumStateX);
		k1 = diff(t, x, u);
		k2 = diff(t + hdt, x + k1 * hdt, u);
		k3 = diff(t + hdt, x + k2 * hdt, u);
		k4 = diff(t + hdt, x + k3 * dt, u);
		x = x + (k1 + k2 * 2.0 + k3 * 2.0 + k4) * (dt / 6.0);
		return x;
	}
};
#endif // _RUNGEKUTTA_H_