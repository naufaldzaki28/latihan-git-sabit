#include <iostream>
using namespace std;

int main() {
    int a[] = {2, 2, 2, 2};
    int n = sizeof (a)/sizeof (a[0]);
    bool sama = true;
    for (int i=1; i<n; i++){
    if (a[i] != a[0]){
        sama = false;
        break;
    }
}    
    if (sama) {
        cout << "nilai a sama";
    } else {
        cout << "nilai a tidak sama";
    }
    return 0;
}