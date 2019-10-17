import subprocess

proc = subprocess.run("./sol", stdin=open('in', 'r'))
print(proc.stdout)

