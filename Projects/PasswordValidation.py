import re
def password_validation(password):
    if len(password)<8:
        print("Password length doesnt match..")
        return
    if not  re.search(r"[a-z]",password):
        print("Weak password..Must include atleast one Uppercase letter")
        return
    if not re.search(r"[A-Z]",password):
        print("Weak pasword.. Must include atleast one Lowercase letter")
        return
    if not re.search(r"[0-9]",password):
        print("Weak password..Must include atleast one digit")
        return
    if not re.search(r"[^a-zA-Z0-9]",password):
        print("Weak password..Must include atleast one special character")
        return
    if  re.search(r"(.)\1{2,}",password):
        print("Weak password..Contains repeating values")
        return
    print("Strong password")
password_validation("sAyantna#*8")
