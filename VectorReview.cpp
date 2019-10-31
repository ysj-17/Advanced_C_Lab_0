// Program Name: Vector Review
//
// Description:  
//  This assignment is intended as a review of C++ features you already know. 
//	However, please replace any use of arrays with either the new C++ array type or vectors. 
//	Refer to the VECTOR.cpp example for code samples. This may seem, on the surface, to be a unchallenging assignment. 
//	The challenge is to do it with 10 or fewer IF statements. Too many IF statements often indicate a poorly designed program.
//
// Author: Jason Yoon
//
// Date: 9/29/2018
//
// IDE Used: Visual Microsoft
//


#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;


class OverallMeasurements {
	private:
		vector<tuple<double, string, double, string>> USDistance // 3 different measurement types
		{
			{ 1, "inches", (1.0/12.0), "feet" }, // 1 foot = 12 inches
			{ 1, "feet", (1.0/5280.0), "mile" }, // 1 mile = 5280 feet
		};

		vector<tuple<double, string, double, string>> MetricDistance // 4 different measurement types
		{
			{ (1.0 / 2.54), "inches", 1, "centimeter" }, // 1 centimeter = 1 / 2.54 inches
			{ 1, "centimeters", (1.0 / 100.0), "meters" }, // 1 meter = 100 centimeters
			{ 1, "meter", (1.0 / 1000.0), "kilometers" } // 1 kilometer = 1000 meters
		};

		vector<tuple<double, string, double, string>> USWeight // 2 different measurement types
		{
			{ 1, "ounces", (1.0/16.0), "pounds" }, // 1 pound = 16 ounces
		};

		vector<tuple<double, string, double, string>> MetricWeight // 2 different measurement types
		{
			{ 1, "ounces", 28.375, "grams" }, // 1 ounce = 28.375 grams
			{1000, "grams", 1, "kilogram"} // 1 kilogram = 1000 grams
		};

		vector<tuple<double, string, double, string>> USVolume // 2 different measurement types
		{
			{ 1, "ounces", (1.0/128.0), "gallon" }, // 1 gallon = 128 ounces
		};

		vector<tuple<double, string, double, string>> MetricVolume // 2 different measurement types
		{
			{ 1, "ounces", 29.57353, "milliliters" }, // 1 ounce = 29.57353 milliliters
			{ 1, "milliliters", (1.0/1000.0), "liters"} // 1 liter = 1000 milliliters
		};

	public: 

		void convertInches(int inches) {

			double bucket = inches * get<0>(USDistance[0]);
			for (auto& container : USDistance) {
				cout << bucket << " " << get<1>(container);
				bucket = bucket * get<2>(container);
				cout << " = " << bucket << " " << get<3>(container) << endl;
			}

			bucket = inches * get<0>(MetricDistance[0]);
			for (auto& container : MetricDistance) {
				cout << bucket << " " << get<1>(container);
				bucket = bucket * get<2>(container);
				cout << " = " << bucket << " " << get<3>(container) << endl;
			}
		}

		void convertOunces(int ounces) {
			double bucket = ounces * get<0>(USWeight[0]);
			for (auto& container : USWeight) {
				cout << bucket << " " << get<1>(container);
				bucket = bucket * get<2>(container);
				cout << " = " << bucket << " " << get<3>(container) << endl;
			}

			bucket = ounces * get<0>(MetricWeight[0]);
			for (auto& container : MetricWeight) {
				cout << bucket << " " << get<1>(container);
				bucket = bucket * get<2>(container);
				cout << " = " << bucket << " " << get<3>(container) << endl;
			}
		}

		void convertVolumeOunces(int ounces) {
			double bucket = ounces * get<0>(USVolume[0]);
			for (auto& container : USVolume) {
				cout << bucket << " " << get<1>(container);
				bucket = bucket * get<2>(container);
				cout << " = " << bucket << " " << get<3>(container) << endl;
			}

			bucket = ounces * get<0>(MetricVolume[0]);
			for (auto& container : MetricVolume) {
				cout << bucket << " " << get<1>(container);
				bucket = bucket * get<2>(container);
				cout << " = " << bucket << " " << get<3>(container) << endl;
			}
		}

};



int main() {

	OverallMeasurements example;

	cout << "Converting 10,000 inches" << endl;
	example.convertInches(10000);

	cout << endl << "Converting 100 ounces - weight" << endl;
	example.convertOunces(100);

	cout << endl << "Converting 100 ounces - volume" << endl;
	example.convertVolumeOunces(100);


	cin.get();
	return 0;
}