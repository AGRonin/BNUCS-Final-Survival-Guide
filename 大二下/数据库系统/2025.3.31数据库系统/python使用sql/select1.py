import psycopg2
conn=psycopg2.connect(database="finance01",user="x",password="x",host="110.41.115.206",port=8000)
cursor=conn.cursor()
sql="select * from weapon where weapon_id=1;"
cursor.execute(sql)
print("there is/are",cursor.rowcount,"data(s) that weapon_id==1")
result=cursor.fetchall()
print(result)
print("here are all the data that weapon_id==1")
conn.close