import os, sys, subprocess
from pathlib import Path

#Ensuring the existence of input and output directories
def dirEnsure():

    Path("src/datas/inputs").mkdir(parents = True, exist_ok = True)
    Path("src/datas/outputs").mkdir(parents = True, exist_ok = True)
    
#run automation
def main():

    if len(sys.argv) < 2:
        print("\n\tUse: python3 run.py <Your-Archive-Name.pgm>")
        sys.exit(1)

    dirEnsure()

    file = sys.argv[1]

    if not os.path.exists(f"src/datas/inputs/{file}"):
        print(f"Archive '{file}' does not exist in this directory")
        sys.exit(2)

    os.system("make")
    subprocess.run(["./lbp", file])

    output = f"{os.path.splitext(file)[0]}-lbp.pgm"                                                                         #removing extension .pgm
    if os.path.exists(f"src/datas/outputs/{output}"): subprocess.run(["xdg-open", f"src/datas/outputs/{output}"])
    else: print(f"Output not found. Expected: {output}")

if __name__ == "__main__":
    main()