#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  /* Check the validity of the following inputs
     * The estimation vector size should not be zero
     * The estimation vector size should be equal to the ground truth vector size
  */
  if(estimations.size()!=ground_truth.size() || estimations.size()==0){
    std::cout << "Invalid estimation or ground truth data" << std::endl;
    return rmse;
  }

  // Accumulate the squared error
  for(unsigned int i = 0; i < estimations.size(); ++i){
  	VectorXd residual = estimations[i] - ground_truth[i];
  	// Square the values
  	residual = residual.array() * residual.array();
  	rmse += residual;
  }

  // Calculate the mean of the squared error
  rmse = rmse/estimations.size();

  // Calculate the square root
  rmse = rmse.array().sqrt();

  //return the result
  return rmse;
}