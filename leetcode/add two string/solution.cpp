class Solution {
public:
string helper(string& s,int i,string& t,int j,int carry){

if(i<0 && j<0){
           if(carry!=0){
               string s=to_string(carry);
               return s;
           }
           return "";
       }
       int a,b;
       if(i>=0)
       {
           a=s[i]-'0';
       }
       else
       {
           a=0;
       }
        if(j>=0)
       {
           b=t[j]-'0';
       }
       else
       {
           b=0;
       }
       int sum=a+b+carry;
       int last=sum%10;
       carry=sum/10;
       string ans="";
       ans+=to_string(last);
       ans+=helper(s,i-1,t,j-1,carry);
       return ans;
    }
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;
        int j=num2.length()-1;

        string ans=helper(num1,i,num2,j,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
