#server
import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#using local ip(127.0.0.1) and a random port for example 124
s.bind(("localhost",124))
s.listen(1)
print("server listening...")
con,ad=s.accept()
print("client addr is ",ad)
data=con.recv(1024)
print("client: "+data.decode())
data2=con.send(b"hi bro this is server")
con.close()
