import psycopg2
conn=psycopg2.connect(database="finance01",user="x",password="x",host="110.41.115.206",port=8000)
cursor=conn.cursor()
sql="create table weapon(weapon_id int primary key,weapon_type varchar,num_cn int,num_usa int)"
cursor.execute(sql)
conn.commit()
print("table weapon is created by python successfully")
conn.close