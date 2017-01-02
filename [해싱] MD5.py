import hashlib

mString = str(input()).encode('utf-8')

print(hashlib.md5(mString).hexdigest())
