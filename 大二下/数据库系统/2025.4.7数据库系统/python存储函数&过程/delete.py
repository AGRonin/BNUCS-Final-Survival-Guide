import psycopg2

conn=psycopg2.connect(database="finance01",user="x",password="x",host="110.41.115.206",port=8000)
cursor=conn.cursor()
sql="DELETE FROM weapon;"
cursor.execute(sql)
conn.commit()
print("weapon表的所有记录已删除")
conn.close()