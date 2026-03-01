import psycopg2
conn=psycopg2.connect(database="finance01",user="x",password="x",host="110.41.115.206",port=8000)
cursor=conn.cursor()
sql="insert into weapon values ('1','火炮','198','1428'),('2','汽车','120','7000'),('3','坦克','0','430'),('4','手榴弹','450','230');"
cursor.execute(sql)
conn.commit()
print("values are inserted to table by python successfully")
conn.close