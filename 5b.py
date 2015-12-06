import sys
import re

def verbose_usage_and_exit():
    """ Prints usage and exits. """
    sys.stderr.write('Usage:\n')
    sys.stderr.write('\tpython <script_name> <in_file>\n'.format(sys.argv[0]))
    exit(0)


bad = ['ab', 'cd', 'pq', 'xy']

def isGood(line):
    isGood1 = re.match(r".*(\w{2}).*\1.*", line)
    isGood2 = re.match(r".*(\w).\1.*", line)

    if isGood1 and isGood2:
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
