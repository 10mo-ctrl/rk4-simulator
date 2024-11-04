#include <iostream>
#include <cmath>
#include <vector>
#include <array>

#include "Eigen/Dense"
#include "param.h"
#include "dynamics.h"

// 定数定義
const double A = 2.0, B = 3.0, C = 4.0, D = 5.0;

// 状態方程式計算関数
Eigen::VectorXd Dynamics::StateEquation::CalcSEQ(double t, Eigen::VectorXd x, Eigen::VectorXd u)
{
    Eigen::VectorXd dx(kNumStateX);
    dx(0) = x(0) * (A - B * x(1));
    dx(1) = x(1) * (C * x(0) - D);
    return dx;
}

// 出力方程式計算関数
Eigen::VectorXd Dynamics::OutputEquation::CalcOEQ(double t, Eigen::VectorXd x, Eigen::VectorXd u)
{
    Eigen::VectorXd y = Eigen::VectorXd::Zero(kNumOutputY);
    y(0) = t;
    return y;
}
