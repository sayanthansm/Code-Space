import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('localhost',123))
s.listen(1)
print("Server ready~~")
conn,add=s.accept()
filename=conn.recv(1024).decode()
print("REceivnin file",filename)
with open("received_"+filename,"wb") as f:
    while True:
        data=conn.recv(1024)
        if not data:
            break
        f.write(data)
print("completed")
conn.close()
s.close()
