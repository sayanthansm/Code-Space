import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(('localhost',123))
while True:
    name=input("Enter name: ")
    mail=input("Enter mail: ")
    message=input("Enter message: ")
    
    if not message or message.lower()=='quit':
        print("exiting..")
        s.send(b"quit")
        break
    dat=f"{name},{mail},{message}"
    s.send(dat.encode())
    print("Server:",s.recv(1024).decode())
s.close()
