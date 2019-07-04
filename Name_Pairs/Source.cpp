

#include"name_pair.h"

using namespace std;

int main()
{

	char ch = 0;
	name_pair np, np1;
	try {
		while (cin >> np);

		if (np.size()) {
			np.sort();
			cout << np;
		}

		cout << "enter name pair for np1\n";

		cin.clear();
		while (cin >> np1);

		if (np1.size()) {
			np1.sort();
			cout << np1;
		}

		cout << ((np == np1) ? "they are equal" : "they are not equal") << endl;
		cout << ((np != np1) ? "they are not equal" : "they are equal") << endl;
	}

	catch (execution_error& e) {
		cerr << e.what() << endl;
	}
	catch (exception& i) {
		cerr << i.what() << endl;
	}



	keep_window_open("s");
	return 0;
}