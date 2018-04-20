class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int *uglyNumber = new int[n];
                int pNextIndex=1;  
                uglyNumber[0] = 1;  
                int *pM2 = uglyNumber;  
                int *pM3 = uglyNumber;  
                int *pM5 = uglyNumber;  
                
                while(pNextIndex < n){  
                    int min = getMin(*pM2 * 2,*pM3 * 3, *pM5 * 5);  
                    uglyNumber[pNextIndex] = min;  
                    while(*pM2 * 2 <= uglyNumber[pNextIndex])  
                        ++pM2;  
                    while(*pM3 * 3 <= uglyNumber[pNextIndex])  
                        ++pM3;  
                    while(*pM5 * 5 <= uglyNumber[pNextIndex])  
                        ++pM5;  
                    pNextIndex ++;
                }
                return uglyNumber[n-1];
        }
    
    int getMin(int a, int b, int c){
        int min = b>a ? a:b;
        return min>c ? c:min;
    }
};
