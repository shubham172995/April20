#include<bits/stdc++.h>


using namespace std;


int t, rx, ry, p[45], b, x, y;

vector<char> ans;


int main() {

	p[0] = 1;
	
	for (int i = 1; i <= 40; i++) 
		p[i] = p[i - 1] * 2;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {

		scanf("%d%d", &rx, &ry);

		b = 0;

		ans.clear();

		for (int j = 0; j <= 40; j++) {

			x = rx;

			y = ry;

			ans.clear();

			for (int k = j; k >= 0; k--) {

				if (abs(x) > abs(y)) {

					if (x > 0) {

						ans.push_back('E');
	
						x -= p[k];

					}

					else {

						ans.push_back('W');

						x += p[k];

					}

				}

				else {

					if (y > 0) {

						ans.push_back('N');
	
						y -= p[k];

					}

					else {

						ans.push_back('S');

						y += p[k];

					}

				}

				//printf("%d %d\n", x, y);

			}

			reverse(ans.begin(), ans.end());

			if (x == 0 && y == 0) {

				b = 1;

				printf("Case #%d: ", i + 1);
	
				for (int k = 0; k < ans.size(); k++) printf("%c", ans[k]);

				printf("\n");

				break;

			}

		}

		if (!b) printf("Case #%d: IMPOSSIBLE\n", i + 1);

	}
}