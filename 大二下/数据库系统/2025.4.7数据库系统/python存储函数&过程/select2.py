import psycopg2

conn=psycopg2.connect(database="finance01",user="x",password="x",host="110.41.115.206",port=8000)
cursor=conn.cursor()
sql="select * from compare_weapons();"
cursor.execute(sql)
conn.commit()
results=cursor.fetchall()
print("武器类型\t中方数量\t美方数量\t数量差")
for result in results:
    print(f"{result[0]}\t{result[1]}\t\t{result[2]}\t\t{result[3]}")
conn.close