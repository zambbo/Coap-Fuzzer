import binascii
import os
import random


f = open("coap_url_corpus", "rb")

urls = f.read()
urls = urls.split(b"\r\n")

rand_byte = [b'\x00', b'\x01']

for url in urls:
    filename = binascii.hexlify(os.urandom(32)).decode()

    with open(os.path.join("corpus",filename) , "wb") as f:
        f.write(random.choice(rand_byte)+url)



    
