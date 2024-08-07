class Solution {
public:
    string nametriplet(int n,vector<string> &words,vector<string> &tens){
        
        string res="";
        int a = n%10;
        int b = n%100;
        
        if(n/100 > 0){
            res+= words[n/100-1] + "Hundred ";
        }
        n=n%100;
        if(n/10 ==1){
            res+=words[n-1] ;
            return res;
        }else if (n/10 >1){
            res+=tens[n/10 -2];
        }
        n=n%10;
        
        if(n>0)
            res+=words[n-1];
        
        return res;
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string number="";
        vector<string> words = {"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine ","Ten ","Eleven ","Twelve ",
"Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
        vector<string> tens = {"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
        
        vector<string> biggies = {"Thousand ","Million ","Billion "};
        
        vector<string> array;
        int temp = num,digs=0,trip=0,pow=1;
        while(temp!=0){
            trip +=  (temp%10)*pow;
            temp/=10;
            pow*=10;
            digs++;
            
            if((digs==3 || temp==0) ){
                array.push_back(nametriplet(trip,words,tens));
                digs=0;
                pow=1;
                trip=0;
            }
        }
        reverse(array.begin(),array.end());
        
        int st=0;
        for(int i=array.size()-2;i>=0;i--){
            if(array[i]!="")
            array[i]+=biggies[st];
            st++;
        }
        
        for(int i=0;i<array.size();i++){
            number+=array[i];
        }
        number.pop_back();
        
        return number;
    }
};