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

	//小于号的重载
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
	//等于号的重载
	bool operator==(const Date& d)
	{
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	//大于等于号的重载，可利用复用性
	bool operator>=(const Date& d)
	{
		return !(*this<d);
	}
	//大于号的重载
	bool operator>(const Date& d)
	{
		return !(*this < d||*this ==d);
	}
	//小于等于号的重载
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
	//加一个天数，自动跳转应到的日期
	Date operator+(int day)
	{
		Date& tmp = *this;
		//如果天数为负数，则可以看作是减一个天数
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
	//实现一个天数的相减，返回一个DATE类
	Date operator-(int day)
	{
		Date& tmp = *this;
		
		//如果天数小于零，可以看作是加一个天数
		if (day < 0)
		{
			return *this + (-day);
		}
		_day -= day;//若day>_day,得数则为负
		while (isInvaild()==false)//思考为什么判断为错误时进循环？？
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
			tmp._day =tmp. _day + tmp.getMonthDay(_year, _month);//加上一个数时
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
	Date operator++()//前置加加
	{
		*this = *this + 1;
		return *this;
	}
	Date operator++(int)//后置加加
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	Date operator--()//前置减减
	{
		*this = *this - 1;
		return *this;
	}
	Date operator--(int)//后置减减
	{
		Date tmp = *this;
		*this = *this - 1;
		return tmp;
	}
	int operator-(const Date& d)//一个日期减上一个日期是多少天
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


