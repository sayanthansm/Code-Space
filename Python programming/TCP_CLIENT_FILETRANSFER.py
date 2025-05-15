import socket 
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.connect(('localhost',123))
filname='name.txt'
s.send(filname.encode())
with open(filname,"rb") as g:
    byte=g.read(1024)
    while byte:
        s.send(byte)
        g.read(1024)
s.close()
