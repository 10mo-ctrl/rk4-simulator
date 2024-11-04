#include <iostream>
#include <fstream>
#include <cmath>
#include <cfloat>
#include <vector>
#include <array>

#include "Eigen/Dense"

#include "param.h"
#include "controller.h"

// 制御入力計算関数
Eigen::VectorXd Controller::CalcCtrlInput(Eigen::VectorXd x)
{
	// std::cout << "CalcCtrlInput() Called" << std::endl;
	for (auto &s : u)
	{
		s = s + 1;
	}
	
	return u;
}
