import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(('localhost',124))
while True:
    f=input("client: ")
    s.send(f.encode())
    if f.lower()=='quit':
        print("connection terminating!")
        break
    p=s.recv(1024).decode()
    print("Server: ",p)
s.close()
