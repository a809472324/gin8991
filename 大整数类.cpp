#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class BigInteger
{
public:
	string num;
	BigInteger(string num)
	{
		this->num = num;
	}
	void add(string adder)
	{
		string temp;
		if (adder.length()>num.length())
			swap(adder,num);
		reverse(adder.begin(),adder.end());
		reverse(num.begin(),num.end());
		int len = adder.length();
		int carry = 0;
		int i;
		for (i=0;i<len;i++){
			int res = adder[i]-'0'+num[i]-'0'+carry;
			carry=0;
			if (res>=10)
				carry = 1;
			temp += res%10+'0';
		}
		while (carry&&i!=num.length()){
			int res = num[i]-'0'+carry;
			carry=0;
			if (res>=10)
				carry=1;
			temp += res%10+'0';
			i++;
		}
		if (carry&&i==num.length())
			temp+='1';
		if (!carry&&i!=num.length()){
			temp+=num.substr(i,num.length());
		}
//		else if (i!=num.length())
//			temp+=num.substr(i,num.length());
		num = temp;
		reverse(num.begin(),num.end());
	}
};

int main()
{
	BigInteger m("32176");
	m.add("364");
	m.add("78");
	cout<<m.num;
}
