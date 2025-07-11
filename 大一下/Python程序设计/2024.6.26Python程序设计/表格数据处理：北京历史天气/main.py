import pandas as pd
import matplotlib.pyplot as plt
plt.style.use('fivethirtyeight')
plt.rcParams['font.family']='STFangsong'
whether_form = pd.read_csv('Beijing2.csv',index_col=0,encoding='gbk')
year=[]
month=[]
day=[]
year_month=[]
for i in whether_form.index:
    y,m,d=str(i).split('-')
    ym=y+'-'+m
    y=int(y)
    m=int(m)
    d=int(d)
    year.append(y)
    month.append(m)
    day.append(d)
    year_month.append(ym)
whether_form['year']=year
whether_form['month']=month
whether_form['day']=day
whether_form['year-month']=year_month
temper_high_digit=[]
for i in whether_form['temper_high']:
    temper_high_digit.append(int(i))
whether_form['temper_high_digit']=temper_high_digit
average_highest_year_month_form=whether_form[['year-month','temper_high_digit']]
group_year_month=average_highest_year_month_form.groupby('year-month')
group_year_month_mean=group_year_month.mean()
group_year_month_mean.plot()
plt.title('2020-2024年月平均最高气温变化图')
plt.show()

weather_year_form=whether_form[['year','weather']]
group_year=weather_year_form.groupby('year')
group_year_list=[]
for i in range(2020,2025):
    group_year_list.append(group_year.get_group(i))
    group_year_weather_list=[0,0,0,0,0,0,0]#依次为：晴、雨、多云、阴、雪、霾、沙尘
    for j in group_year_list[i-2020]['weather']:
        if '晴' in j:
            group_year_weather_list[0]+=1
        if '雨' in j:
            group_year_weather_list[1] += 1
        if '多云' in j:
            group_year_weather_list[2]+=1
        if '阴' in j:
            group_year_weather_list[3]+=1
        if '雪' in j:
            group_year_weather_list[4]+=1
        if '霾' in j:
            group_year_weather_list[5]+=1
        if '沙' in j or '尘' in j:
            group_year_weather_list[6]+=1
    print(f"""{i}年天气情况如下：
晴天\t\t{group_year_weather_list[0]}次
雨天\t\t{group_year_weather_list[1]}次
多云\t\t{group_year_weather_list[2]}次
阴天\t\t{group_year_weather_list[3]}次
雪天\t\t{group_year_weather_list[4]}次
雾霾\t\t{group_year_weather_list[5]}次
沙尘\t\t{group_year_weather_list[6]}次""")
    plt.pie(group_year_weather_list,labels=['晴','雨','多云','阴','雪','霾','沙尘'],pctdistance=5)
    plt.title(f'{i}年天气情况')
    plt.show()