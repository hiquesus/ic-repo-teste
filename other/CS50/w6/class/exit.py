import sys

if len(sys.argv) != 2:
    print("command-line arg must be 2")
    sys.exit(1)

print("hello,", sys.argv[1])
sys.exit(0)