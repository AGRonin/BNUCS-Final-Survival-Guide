import psycopg2

conn=psycopg2.connect(database="finance01",user="x",password="x",host="110.41.115.206",port=8000)
cursor=conn.cursor()
sql="select add_num_cn(%s,%s);"
cursor.execute(sql,(2,1))
conn.commit()
result=cursor.fetchall()
print("更新后的num_cn值为", result[0][0])
conn.close