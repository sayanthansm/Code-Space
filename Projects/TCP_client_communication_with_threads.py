
import socket


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 124))

while True:
    msg = input("Client: ")
    client.send(msg.encode())
    if msg.lower() == "quit":
        print("Disconnected from server.")
        break
    try:
        reply = client.recv(1024).decode()
        print("Server:", reply)
    except:
        print("Connection closed by server.")
        break

client.close()

