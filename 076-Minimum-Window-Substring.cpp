#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

string  minWindow(string s, string t)
{
    unordered_map<char, int> hash;
    int num = t.size(), len = INT_MAX, start = 0, left = 0;

    for(auto val : t) hash[val]++;

    for(int i = 0; i < s.size(); ++i)
    {
        if(hash[s[i]]-- > 0) num--;
        while(num == 0)
        {
            len = (i - left + 1) < len ? (i - (start = left) + 1) : len;
            if(hash[s[left++]]++ == 0) num++;
        }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
}

int main()
{
    string s,t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}
/*
ADOBECODEBANC
ABC
*/

/*
** unordered_map
** uses C++ 11
** select that in compiler
*/

/*
** hash��ʼֵ�� ��T�г��ֹ���ΪT�г��ֵĴ���
** T��û�еģ�S�еģ�����ֵΪ0
** ����S
** ����һ���ַ������ַ���Ӧhash��value - 1
** S���еģ�T��û�еģ�hash���Ϊ����
** T���еģ�hash����S�о������ַ����г��ָ��ַ��ĸ���
** ��Ϊ0����ʾ�ö��ַ����԰���T�����еĸ��ַ�
** ���������ַ���hash���Ϊ��������Ϊ����Ҫ���ַ�
** num: ��hash Ϊ����֤���ҵ�һ���������T�е��ַ���num - 1
** ���num�����ܹ��ж����ַ���������Ҫ���������ǲ��������������ַ���
** ��Ҳ���ܹ���O(1)ʱ�����жϵ�ǰ�����ǲ��Ǹ����ˣԵĹؼ�
** �������ܵ�����Ϊ����ʱ�����Ǿ��ҵ���һ�����ǣԵ��Ӵ����ڣ�
****************************
** �ų���˲���Ҫ�ַ���
** ���������Ϊ��˿��ܰ�����һЩ����Ҫ���ַ���
** ���������Ҫ�����ڵ���������ƶ���ʹ�����ð����ԣ�
** �ڴ�����������ƶ��Ĺ�������Ҫ�������ַ���hash���У�����
** ����Ҫ���ַ�����hash��Ӹ�����ʼ��
** �����ǰ�ַ���hash���еļ���Ϊ�������������������ˣ�
** ˵������ַ��ǳ����ڣ��еģ����numҪ��һ��
****************************
** ����������S�����ҵ�len��С��start,len
*/
