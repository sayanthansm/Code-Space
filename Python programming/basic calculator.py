def add(a,b):
    return a+b
def sub(a,b):
    return a-b
def multi(a,b):
    return a*b
def div(a,b):
    if b==0:
        print("Division  cant be done")
    else:
        return a/b
def mod(a,b):
    return a%b
print("Enter two numbers too calculate")
a=int(input("Enter num1 "))
b=int(input("Enter num2 "))
print("1.Addition")
print("2.Subtraction")
print("3.Multiplication")
print("4.Division")
print("5.Modulus")
choice=int(input("Enter the operation to be done:"))
if choice==1:
    print("Addition of",a,"and",b,"is",add(a,b))
if choice==2:
    print("Subtraction of",a,"and",b,"is",sub(a,b))
if choice==3:
    print("Multiplication of",a,"and ",b,"is",multi(a,b))
if choice==4:
    print("Division of",a,"and",b,"is",div(a,b))
if choice==5:
    print("Modulus of",a,"and",b,"is",mod(a,b))