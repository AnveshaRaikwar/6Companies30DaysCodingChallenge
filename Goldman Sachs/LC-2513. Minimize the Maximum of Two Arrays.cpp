class Solution {
public:
    long gcd(long a,long b){
        if((a%b)==0){
            return b;
        }
        else{
            return gcd(b,a%b);
        }
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long g = gcd(max(divisor1,divisor2), min(divisor1,divisor2));
        long lcm = (long (divisor1) * long(divisor2))/g;

        long ans = 1000000000;
        long l=1, h=2e9;

        while(l<=h){
            long m = (l+h)/2;
            long a,b,c;

            a = m-(m/divisor1);
            b = m-(m/divisor2);
            c = m-(m/divisor1)-(m/divisor2)+(m/lcm);

            if(a >= uniqueCnt1 && b >= uniqueCnt2 && a+b-c >= (uniqueCnt1+uniqueCnt2)){
                ans=m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        
        return int(ans);
    }
};