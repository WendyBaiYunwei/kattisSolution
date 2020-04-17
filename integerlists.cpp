#include <bits/stdc++.h>

//change to vector
//reverse and drop
using namespace std;

int main(){
    int cases,total,k,count,error,count2;
    string s, num, input;
    int temp2;
    deque<int> input2;
    
    cin >> cases;
    
    while(cases--){
        cin >> s >> total >> input;
        k=count=error=count2=0;
        input2.clear();
        
        //create a vector without extra stuffs
        for(int m = 1;count<total; m++){
            char temp[4];
            int j = 0;

            int mDown = 0;
            
            while(input[m]!=','&&input[m]!=']'){
                temp[j++]=input[m++];
                mDown = 1;
            }
            
            if(mDown == 1){
                m--;
                count++;
            }
            
            
            temp[j] = '\0';
            
            if(mDown == 1){
                temp2 = atoi(temp);
                input2.push_back(temp2);
            }
        }
        
        /*for(auto j:input2)
            cout<<j<<' ';*/
        
        //deal with it accordingly
        for(int i = 0; s[i]!='\0';i++){
            if(s[i]=='R')
                count2++;
            
            if(s[i]=='D'){
                if(total<=0){
                    cout << "error\n";
                    error = 1;
                    break;
                }
                
                else{
                    if(count2%2==0)
                        input2.pop_front();
                    else if(count2%2==1)
                        input2.pop_back();
                    total--;
                }
            }
        }
        
        if(count2%2==1)
            reverse(input2.begin(),input2.end());
        
        if(error == 0){
            cout << '[';
            for(int m=0;m<total-1;m++)
                cout << input2[m] << ',';
            if(total>0)
                cout << input2[total-1] ;
            cout << ']' <<'\n';
        }
    }
}