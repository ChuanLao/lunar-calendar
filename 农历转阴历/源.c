#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int LunarInfo[201] =
{
	//1900年到2099年农历数据
	0x04BD8, 0x04AE0, 0x0A570, 0x054D5, 0x0D260, 0x0D950, 0x16554, 0x056A0, 0x09AD0, 0x055D2,
	0x04AE0, 0x0A5B6, 0x0A4D0, 0x0D250, 0x1D255, 0x0B540, 0x0D6A0, 0x0ADA2, 0x095B0, 0x14977,
	0x04970, 0x0A4B0, 0x0B4B5, 0x06A50, 0x06D40, 0x1AB54, 0x02B60, 0x09570, 0x052F2, 0x04970,
	0x06566, 0x0D4A0, 0x0EA50, 0x06E95, 0x05AD0, 0x02B60, 0x186E3, 0x092E0, 0x1C8D7, 0x0C950,
	0x0D4A0, 0x1D8A6, 0x0B550, 0x056A0, 0x1A5B4, 0x025D0, 0x092D0, 0x0D2B2, 0x0A950, 0x0B557,
	0x06CA0, 0x0B550, 0x15355, 0x04DA0, 0x0A5B0, 0x14573, 0x052B0, 0x0A9A8, 0x0E950, 0x06AA0,
	0x0AEA6, 0x0AB50, 0x04B60, 0x0AAE4, 0x0A570, 0x05260, 0x0F263, 0x0D950, 0x05B57, 0x056A0,
	0x096D0, 0x04DD5, 0x04AD0, 0x0A4D0, 0x0D4D4, 0x0D250, 0x0D558, 0x0B540, 0x0B6A0, 0x195A6,
	0x095B0, 0x049B0, 0x0A974, 0x0A4B0, 0x0B27A, 0x06A50, 0x06D40, 0x0AF46, 0x0AB60, 0x09570,
	0x04AF5, 0x04970, 0x064B0, 0x074A3, 0x0EA50, 0x06B58, 0x055C0, 0x0AB60, 0x096D5, 0x092E0,
	0x0C960, 0x0D954, 0x0D4A0, 0x0DA50, 0x07552, 0x056A0, 0x0ABB7, 0x025D0, 0x092D0, 0x0CAB5,
	0x0A950, 0x0B4A0, 0x0BAA4, 0x0AD50, 0x055D9, 0x04BA0, 0x0A5B0, 0x15176, 0x052B0, 0x0A930,
	0x07954, 0x06AA0, 0x0AD50, 0x05B52, 0x04B60, 0x0A6E6, 0x0A4E0, 0x0D260, 0x0EA65, 0x0D530,
	0x05AA0, 0x076A3, 0x096D0, 0x04BD7, 0x04AD0, 0x0A4D0, 0x1D0B6, 0x0D250, 0x0D520, 0x0DD45,
	0x0B5A0, 0x056D0, 0x055B2, 0x049B0, 0x0A577, 0x0A4B0, 0x0AA50, 0x1B255, 0x06D20, 0x0ADA0,
	0x14B63, 0x09370, 0x049F8, 0x04970, 0x064B0, 0x168A6, 0x0EA50, 0x06B20, 0x1A6C4, 0x0AAE0,
	0x092E0, 0x0D2E3, 0x0C960, 0x0D557, 0x0D4A0, 0x0DA50, 0x05D55, 0x056A0, 0x0A6D0, 0x055D4,
	0x052D0, 0x0A9B8, 0x0A950, 0x0B4A0, 0x0B6A6, 0x0AD50, 0x055A0, 0x0ABA4, 0x0A5B0, 0x052B0,
	0x0B273, 0x06930, 0x07337, 0x06AA0, 0x0AD50, 0x14B55, 0x04B60, 0x0A570, 0x054E4, 0x0D260,
	0x0E968, 0x0D520, 0x0DAA0, 0x16AA6, 0x056D0, 0x04AE0, 0x0A9D4, 0x0A4D0, 0x0D150, 0x0F252,
};

