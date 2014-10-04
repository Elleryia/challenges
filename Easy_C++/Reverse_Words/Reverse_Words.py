import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    # ignore test if it is an empty line
    # 'test' represents the test case, do something with it
    if not test in ['\n', '\r\n']:
        test = test.rstrip('\r\n')
        fields = test.split()
        for x in range(len(fields) - 1, -1, -1):
            if x == 0:
                sys.stdout.write(fields[x] + ' ')
            else:
                #print fields[x]
                sys.stdout.write(fields[x] + ' ')
        sys.stdout.write('\n')
test_cases.close()