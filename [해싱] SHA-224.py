import hashlib

mString = str(input()).encode('utf-8')

print(hashlib.sha224(mString).hexdigest())
