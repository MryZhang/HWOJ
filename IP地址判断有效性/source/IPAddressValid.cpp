#include "IPAddressValid.h"
#include "stdio.h"

bool isIPAddressValid(const char* pszIPAddr)
{
	// ���ڴ˴�ʵ��
	const char* start = pszIPAddr;
	const char* end = 0;
	const char* temp = 0;

	// ����ַ�����ʼ��ַ��Ϊ0
	if (!start)
	{
		return false;
	}

	// �����ַ���ǰ��Ŀո�
	while (*start)
	{
		if (*start == ' ')
		{
			start++;
		}
		else
		{
			break;
		}
	}
	for (end = start; *end; end++)
		;
	end--;
	while (end != start)
	{
		if (*end == ' ')
		{
			end--;
		} 
		else
		{
			break;
		}
	}

	// ȷ��start��end֮��ȫΪ���ּ���ָ���
	for (temp = start; temp <= end; temp++)
	{
		if ((*temp < '0' || *temp > '9') && *temp != '.')
		{
			return false;
		}
	}

	// ȷ������3����ָ���
	int dots=0;
	for (temp = start; temp <= end; temp++)
	{
		if (*temp == '.')
		{
			dots++;
		}
	}
	if (dots!=3)
	{
		return false;
	}

	// ȷ��ÿ���ַ�����Ϊ���Ҷ�Ӧ��ֵ������255
	int len=0,sum=0;
	for (temp = start; temp <= end; temp++)
	{
		if (*temp != '.'  && temp != end)
		{
			len++;
			continue;
		}

		if (*temp == '.' && temp == end)
		{
			return false;
		}

		if (temp == end)
		{
			len++;
			temp++;
		}

		if (len == 0 || len > 3)
		{
			return false;
		}
		
		// ȷ���Ӷγ��ȴ���1ʱ����0��ͷ
		if (len >1 && *(temp - len) == '0')
		{
			return false;
		}
		else
		{
			sum = 0;
			while (len)
			{
				sum *= 10;
				sum += *(temp-len) - '0';
				len--;
			}
			if (sum > 255)
			{
				return false;
			}
		}
	}

	return true;
}