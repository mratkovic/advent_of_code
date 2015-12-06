import md5
import sys

def verbose_usage_and_exit():
    """ Prints usage and exits. """
    sys.stderr.write('Usage:\n')
    sys.stderr.write('\tpython <script_name> <key> <prefix>\n'.format(sys.argv[0]))
    exit(0)

def main(key, prefix):
    for i in range(10000000):
        new_key = key + str(i)
        digest = md5.new(new_key).hexdigest()

        if digest.startswith(prefix):
            print(i); break


if __name__ == "__main__":
    if len(sys.argv) != 3:
        verbose_usage_and_exit()
    main(sys.argv[1], sys.argv[2])
