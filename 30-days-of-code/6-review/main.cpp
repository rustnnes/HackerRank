#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    string* x = new string[n];
    for(int i = 0; i < n ; i++){
        cin >> x[i];
        string aux (x[i]);
		int l = aux.length();
		for(int j = 0, k = 0; j < l; j++)
			x[i][k++] = aux[j++];
		x[i].resize(1, ' ');
		for(int j = 0, k = 0; j < l; j++)
			x[i][k++] = aux[j++];
    }
	for (int i = 0; i < n; i++) cout << x[i] << endl;

    delete[] x;
    return 0;
}

/*
int main() {
    string x ("hacker");
    //string aux (x.length(), ' ');
	int l = x.length();
	for(int i = 0; i < l; i++) cout << x[i++];
	cout << ' ';
	for(int i = 1; i < l; i++) cout << x[i++];
	cout << endl;
	//for(int i = 1; i < l; i+2) cout << x[i] << endl;

    return 0;
}

*/
