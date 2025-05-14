import threading
import socket
def handle_client(con,add):
    print(f"New connection established {con},{add}")
    while True:
        try:
            msg=s.recv(1024).decode()
            if msg.lower()=='quit':
                print("Disconnecting..")
                break
            print(f"{add}|{msg}")
            reply=input("Send: ")
            s.send(reply.encode())
        except:
            print(f"Disconnected with {add}")
            break
        s.close()
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('localhost',124))
s.listen(4)
print("Server listening..")
while True:
    con,adr=s.accept()
    t=threading.Thread(target=handle_client,args=(con,adr))
    t.start()
        
