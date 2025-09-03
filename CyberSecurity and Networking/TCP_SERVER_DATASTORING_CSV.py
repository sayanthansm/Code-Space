import socket
import threading
def handleclient(con,addr):
    print(f"Connected to {addr}..")
    try:
        rec=con.recv(1024).decode()
        name,mail,msg=rec.split(',')
        with open("data.csv","a") as f:
            f.write(f"Name: {name} \n Email:{mail} \n Message:{msg}\n")
        con.send("Data stored successfully..".encode())
    except:
        con.send("error sending data".encode())
    con.close()
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(('localhost',123))
s.listen(5)
print("Server binding...")
while True:
    con,adr=s.accept()
    t=threading.Thread(target=handleclient,args=(con,adr))
    t.start()
