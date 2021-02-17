#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


std::string time_format(long int time, std::string format) {

	std::stringstream ss;
	ss << std::put_time(std::localtime(&time), format.c_str());
	return (ss.str());

};


int main() {

	unsigned int n = input("enter n: ");

	auto now = std::chrono::system_clock::now();
	auto time_sec = std::chrono::system_clock::to_time_t(now);

	std::cout << "time now: " << time_sec << "s\t" << time_format(time_sec, "%Y-%m-%d %X") << '\n';
	time_sec += n;
	std::cout << "time in " << n << "s:" << time_sec << "s\t" << time_format(time_sec, "%Y-%m-%d %X") << '\n';

	return (0); // :) C++11 ...

};
