import sys
import os, shutil

path = os.getcwd()

print(path)

args = sys.argv[1]

print("RX1 build tool")
print(args)

if str(args).lower() == "build_messages":
    print("generating c++ messages")
    os.chdir(path + "\Tools")
    os.system("python "+ path +"\Tools\generateCode.py")

    print("generating telemetry messages")
    os.chdir(path + "\Groundstation\Backend")
    os.system("python " + path + "\Groundstation\Backend\generateGSCode.py")

    print("done!")
elif str(args).lower() == "--h":
    print("Commands:")
    print("build_messages : builds c++ messages and telemetry code, ran after modifying messages")
    print("clear_logs: deletes all telemetry stored logs")

elif str(args).lower() == "clear_logs":
    print("Are you sure? This will erase all stored telemetry logs and cannot be undone!")
    inp = input("(N/y)")
    if(inp.lower() == "n" or inp.lower() == ""):
        pass
    elif(inp.lower() == "y"):
        print("If you say so")
        for filename in os.listdir(path + "\Groundstation\Backend\Logs"):
            file_path = os.path.join(path + "\Groundstation\Backend\Logs", filename)
            if(filename.endswith(".csv")):
                try:
                    if os.path.isfile(file_path) or os.path.islink(file_path):
                        os.unlink(file_path)
                except Exception as e:
                    print('Failed to delete %s. Reason: %s' % (file_path, e))
        print("Done")
elif str(args).lower() == "run_gs":
    os.chdir(path + "\Groundstation\Backend")
    os.system("python " + path + r"\Groundstation\Backend\runProcessing.py")
    try:
        os.system("python " + path + r"\Groundstation\Backend\runProcessing.py")
    except KeyboardInterrupt:
        pass
else:
    print("unrecognized command")
    print("use --h for help")    
print("Complete, exiting...")