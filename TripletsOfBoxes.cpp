int solve(vector<int> &A, vector<int> &B){
	int ans=0, n=A.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				int s1, s2;
				s1=A[i]+A[j]+A[k];
				s2=B[i]+B[j]+B[k];
				if(s1<s2)
					++ans;
			}
		}
	}
	return ans;
}