#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int numeros[n];
    for(int i=0; i<n; i++) {
        cin >> numeros[i];
    }
    
    int mcm = numeros[0];
    for(int i=1; i<n; i++) {
        mcm = lcm(mcm, numeros[i]);
    }
    
    cout<< mcm << endl;
    
    return 0;
}
