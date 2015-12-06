import md5
import sys

def verbose_usage_and_exit():
    """ Prints usage and exits. """
    sys.stderr.write('Usage:\n')
    sys.stderr.write('\tpython <script_name> <in_file>\n'.format(sys.argv[0]))
    exit(0)


bad = ['ab', 'cd', 'pq', 'xy']

def isGood(line):
    isGood1 = len([1 for c in line if c in 'aeiou']) >= 3
    isGood2 = any(a == b for a, b in zip(line, line[1:]))
    isGood3 = not any(part in line for part in bad)

    if isGood1 and isGood2 and isGood3:
        return 1
    else:
        return 0




def main(path):
    cntr = 0

    with open(path, 'r') as fin:
        for line in fin:
            cntr += isGood(line)

    print(cntr)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        verbose_usage_and_exit()
    main(sys.argv[1])
