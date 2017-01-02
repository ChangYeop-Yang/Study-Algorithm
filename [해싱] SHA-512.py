import hashlib

mString = str(input()).encode('utf-8')

print(hashlib.sha512(mString).hexdigest())
