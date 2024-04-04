import itertools 

def f(a, b, c):
    _1 = a & b
    _2 = _1 & c
    _3 = not(_1 | c)
    _4 = not(_2 | _3)
    _5 = a & _4
    _6 = a | b
    _7 = not(b & _4)
    _8 = not(_6 & _7)

    return _5, _8
print("a b c | f1 f2")
print("------|------")

for a, b, c in itertools.product([False, True], repeat=3):
    f1, f2 = f(a, b, c)
    print(int(a), int(b), int(c), "|", int(f1), int(f2))

