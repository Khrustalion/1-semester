import  hashlib

string = b"DM Fall 2023 HW3"
h = bin(int(hashlib.sha256(string).hexdigest(), 16))[2:]
for _ in range(256 - len(h)):
    h = '0' + h
d = 0
print("h:", h)
for i in range(0, 255, 32):
    d ^= int(h[i:i+32], 2)
print("d:", bin(d)[2:])
w = d ^ int("24d03294", 16)
print("w:", bin(w)[2:])
