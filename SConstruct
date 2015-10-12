env = Environment(
    CC='g++',
    CCFLAGS='-g -O2 -static -std=gnu++0x',
    CPPPATH=['src']
)

source = ['src/fenwick.cpp']
program = env.Program(target='bin/fenwick', source=source);

env.Append(LIBS=['gmock', 'pthread'])
source = ['test/fenwick_tree_test.cpp']
test = env.Program(target='bin/run_all_tests', source=source);
