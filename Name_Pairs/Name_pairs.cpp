#include"name_pair.h"

using namespace std;

void name_pair::print() {
	if (age.size() != name.size())error_msg("size of age and name are not equal");
	for (vector<string>::size_type i = 0; i < name.size(); ++i)
		cout << "(" << name.at(i) << " : " << age.at(i) << " )\n";
}

void name_pair::print() const {
	if (age.size() != name.size())error_msg("size of age and name are not equal");
	for (vector<string>::size_type i = 0; i < name.size(); ++i)
		cout << "(" << name.at(i) << " : " << age.at(i) << " )\n";
}

void name_pair::sort() {
	bool check = true;
	vector<string>tmp_nam = name;
	vector<double>tmp_ag = age;
	if (age.size() != name.size())error_msg("size of age and name are not equal");
	while (check) {
		check = false;
		for (vector<string>::size_type i = 0; i < tmp_nam.size()-1; ++i) {
			if (strcmp(tmp_nam.at(i).c_str(), tmp_nam.at(i + 1).c_str()) > 0) {
				swap(tmp_nam.at(i), tmp_nam.at(i + 1));
				swap(tmp_ag.at(i), tmp_ag.at(i + 1));
				check = true;
			}
		}
	}
	name = tmp_nam;
	age = tmp_ag;
}

istream& operator>>(istream& st, name_pair& n) {
	double a;
	string s;
	char ch = 0;
	cout << "Please enter name of your choice or 'q' to exit\n";
	st >> ch;
	if (!st)return st;

	if (ch == 'q') {
		st.clear(ios_base::failbit);
		return st;
	}
	st.unget();
	st >> s;
	if (!st)return st;

	cout << "Please enter age of your choice\n";
	st >> a;
	if (!st)return st;

	n.set_age(a);
	n.set_name(s);

	return st;
}

ostream& operator<<(ostream& st, name_pair& n) {

	if (n.size() != n.size())error_msg("size of age and name are not equal");
	for (vector<string>::size_type i = 0; i < n.size(); ++i)
		st << "(" << n.get_name(i) << " : " << n.get_age(i) << " )\n";

	return st;
}

bool operator==(name_pair& a, name_pair& b) {

	if (a.size() != b.size())error_msg("vector sizes not equal");

	for (int i = 0; i < a.size(); ++i) {
		if(a.get_age(i) != b.get_age(i) || a.get_name(i) != b.get_name(i))
			return false;
	}
	return true;
}

bool operator!=(name_pair& a, name_pair& b) {

	if (a.size() != b.size())error_msg("vector sizes not equal");

	for (int i = 0; i < a.size(); ++i) {
		if (a.get_age(i) != b.get_age(i) || a.get_name(i) != b.get_name(i))
			return true;
	}
	return false;
}


