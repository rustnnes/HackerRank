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
