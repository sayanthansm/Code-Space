import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(("localhost",124))
s.send(b"hello")
data=s.recv(1024)
print("server is saying \n"+data.decode())
s.close()
