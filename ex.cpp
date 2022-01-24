//g++ -g -O2 -std=c++11 -pthread -march=native ex.cpp -o ex -lntl -lgmp -lm 
//-lssl -lcrypto

#include <iostream>
#include <NTL/ZZ.h>
#include <openssl/sha.h>

using namespace std;
using namespace NTL;

class ExtendedEuclid{
    private:
        
        ZZ a,b; 
          
    public: 

        ExtendedEuclid(){
        }

        ExtendedEuclid(ZZ a, ZZ b){
            this->a = a;
            this->b = b;
        }

        void calc(ZZ& s, ZZ& t){
            ZZ s1 =ZZ(1), s2 =ZZ(0);
            ZZ t1 =ZZ(0), t2 =ZZ(1);
            ZZ r1 =a, r2 =b;
            
            while(r2 > 0){
                ZZ q = r1/r2;
                ZZ r = r1 - q*r2;
                r1 = r2;
                r2 = r;

                s = s1 - q*s2;
                s1 = s2;
                s2 = s;

                t = t1 - q*t2;
                t1 = t2;
                t2 = t;
            }
            s = s1;
            t = t1;
        }
};

int main(int argc, char** argv){
    ZZ s=ZZ(0),t=ZZ(0);
    ZZ a=ZZ(0),b=ZZ(0);

    cout << "a 값은?" <<endl;
    cin >> a;
    cout << "b 값은?" <<endl;
    cin >> b;

    ExtendedEuclid e(a,b);
    e.calc(s,t);

    cout << s << endl;
    cout << t << endl;

    return 0;
}