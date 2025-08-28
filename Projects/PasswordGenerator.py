import secrets 
import string
def password_generator(len=12):
    if len<8:
        raise ValueError("Must contain more than 8 values")
    password=[secrets.choice(string.ascii_lowercase),secrets.choice(string.ascii_uppercase),secrets.choice(string.digits),secrets.choice(string.punctuation),secrets.choice(string.hexdigits)]
    dictionary=string.ascii_letters+string.digits+string.punctuation
    password+=[secrets.choice(dictionary)for _ in range(len-5)]
    secrets.SystemRandom().shuffle(password)
    return ''.join(password)
print(password_generator(14))
