#!/usr/bin/env python3

# Run 'python3 testing_tool.py -h' for information on usage.

import argparse
import subprocess
import sys
import traceback

parser = argparse.ArgumentParser(description="""
  Testing tool for the Factor Queries problem

  You can compile and run your solution as follows.
  - Replace N with the hidden number you want to test.
  - You may have to replace 'python3' by just 'python'.
  - On Windows, you may have to to replace '/' by '\\'.

  C++:
    g++ solution.cpp
    python3 testing_tool.py -n N ./a.out

  Java:
    javac solution.java
    python3 testing_tool.py -n N java solution

  Python 3:
    python3 testing_tool.py -n N python3 ./solution.py


  The tool is provided as-is, and you should feel free to make
  whatever alterations or augmentations you like to it.

  The tool attempts to detect and report common errors, but it is not an
  exhaustive test. It is not guaranteed that a program that passes this testing
  tool will be accepted.""", formatter_class=argparse.RawDescriptionHelpFormatter)

parser.add_argument('-f', dest='inputfile', metavar='inputfile', default=None, type=argparse.FileType('r'),
                    help='custom input file containing the hidden number (defaults to sample 1)')
parser.add_argument('-n', dest='x', metavar='N', type=int,
                    help='use N as hidden number; this overwrites the -f flag')
parser.add_argument('-q', action='store_true', dest='quiet', default=False,
                    help='only output the number of queries required')
parser.add_argument('program', nargs='+', help='your solution, as described above')

args = parser.parse_args()

def write(p, line):
    assert p.poll() is None, 'Program terminated early'
    if not args.quiet: print('Write: {}'.format(line), flush=True)
    p.stdin.write('{}\n'.format(line))
    p.stdin.flush()

def read(p):
    assert p.poll() is None, 'Program terminated early'
    line = p.stdout.readline().strip()
    assert line != '', 'Read empty line or closed output pipe'
    if not args.quiet: print('Read: %s' % line, flush=True)
    return line

if args.x is not None:
    x = args.x
elif args.inputfile is not None:
    # Read the input file
    with args.inputfile as f:
        x = int(f.readline())
else:
    x = 6

def evaluate(y):
    if x == y: return 'equal'
    if y%x == 0: return 'multiple'
    if x%y == 0: return 'factor'
    return 'other'

with subprocess.Popen(" ".join(args.program), shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE,
                          universal_newlines=True) as p:
    try:
        queries = 0
        while True:
            y = int(read(p))
            queries += 1

            assert queries <= 50, 'Used too many queries'
            
            ans = evaluate(y)
            write(p, ans)

            if ans == 'equal':
                assert p.stdout.readline() == '', 'Printed extra data after finding solution'
                assert p.wait() == 0, 'Did not exit cleanly after finishing'
                break
    except:
        traceback.print_exc()
        p.kill()
    finally:
        sys.stdout.flush()
        sys.stderr.flush()
        if args.quiet:
            print(queries)
        else:
            print()
            print('Number of guesses:', queries)
            print('Exit code:', p.wait())