void y_to_n(int year, int month, int day);
int n_leapyear_month_days(int year);			//1.判断该年是否为闰年 2.若为闰年，返回闰月天数；若为平年，返回0
int n_leapyear_month(int year);					//若为闰年，返回闰月月份；若为平年，返回0
int n_year_month_days(int year, int month);		//农历某年某月的天数
int n_year_days(int year);						//农历该年总天数
int y_year_month_days(int year, int month);		//阳历某年某月的天数
int all_days(int year, int month, int day);		//计算从当天到1900年1月31日的天数
int main()
{
	int year, month, day;
	char choose = 'y';
	while (choose == 'y')
	{
		printf("请输入某日的阳历，我们将为你打印出阴历（eg：2018.6.8）\n阳历：");
		scanf("%d.%d.%d", &year, &month, &day);
		if (year < 1900 || year>2099 || month > 12 || month < 1 || day < 1 || day>31)
		{
			printf("请输入1900.1.31--2099.12.30之间的日期\n");
			continue;
		}
		y_to_n(year, month, day);
		printf("continue? y/n\n");
		getchar();
		choose = getchar();
	}
	getchar();
	return 0;
}

void y_to_n(int year, int month, int day)
{
	int n_year, n_month, n_day;
	int i, j;
	int AllDays;
	int leap= n_leapyear_month(year);  //闰月份数
	int isleap=0;
	int t;           //存放该年每月天数
	char N_Day[31][8] = {
		"*","初一","初二","初三","初四","初五",
		"初六","初七","初八","初九","初十",
		"十一","十二","十三","十四","十五",
		"十六","十七","十八","十九","二十",
		"廿一","廿二","廿三","廿四","廿五",
		"廿六","廿七","廿八","廿九","三十" };
	char N_Month[13][6] = { "*","正","二","三","四","五","六","七","八","九","十","十一","腊" };
	AllDays = all_days(year, month, day);

	for (i = 1900; AllDays>n_year_days(i); i++)
	{
		AllDays = AllDays - n_year_days(i);
	}
	n_year = i;

	for (j = 1; j<13; j++)
	{		
		if (leap>0 && i == (leap + 1) && !isleap)	//闰月
		{
			j--;
			isleap = 1;
			t = n_leapyear_month_days( n_year);
		}
		else										//非闰月
		{
			t = n_year_month_days(n_year, j);
		}

		if (isleap && j == (leap + 1))				//若闰月已过，检验恢复原值
		{
			isleap = 0;
		}
		if (AllDays < t)
			break;
		AllDays -= t;
	}
	n_month = j;
	n_day = AllDays + 1;
	printf("农历：%d年%s月%s\n", n_year, N_Month[n_month], N_Day[n_day]);
}
//1.判断该年是否为闰年 2.若为闰年，返回闰月天数；若为平年，返回0
int n_leapyear_month_days(int year)
{
	if (LunarInfo[year - 1900] & 0xf)
	{
		if ((LunarInfo[year - 1900] & 0x10000) == 0)		//闰月天数
		{
			return 29;
		}
		else
		{
			return 30;
		}
	}
	else
	{
		return (0);
	}
}
//若为闰年，返回闰月月份；若为平年，返回0
int n_leapyear_month(int year)
{
	return (LunarInfo[year - 1900] & 0xf);
}
//农历某年某月的天数
int n_year_month_days(int year, int month)
{
	int days;
	if ((LunarInfo[year - 1900] & (0x10000 >> month)) == 0)
	{
		days = 29;
	}
	else
	{
		days = 30;
	}
	return days;
}
//农历该年总天数
int n_year_days(int year)
{
	int nyear_days = 0;
	int i;
	for (i = 1; i < 13; i++)
	{
		nyear_days += n_year_month_days(year, i);
	}
	nyear_days += n_leapyear_month_days(year);
	return nyear_days;
}
//某年某月的天数
int y_year_month_days(int year, int month)
{
	int days;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: days = 31;  break;
	case 4:
	case 6:
	case 9:
	case 11:  days = 30;  break;
	case 2:
		if (n_leapyear_month_days(year) != 0)
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
		break;
	}
	return days;
}
//计算从当天到1900年1月31日的天数
int all_days(int year, int month, int day)
{
	int i;
	int Alldays = 0;			//从当天到1900年1月31日的天数
	for (i = 1; i < month; i++)
	{
		Alldays += y_year_month_days(year, i);
	}
	Alldays = Alldays + (year - 1900) * 365 + (year - 1900) / 4 + day - 31;
	if (((year%4 == 0 && year % 100 != 0) || (year %400)==0) && month != 12 && day != 31)
		Alldays -= 1;
	return Alldays;
}