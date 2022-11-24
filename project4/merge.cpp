#include <iostream>
#include <string.h>
using namespace std;

bool DP[2001][2001];

bool InterleaveCheck(string s1, string s2, string s3) {
int s1_len = s1.length();
int s2_len = s2.length();
for(int i = 0; i <= s1_len; i++) {
	for(int j = 0; j <= s2_len; j++) {
		if( !i && !j)   {
			DP[i][j] = true;
		}

		else if(i && j && s1[i - 1] == s3[i + j -1] && s2[j -1] == s3[i + j - 1]) {
		DP[i][j] = DP[i-1][j] || DP[i][j-1];
		}
		else if( i && s1[i -1] == s3[i+j -1]) {
			DP[i][j] = DP[i-1][j];
		}
			else if(j && s2[j-1] == s3[i+j-1]) {
			DP[i][j] = DP[i][j-1];
			}

}
}
return DP[s1_len][s2_len];


}

bool isInterleaving(string X, string Y, string S) {
  int M = X.size();
  int N = Y.size();
 bool T[M + 1][N + 1];
  if (M + N != S.size()) {
    return false;
  }
 
  
 
  for (int i = 0; i < M; i++) {
    for (int j = 0; j <  N; j++) {
      if (i == 0 && j == 0) {
        T[i][j] = true;
      } else if (i and j and X[i - 1] == S[i + j - 1] and Y[j - 1] == S[i + j - 1]) {
        T[i][j] = T[i - 1][j] || T[i][j - 1];
      } else if (i and X[i - 1] == S[i + j - 1]) {
        T[i][j] = T[i - 1][j];
      } else if (j and Y[j - 1] == S[i + j - 1]) {
        T[i][j] = T[i][j - 1];
      }
    }
  }
  return T[M][N];
}



int main() {
string s1 = "zzzzzzzzzzzzzzzzzzzzabc";
string s2 = "zzzzzzzzzzzzzzzzzzzzacb";
string s3 = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzabcbac";
cout << InterleaveCheck(s1, s2, s3) << endl;




}
