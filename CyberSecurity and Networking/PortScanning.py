#Scan ports in local machine in the range of starting port to ending port
import random
import socket
def port_Scan(host,start,end):
    for port in range(start,end+1):
        s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        s.settimeout(0.3)
        try:
            s.connect((host,port))
            print("O")
        except:
            print("C")
        finally:
            s.close()
port_Scan("127.0.0.1",10,40)
