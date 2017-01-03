#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("A-large-practice.in", "r", stdin);
    freopen("outs.out", "w", stdout);

    int T, N, A, osmos[103], ans;

    cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        cin >> A >> N;

        for (int i = 0; i < N; i++)
            cin >> osmos[i];

        if (A == 1) {
            cout << "Case #" << cases << ": " << N << endl;
            continue;
        }
        
        sort(osmos, osmos + N);

        ans = N;
        for (int j = N; j >= 0; j--) {
            int currentSize = A;
            int counter = 0;

            for (int i = 0; i < j; i++) {
                if (currentSize > osmos[i])
                    currentSize += osmos[i];
                else {
                    while (currentSize <= osmos[i]) {
                        counter++;
                        currentSize += (currentSize - 1);
                    }

                    currentSize += osmos[i];
                }
            }

            ans = min(ans, counter + N - j);
        }

        cout << "Case  #" << cases << ": " << ans << endl;
    }
}
