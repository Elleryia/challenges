import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    # ignore test if it is an empty line
    # 'test' represents the test case, do something with it
    if not test in ['\n', '\r\n']:
        test = test.rstrip('\r\n')
        fields = list(map(int, test.split()))
        for n in range(1, fields[2] + 1):
            if(n % fields[0] == 0):
                print('F', end="")
                if(n %  fields[1] == 0):
                    print('B', end=" ")
                else:
                    print(end =" ")
            elif(n % fields[1] == 0):
                print('B', end=" ")
            else:
                print(n, end=" ")
        print()
test_cases.close()