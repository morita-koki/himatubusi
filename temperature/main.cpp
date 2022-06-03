#include "temperature.hpp"
#include <iostream>


int main(int argc, char* argv[]) 
{
	using namespace temperature;
	using namespace temperature_scale_literals;

	auto T1{ 36.5_deg };
	auto T2{ 79.0_f };

	auto Tf = temperature_cast<scale::fahrenheit>(T1);
	auto Tc = temperature_cast<scale::celsius>(Tf);

	std::cout << static_cast<double>(Tf) << std::endl;
	std::cout << static_cast<double>(Tc) << std::endl;
	return 0;
}