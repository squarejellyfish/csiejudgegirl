import os

files = os.listdir()

for file in files:
    if (os.path.isdir(file)):
        os.chdir(file)
        name = os.listdir()[0]
        os.rename(name, name[1:])
        os.chdir('..')
