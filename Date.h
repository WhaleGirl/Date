#include<iostream>
using namespace std;
#include<assert.h>
class Date
{
public :

	Date(int year = 1900,int month = 1,int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		assert(isInvaild());
	}
	void print()
	{ 
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int getMonthDay(int year,int month)
	{
		static int MonthDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		if (month==2 && (year%4==0 && (year%100!=0))||(year%400==0))
		{
			return 29;
		}
		return MonthDay[month];
	}

	bool isInvaild()
	{
		if (_day > 0 && _day <= getMonthDay(_year,_month) && _month<13 && _month>0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isLeap()
	{
		if ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//С�ںŵ�����
	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			if (_month<d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
				else
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	//���ںŵ�����
	bool operator==(const Date& d)
	{
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	//���ڵ��ںŵ����أ������ø�����
	bool operator>=(const Date& d)
	{
		return !(*this<d);
	}
	//���ںŵ�����
	bool operator>(const Date& d)
	{
		return !(*this < d||*this ==d);
	}
	//С�ڵ��ںŵ�����
	bool operator<=(const Date& d)
	{
		return !(*this>d);
	}
	//d1!=d2
	bool operator!=(const Date& d2)
	{
		return !(*this == d2);
	}
	//
	//��һ���������Զ���תӦ��������
	Date operator+(int day)
	{
		Date& tmp = *this;
		//�������Ϊ����������Կ����Ǽ�һ������
		if (day<0)
		{
			return *this - (-day);
		}
		_day = day + _day;
		if (_day>tmp.getMonthDay(_year, _month))
		{
			_day -= tmp.getMonthDay(_year,_month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return tmp;
	}
	//ʵ��һ�����������������һ��DATE��
	Date operator-(int day)
	{
		Date& tmp = *this;
		
		//�������С���㣬���Կ����Ǽ�һ������
		if (day < 0)
		{
			return *this + (-day);
		}
		_day -= day;//��day>_day,������Ϊ��
		while (isInvaild()==false)//˼��Ϊʲô�ж�Ϊ����ʱ��ѭ������
		{
			if (_month == 1)
			{
				_year--;
				_month = 12;
			}
			else
			{
				_month--;
			}
			tmp._day =tmp. _day + tmp.getMonthDay(_year, _month);//����һ����ʱ
		}
		return tmp;
	}

	
	Date operator+=(int day)
	{
		*this = *this + day;
		return *this;
	}
	Date operator-=(int day)
	{
		*this = *this - day;
		return *this;
	}
	Date operator++()//ǰ�üӼ�
	{
		*this = *this + 1;
		return *this;
	}
	Date operator++(int)//���üӼ�
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	Date operator--()//ǰ�ü���
	{
		*this = *this - 1;
		return *this;
	}
	Date operator--(int)//���ü���
	{
		Date tmp = *this;
		*this = *this - 1;
		return tmp;
	}
	int operator-(const Date& d)//һ�����ڼ���һ�������Ƕ�����
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int month = 1; month < _month; month++)
		{
			sum1 += getMonthDay(_year, month);
		}
		sum1 += _day;

		for (int month = 1; month < d._month; month++)
		{
			sum2 += getMonthDay(_year, month);
		}
		sum2 += d._day;
		int sum = abs(sum1 - sum2);

		int tmp = 0;
		if (_year == d._year)
		{
			return sum;
		}

		else if (_year > d._year)
		{
			for (int year = d._year;year < _year;year++)
			{
				if (isLeap())
				{
					tmp += 366;
				}
				else
				{
					tmp += 365;
				}
			}
			return (tmp + sum);
		}
		else if (_year < d._year)
		{
			for (int year = _year; year < d._year; year++)
			{
				if (isLeap())
				{
					tmp += 366;
				}
				else
				{
					tmp += 365;
				}
			}
			return abs(tmp + sum);
		}
	}

private :
	int _year;
	int _month;
	int _day;
};

void test()
{
	//Date d1(2017,10,13);
	//d1.print();
	//Date d2(2017,10,3);
	//Date d3(2017,9,23);
	//Date d4 = d2 + 20;
	//Date d5 = d3 - 30;
	//d4.print();
	//d5.print();
	//cout << (d2 < d1) << endl;
	//cout << (d2 >= d1) << endl;
	//cout << (d2 > d1) << endl;
	//Date d;
	//cout<<d.getMonthDay(2017,2);
	//Date d6(2017, 10, 20);
	//d6 += 20;
	//d6.print();
	//d6 -= 20;
	//d6.print();
	//Date d7(2017, 10, 20);
	//Date d8 = d7++;
	//d8.print();
	Date d9(2016, 2, 20);
	Date d10(2017, 2, 28);
	cout<<(d9 - d10)<<endl;
}


