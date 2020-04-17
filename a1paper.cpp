#include <iostream>
#include <math.h>
using namespace std;

double tape(int size, int sheetsRequired, int sizeLimit,int sheets[]){
    int sheetsAvailable;
    double length;
    
    length = pow(2.0, (0.25 - size / 2.0)) * (sheetsRequired / 2.0);
    
    if(size > sizeLimit)
        return 0;
    
    sheetsAvailable = sheets[size - 2];
    
    if(sheetsAvailable >= sheetsRequired){
        return length;
    }
    
    else{
        double extra = tape(size+1, (sheetsRequired - sheetsAvailable)*2, sizeLimit, sheets);
        
        if(extra == 0)
            return 0;
        
        else
            return extra + length;
    }
}

int main(){
    int sizeLimit, sheets[30];
    int size, sheetsRequired;
    double result;
    
    cin >> sizeLimit;
    
    for(int i=0;i<sizeLimit;i++)
        cin >> sheets[i];
    
    result = tape(2,2,sizeLimit,sheets);
    
    if(result == 0)
        cout << "impossible\n";
    else{
        cout.precision(12);
        cout << result << '\n';
    }
}