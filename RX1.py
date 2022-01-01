import sys
import os

args = sys.argv[1]

print("RX1 build tool")
print(args)

if str(args).lower() == "build_messages":
    print("generating c++ messages")
    os.system("cd /Tools")
    os.system("python ./generateCode.py")

    print("generating telemetry messages")
    os.system("cd ../Groundstation/Backend")
    os.system("python ./generateGSCode.py")

    print("done!")
elif str(args).lower() == "--h":
    print("Commands:")
    print("build_messages : builds c++ messages and telemetry code, ran after modifying messages")
else:
    print("unrecognized command")
    print("use --h for help")
