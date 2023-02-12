#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
string s;
vector<string>ans;
int f[26];

void rec(string cur){
    if(cur.size()==s.size()){
        ans.push_back(cur);
        return;
    }
    for(int i=0;i<26;i++){
        if(f[i]>0){
            f[i]--;
            rec(cur+(char)('a'+i));
            f[i]++;
        }
    }
}

int main() {
    cin>>s;
    for(int i=0;i<s.size();i++){
        f[s[i]-'a']++;
    }
    rec("");
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    

	
	return 0;

}
