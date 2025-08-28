import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('localhost',124))
s.listen(1)
print("Server in listening mode...")
con,adr=s.accept()
print("connected by",adr)
while True:
    b=con.recv(1024).decode()
    if not b:
        break
    print("Client: ",b)
    if b.lower()=='quit':
        print("Terminating..")
        break
    reply=input("server: ")
    con.send(reply.encode())
con.close()
## HERE WE ARE STARTING A CONVERSATION WHERE U CAN SEND MESSAGES AND QUIT IF 'quit' IS GIVEN.
