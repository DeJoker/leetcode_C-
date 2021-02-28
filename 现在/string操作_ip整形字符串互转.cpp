#include "../common/debugger.h"


inline vector<string> Split(const string& data, const string& str)
{
	vector<string> vec;
	if (data.empty() || str.empty())
		return vec;

	string::size_type cur = 0;
	string::size_type pos = data.find(str);
	while(pos != std::string::npos)
	{
		string s = data.substr(cur, pos - cur);
		vec.push_back(s);
		cur = pos + str.size();
		pos = data.find(str, cur);
	}

	string s = data.substr(cur,data.size() - cur);
	vec.push_back(s);

	return vec;
}


inline int Count(const string& data, const string& str)
{
	int n(0);
	if (str.empty())
		return n;

	string::size_type pos = data.find(str);
	while(pos != std::string::npos)
	{
		n++;
		pos = data.find(str, pos + str.size());
	}
	return n;
}


// static String int2ip(long ipInt) {
//     StringBuilder sb = new StringBuilder();
//     sb.append((ipInt >> 24) & 0xFF).append(".");
//     sb.append((ipInt >> 16) & 0xFF).append(".");
//     sb.append((ipInt >> 8) & 0xFF).append(".");
//     sb.append(ipInt & 0xFF);
//     return sb.toString();
// }

// public static long ipToLong(String strIp){   
//         long[] ip = new long[4];   
//         //先找到IP地址字符串中.的位置   
//         int position1 = strIp.indexOf(".");   
//         int position2 = strIp.indexOf(".", position1 + 1);   
//         int position3 = strIp.indexOf(".", position2 + 1);   
//         //将每个.之间的字符串转换成整型   
//          ip[0] = Long.parseLong(strIp.substring(0, position1));   
//          ip[1] = Long.parseLong(strIp.substring(position1+1, position2));   
//          ip[2] = Long.parseLong(strIp.substring(position2+1, position3));   
//          ip[3] = Long.parseLong(strIp.substring(position3+1));   
//         return (ip[0] << 24) + (ip[1] << 16) + (ip[2] << 8) + ip[3];   
//      }   

string IntToIp(int i) {
    int ip[4];
    ip[0] = (i>>24)&0xFF;
    ip[1] = (i>>16)&0xFF;
    ip[2] = (i>>8)&0xFF;
    ip[3] = (i)&0xFF;
    string res = to_string(ip[0])+"."+to_string(ip[1])+"."+to_string(ip[2])+"."+to_string(ip[3]);
    return res;
}

int IpToInt(string s) {
    vector<string> ips = Split(s, ".");
    vector<int> ints;
    for(auto p : ips) {
        ints.push_back(atoi(p.c_str()));
    }
    return (ints[0]<<24) + (ints[1]<<16) + (ints[2]<<8) + ints[3];
}


int main() {
    LOG_DEBUG << IntToIp(2);
    LOG_DEBUG << IntToIp(INT_MAX);
    LOG_DEBUG << IntToIp(-1); // 0xFFFFFFFF
    LOG_DEBUG << IntToIp(0xFFFFFFFF);

    LOG_DEBUG << IpToInt("255.255.255.255");
}
