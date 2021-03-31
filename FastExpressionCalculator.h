// Happy April Fools' Day
#ifndef FAST_EXPRESSION_CALCULATOR_H

#define FAST_EXPRESSION_CALCULATOR_H

#include <string>
#include <fstream>
#include <cstdlib>

std::string eval(std::string x){
	std::string ret;
	std::ofstream oup("calculator.py");
	oup << ("fo = open(\"result.txt\", \"w\")\n");
	oup << "fo.write(str(eval(\"" << x << "\")))\n";
	oup << ("fo.close()");
	oup.close();
	system("python calculator.py");
	std::ifstream red("result.txt");
	red >> ret;
	red.close();
	system("rm calculator.py");
	system("rm result.txt");
	return ret;
}

#endif
