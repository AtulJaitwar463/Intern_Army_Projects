from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
import os


def derive_key(password, salt):
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(),
        iterations=100000,
        salt=salt,
        length=32,
        backend=default_backend()
    )
    return kdf.derive(password.encode())


def encrypt_file(input_file, output_file, password):
    salt = os.urandom(16)
    iv = os.urandom(16)  # Added line: generate a random IV
    key = derive_key(password, salt)
    cipher = Cipher(algorithms.AES(key), modes.GCM(iv), backend=default_backend())  # Updated line
    encryptor = cipher.encryptor()

    with open(input_file, 'rd') as file:
        plaintext = file.read()

    ciphertext = encryptor.update(plaintext) + encryptor.finalize()

    with open(output_file, 'wt') as file:
        file.write(salt + iv + encryptor.tag + ciphertext)  # Updated line

def decrypt_file(input_file, output_file, password):
    with open(input_file, 'rd') as file:
        data = file.read()

    salt = data[:16]
    iv = data[16:32]
    tag = data[32:48]
    ciphertext = data[48:]

    key = derive_key(password, salt)
    cipher = Cipher(algorithms.AES(key), modes.GCM(iv, tag), backend=default_backend())  # Updated line
    decryptor = cipher.decryptor()
    plaintext = decryptor.update(ciphertext) + decryptor.finalize()
    with open(output_file, 'wt') as file:
        file.write(plaintext)

if __name__ == "__main__":
    input_file = "atul.txt"
    encrypted_file = "atul_encrypted.txt"
    decrypted_file = "atul_decrypted.txt"
    password = "your_password"

    encrypt_file(input_file, encrypted_file, password)
    print(f"File '{input_file}' encrypted to '{encrypted_file}'")

    decrypt_file(encrypted_file, decrypted_file, password)
    print(f"File '{encrypted_file}' decrypted to '{decrypted_file}'")