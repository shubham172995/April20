int solve(int A, conts vector<vector<int> > &B){
	vector<int> m(A, INT_MIN);
	m[0]=0;
	for(int i=0;i<A;i++){
		for(int j=i+1;j<=i+3;j++){
			if(j<A){
				m[j]=max(m[j], m[i]+B[i][j-i-1]);
			}
		}
	}
	int ans=0;
	if(A==1)
		ans=B[0][2];
	else if(A==2){
		ans=max(m[A-1]+B[A-1][2], m[A-2]+B[A-2][2]);
	}
	else{
		ans=max(m[A-1]+B[A-1][2], m[A-2]+B[A-2][2]);
		ans=max(ans, m[A-3]+B[A-3][2]);
	}
	return ans;
}