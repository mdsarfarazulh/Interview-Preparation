/* 
    Problem:    https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0
    Editorial:  https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/
*/
#include<bits/stdc++.h>
using namespace std;

#define LL long long int

char* utilRemove(char *str, char *last_remove){
    if(str[0] == '\0' || str[1] == '\0')
        return str;
    
    if(str[0] == str[1]){
        *last_remove = str[0];
        while(str[1] && str[0]==str[1])
            str++;
        ++str;
        return utilRemove(str, last_remove);
    }

    char *rem_str = utilRemove(str+1, last_remove);

    if(rem_str[0] && rem_str[0]==str[0]){
        *last_remove = str[0];
        return (rem_str+1);
    }

    if(rem_str[0] == '\0' && *last_remove==str[0]){
        return rem_str;
    }

    --rem_str;
    rem_str[0] = str[0];
    return rem_str;
}

void solve(){
    char str[500];
    scanf("%s",&str);
    char last_remove = '\0';
    cout<<utilRemove(str, &last_remove)<<endl;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tcases;
    cin>>tcases;
    while(tcases--)
        solve();
    return 0;
}