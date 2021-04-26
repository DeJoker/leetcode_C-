

#ifndef __STRING_HELPER_H
#define __STRING_HELPER_H

#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <stdarg.h>
using namespace std;

namespace strHelper
{

inline void Replace(string& data, const char src, const char dst)
{
	if (src == dst)
		return;
	for(string::iterator it = data.begin(); it != data.end(); it++)
	{
		if(*it == src)
		{
			*it = dst;
		}
	}
}

inline void Replace(string& data, const string& src, const string& dst)
{
	if (src == dst || src.empty())
		return;

	string::size_type pos = data.find(src);
	while(pos != std::string::npos)
	{
		data.replace(pos, src.size(), dst);
		pos = data.find(src, pos + dst.size());
	}
}

inline void Trim(string& data, const char ch = ' ')
{
	string::size_type lpos = data.find_first_not_of(ch);
	if(lpos != string::npos)
	{
		data.erase(0,lpos);
	}
	string::size_type rpos = data.find_last_not_of(ch);
	if(rpos != string::npos)
	{
		data.erase(rpos + 1);
	}
}

inline void Trim(string& data, const string& str = " ")
{
	string::size_type lpos = data.find_first_not_of(str);
	if(lpos != string::npos)
	{
		data.erase(0,lpos);
	}
	string::size_type rpos = data.find_last_not_of(str);
	if(rpos != string::npos)
	{
		data.erase(rpos + 1);
	}
}

inline void TrimLeft(string& data, const char ch = ' ')
{
	string::size_type pos = data.find_first_not_of(ch);
	if(pos != string::npos)
	{
		data.erase(0,pos);
	}
}

inline void TrimLeft(string& data, const string& str = " ")
{
	string::size_type pos = data.find_first_not_of(str);
	if(pos != string::npos)
	{
		data.erase(0,pos);
	}
}

inline void TrimRight(string& data, const char ch = ' ')
{
	string::size_type pos = data.find_last_not_of(ch);
	if(pos != string::npos)
	{
		data.erase(pos + 1);
	}
}

inline void TrimRight(string& data, const string& str = " ")
{
	string::size_type pos = data.find_last_not_of(str);
	if(pos != string::npos)
	{
		data.erase(pos + 1);
	}
}

inline void ToUper(string& data)
{
	std::transform(data.begin(), data.end(), data.begin(), ::toupper);
}

inline void ToLower(string& data)
{
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
}

inline vector<string> Split(const string& data, const char ch)
{
	vector<string> vec;
	if (data.empty() || ch==0)
		return vec;

	string::size_type cur = 0;
	string::size_type pos = data.find(ch);
	while(pos != std::string::npos)
	{
		string s = data.substr(cur, pos - cur);
		vec.push_back(s);
		cur = pos + 1;
		pos = data.find(ch, cur);
	}

	string s = data.substr(cur, data.size() - cur);
	vec.push_back(s);

	return vec;
}

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

inline string Left(const string& data, int pos)
{
	if (pos < 0)
	{
		pos = 0;
	}
	if (pos > (int)data.size())
	{
		pos = data.size();
	}
	return data.substr(0, pos);
}

inline string Right(const string& data, int pos)
{
	if (pos < 0)
	{
		pos = 0;
	}
	if (pos > (int)data.size())
	{
		pos = data.size();
	}
	return data.substr(data.size() - pos, pos);
}

inline int Count(const string& data, const char c)
{
	int n(0);
	for (int i = 0; i < (int)data.size(); i++)
	{
		if (c == data[i])
		{
			n++;
		}
	}
	return n;
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

inline string ToString(const char* pszFmt,...)
{
	va_list argList;
	int size(1024);
	char* buf = new char[size+1];
	while(size > 0 && size < 1024*1024*10)
	{
		va_start(argList, pszFmt);
		int len = vsnprintf(buf, size + 1, pszFmt, argList);
		va_end(argList);
		if (len >= 0 && len <= size)
		{
			buf[len] = '\0';
			break;
		}
		if(len < 0)
			size *= 2;
		else
			size = len;

		delete[] buf;
		buf = new char[size + 1];
		buf[0] = '\0';
	}
	string str(buf);
	delete[] buf;
	return str;
}

inline string ToHexString(const char* data,const int len)
{
	char* buf = new char[len*3+1];
	for(int i = 0; i < len; i++)
	{
		sprintf(buf+i*3,"%.2X ",(unsigned char)data[i]);
	}
	buf[len*3] = 0;
	string str(buf);
	delete[] buf;
	return str;
}

inline string ToHexString(const string& data)
{
	return ToHexString(data.data(), (int)data.size());
}

inline string ToDecString(const char* data,const int len)
{
	char* buf = new char[len*3+1];
	for(int i = 0; i < len; i++)
	{
		sprintf(buf+i*3,"%d ",(unsigned char)data[i]);
	}
	buf[len*3] = 0;
	string str(buf);
	delete[] buf;
	return str;
}

inline string ToDecString(const string& data)
{
	return ToDecString(data.data(), (int)data.size());
}

}


#endif


