// Deep Learning
// HW 2
// Problem 1
// David Carlyn

#include <iostream>
#include <string>
#include <vector>

struct ThreeDPoint {
	double x;
	double y;
	double z;
};

void setLearningRate( double& );
std::vector<ThreeDPoint> getInput();
void trainModel( std::vector <ThreeDPoint>, double&, double&, double&, double );
void printResults( double, double, double );

int main() {
	double b0 = 0.0f;
	double b1 = 0.0f;
	double b2 = 0.0f;
	double learning_rate = 0.01f;

	setLearningRate( learning_rate );

	std::vector<ThreeDPoint> training_data = getInput();

	trainModel( training_data, b0, b1, b2, learning_rate );

	printResults( b0, b1, b2 );

	// Pause
	std::system("PAUSE");

	return 0;
}

void setLearningRate( double& learning_rate ) {
	std::cout << "Set Learning Rate: ";
	std::cin >> learning_rate;
}

std::vector<ThreeDPoint> getInput() {
	double input_x;
	double input_y;
	double input_z;
	bool loop = true;
	std::vector<ThreeDPoint> return_value;

	while ( loop ) {
		std::cout << "Enter X value: ";
		std::cin >> input_x;
		std::cout << "Enter Y value: ";
		std::cin >> input_y;
		std::cout << "Enter Z value: ";
		std::cin >> input_z;

		ThreeDPoint p;
		p.x = input_x;
		p.y = input_y;
		p.z = input_z;
		return_value.push_back( p );

		char response;
		std::cout << "Would you like to enter another pair? (y/n): ";
		std::cin >> response;
		if ( response != 'y' ) {
			loop = false;
		}
	}

	return return_value;
}

void trainModel( std::vector <ThreeDPoint> input, double& b0, double& b1, double& b2, double learning_rate ) {
	int training_loops = 1;
	std::cout << "How many training loops? ";
	std::cin >> training_loops;

	std::cout << "Training Model" << std::endl;
	std::cout << "Learning Rate: " << learning_rate << std::endl;

	for ( int i = 0; i < training_loops; ++i ) {
		for ( auto point : input ) {
			double predicted_value = b0 + b1 * point.x + b2 * point.y;
			double error_value = predicted_value - point.z;
			std::cout << "b0: " << b0 << ", b1: " << b1 << ", b2: " << b2 << std::endl;
			std::cout << "g(" << point.x << ", " << point.y << ") = " << predicted_value << " | Error: " << error_value << std::endl;
			b0 = b0 - ( learning_rate * error_value );
			b1 = b1 - ( learning_rate * error_value * point.x );
			b2 = b2 - ( learning_rate * error_value * point.y );
		}
	}
}

void printResults( double b0, double b1, double b2 ) {
	std::cout << "Resulting Model" << std::endl;
	std::cout << "g( x, y ) = " << b0 << " + " << b1 << " * x + " << b2 << " * y" << std::endl;
}
