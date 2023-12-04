#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        vector<long long int> line(n);
        long long int parabola_a[m];
        long long int parabola_b[m];
        long long int parabola_c[m];
        for(int l=0;l<n;l++){
            cin>>line[l];
        }
        for(int p=0;p<m;p++){
            cin>>parabola_a[p];
            cin>>parabola_b[p];
            cin>>parabola_c[p];
        }
        sort(line.begin(),line.end());
        // solution
        for(int bb=0;bb<m;bb++){// parabola iteration
        bool check=true;
        int b_para=parabola_b[bb];
        int b=min(abs(b_para-line[0]),abs(b_para-line[n-1]));
        int answer;
        if(b==abs(b_para-line[0])){
            answer=line[0];
        } else{
            answer=line[n-1];
        }
             // line iteration
                long long int a=parabola_a[bb];
                long long int c=parabola_c[bb];
               long long  int ans=(b*b - 4*a*c);
                if(ans<0){
                    cout<<"Yes\n";
                    cout<<answer<<endl;
                    check = false;
                }
            if(check==true){
                cout<<"No\n";
            }
            check=true;
        }
    }
    return 0;
}
