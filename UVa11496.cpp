#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lloop(i, a, b) for(ll i=a;i<(ll)b; i++)
#define loop(i, a, b) for(int i=a;i<b;i++)

int countLocalExtremes(const vector<int>& arr) {
  int numExtremes = 0;

  loop(i, 1, arr.size()-1) {
    if ((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ||
        (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])) {
      numExtremes++;
    }
  }

  return numExtremes;
}


int main(){
	int size;
  	vector<int> arr;
	 while (1) {
    scanf("%d", &size);
    if (!size) {
      break;
    }
    arr.assign(size + 2, 0);
    for (int i = 1; i <= size; ++i) {
      scanf("%d", &arr[i]);
    }
    // Musical loop
    arr[0] = arr[size];
    arr[size + 1] = arr[1];

    printf("%d\n", countLocalExtremes(arr));
  }
	return 0;
}