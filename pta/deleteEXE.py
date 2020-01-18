import os

import glob
def del_files(path):
    for infile in glob.glob(os.path.join(path, '*.cpp.exe')):
        os.remove(infile)
        print(infile,'delete ok')
# test
if __name__ == "__main__":
    path = os.getcwd()
    print(path)
    del_files(path)