// Happy April Fools' Day
#ifndef FAST_EXPRESSION_CALCULATOR_H

#define FAST_EXPRESSION_CALCULATOR_H

#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

std::string eval(std::string x){
	std::string ret="";
	std::ofstream oup("calculator.py");
	oup << ("fo = open(\"result.txt\", \"w\")\n");
	for(int i=0;i<(int)x.size();i++)
		if(x[i]=='\"')	ret+="\\\"";
		else	ret+=x[i];
	x=ret;
	oup << ("import math\n");
	oup << "fo.write(str(eval(\"" << x << "\")))\n";
	oup << ("fo.close()");
	oup.close();
	system("python calculator.py");
	std::ifstream red("result.txt");
	std::stringstream buffer;
	buffer << red.rdbuf();
	ret=buffer.str();
	red.close();
	system("rm calculator.py");
	system("rm result.txt");
	return ret;
}

#endif
