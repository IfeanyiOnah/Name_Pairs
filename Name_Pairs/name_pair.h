//this program is a name-pair class holding pairs where name is string and age is double
#ifndef NAME_PAIR_H_
#define NAME_PAIR_H_


#include "exception_header.h"
#include<vector>

class name_pair {
public:
	name_pair() {}
	~name_pair() {}

	//modifiable function
	void set_age(double& n) { age.push_back(n); }
	void set_name(std::string& s) { name.push_back(s); }
	void read_age() {
		double a;
		std::cin >> a;
		if (!std::cin)error_msg("unable to read age from cin");
		age.push_back(a);
	}

	void read_name() {
		std::string s;
		std::cin >> s;
		if (!std::cin)error_msg("unable to read name from cin");
		name.push_back(s);
	}

	void sort();
	//non_modifiable function
	void print();
	void print() const;

	double& get_age(int i) { return age.at(i); }
	const double& get_age(int i)const { return age.at(i); }

	std::string& get_name(int i) { return name.at(i); }
	const std::string& get_name(int i)const { return name.at(i); }


	int size() { return age.size(); }
	int size() const { return age.size(); }
private:
	std::vector<std::string> name;
	std::vector<double> age;

};

std::ostream& operator<<(std::ostream& st, name_pair& n);

bool operator==(name_pair& a, name_pair& b);

bool operator!=(name_pair& a, name_pair& b);


std::istream& operator>>(std::istream& st, name_pair& n);


#endif // !NAME_PAIR_H_
