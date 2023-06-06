import hashlib
import random
import string

def generate_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for _ in range(length))
    return password


def hash_password(password):
    md5_hash = hashlib.md5()
    md5_hash.update(password.encode('utf-8'))
    return md5_hash.hexdigest()


password_file = []
for _ in range(5):
    password = generate_password(10)
    password_file.append(password)

print("Password File (Original):", password_file)


hashed_password_file = []
for password in password_file:
    hashed_password = hash_password(password)
    hashed_password_file.append(hashed_password)

print("Password File (Hashed):", hashed_password_file)


salt_file = []
for _ in range(5):
    salt = generate_password(5)
    salt_file.append(salt)

print("Salt File:", salt_file)


salted_hashed_password_file = []
for i in range(len(password_file)):
    salted_password = salt_file[i] + password_file[i]
    salted_hashed_password = hash_password(salted_password)
    salted_hashed_password_file.append(salted_hashed_password)

print("Password File (Salted and Hashed):", salted_hashed_password_file)
